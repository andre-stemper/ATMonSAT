/*
 Copyright 2022 University of Luxembourg

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

/**
 * @author André Stemper (andre.stemper@uni.lu)
 */

#include <cstdint>
#include <stdio.h>
#include <stdarg.h>

#include "atmonsat.h"
#include "atmonsat_anomaly_detection.h"
#include "atmonsat_model.h"
#include "atmonsat_mahalanobis_precalculated_values.h"
#include "mahalanobis.h"
#include "islcc_interpolator.h"
#include "datapoint.h"
#include "datawindow.h"
#include "threshold.h"

#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/system_setup.h"
#include "tensorflow/lite/schema/schema_generated.h"

#ifndef PLACEBO

namespace atmonsat
{

    /* communication callbacks */
    ad_message_callback _message_callback = nullptr;
    ad_exception_callback _exception_callback = nullptr;
    ad_detection_callback _detection_callback = nullptr;
    ad_distance_callback _distance_callback = nullptr;

    /**
     * @brief send message to the message callback
     *
     * @param str
     */
    void do_callback_message(const char *str)
    {
        if (_message_callback != nullptr)
        {

            _message_callback(str);
        }
    }

    /**
     * @brief send message to the exception callback
     *
     * @param str
     */
    void do_callback_exception(const char *str)
    {
        if (_exception_callback != nullptr)
        {

            _exception_callback(str);
        }
    }

    /**
     * @brief forward detection to detection callback
     *
     * @param detection
     */
    void do_callback_detection(const bool detection)
    {
        if (_detection_callback != nullptr)
        {
            _detection_callback(detection);
        }
    }

    /**
     * @brief forward distance to distance callback
     *
     * @param distance
     */
    void do_callback_distance(const float distance)
    {
        if (_distance_callback != nullptr)
        {
            _distance_callback(distance);
        }
    }

    /**
     * @brief ErrorReporter for tf lite micro
     *
     */
    class AD_ErrorReporter : public tflite::ErrorReporter
    {
    public:
        ~AD_ErrorReporter() override {}
        int Report(const char *format, va_list args) override
        {
            char buffer[256];
            int nr = vsnprintf(buffer, 255, format, args);
            do_callback_exception(buffer);
            return nr;
        }

    private:
        TF_LITE_REMOVE_VIRTUAL_DELETE
    };

    /**
     * @brief tf lite micro error reporter
     *
     */
    tflite::ErrorReporter *error_reporter = nullptr;

    /**
     * @brief tf lite micro interpreter
     *
     */
    tflite::MicroInterpreter *interpreter = nullptr;

    /**
     * @brief tf lite micro model
     *
     */
    const tflite::Model *model = nullptr;

    /**
     * @brief tf lite micro model input
     *
     */
    TfLiteTensor *model_input = nullptr;

    /**
     * @brief tf lite micro model output
     *
     */
    TfLiteTensor *model_output = nullptr;

    /**
     * @brief memory arena for tf lite micro
     *
     */
    constexpr size_t kTensorArenaSize = ATMONSAT_TFLM_ARENA_SIZE;
    uint8_t tensor_arena[ATMONSAT_TFLM_ARENA_SIZE];

    /**
     * @brief Instance of threshold with hold-off
     *
     */
    Threshold<t_distance, t_hold_off> threshold;

    /**
     * @brief Mahalanobis: the instance for measuring distances
     *
     */
    Mahalanobis<2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT, t_distance> mahalanobis;

    /**
     * @brief SIPO for temperature data
     *
     */
    DataWindow<t_datapoint<t_data, ATMONSAT_DIMENSIONS_PER_DATAPOINT>, ATMONSAT_WINDOW_SIZE> sipo_temperatures;

    /**
     * @brief SIPO for ISLC data
     *
     */
    DataWindow<t_datapoint<t_iterations, ATMONSAT_DIMENSIONS_PER_DATAPOINT>, ATMONSAT_WINDOW_SIZE> sipo_islc;

    /**
     * @brief concatenated predictions
     *
     */
    t_datapoint<t_internal, 2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT> prediction;

    /**
     * @brief concatenated stored_prediction
     *
     */
    t_datapoint<t_internal, 2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT> stored_prediction;

    /**
     * @brief concatenated prediction error
     *
     */
    t_datapoint<t_internal, 2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT> prediction_error;

    /**
     * @brief IISLCC callback
     *        This is the inner loop of the IISLCC that performance an anlomaly detection on every datappoint+islc
     *
     * @param datapoint
     * @param islc
     * @param forced
     */
    void iislcc_callback(t_datapoint<t_data, ATMONSAT_DIMENSIONS_PER_DATAPOINT> datapoint,
                         t_datapoint<t_iterations, ATMONSAT_DIMENSIONS_PER_DATAPOINT> islc,
                         bool forced)
    {
        (void)forced;

        static t_datapoint<t_data, ATMONSAT_DIMENSIONS_PER_DATAPOINT> temp_temperature;
        static t_datapoint<t_iterations, ATMONSAT_DIMENSIONS_PER_DATAPOINT> temp_islc;

        sipo_temperatures.push(datapoint); /* push temperature datapoint into the temperatures SIPO */
        sipo_islc.push(islc);              /* push islc into the ISLC SIPO */

        /* flatten SIPO outputs into the model input tensor
            ordering row[0].dp[0..8], row[0].cnt[0..8], row[1].dp[0..8], row[1].cnt[0..8]
        */
#if ATMONSAT_WINDOW_ORDER == ATMONSAT_WINDOW_ORDER_ASCENDING
        unsigned int i, j, k;
#elif ATMONSAT_WINDOW_ORDER == ATMONSAT_WINDOW_ORDER_DESCENDING
        unsigned int i, k;
        int j;
#else
#error "Unknown window order"
#endif
        model_input = interpreter->input(0);

        /* quantize into tensor */
        if (model_input->type == kTfLiteInt8)
        {
            int8_t *input = interpreter->typed_input_tensor<int8_t>(0);
#if ATMONSAT_WINDOW_ORDER == ATMONSAT_WINDOW_ORDER_ASCENDING
            for (j = 0, k = 0; j < ATMONSAT_WINDOW_SIZE; ++j)
#elif ATMONSAT_WINDOW_ORDER == ATMONSAT_WINDOW_ORDER_DESCENDING
            for (j = ATMONSAT_WINDOW_SIZE - 1, k = 0; j >= 0; --j)
#else
#error "Unknown window order"
#endif
            {
#if ATMONSAT_INPUT_TENSOR_ORDER == ATMONSAT_INPUT_TENSOR_ORDER_TEMPERATURE_ISLC
                temp_temperature = sipo_temperatures.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<int8_t>(static_cast<t_internal>(temp_temperature.get(i)) / model_input->params.scale + model_input->params.zero_point);
                }
                temp_islc = sipo_islc.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<int8_t>(static_cast<t_internal>(temp_islc.get(i)) / model_input->params.scale + model_input->params.zero_point);
                }
#elif ATMONSAT_INPUT_TENSOR_ORDER == ATMONSAT_INPUT_TENSOR_ORDER_ISLC_TEMPERATURE
                temp_islc = sipo_islc.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<int8_t>(static_cast<t_internal>(temp_islc.get(i)) / model_input->params.scale + model_input->params.zero_point);
                }
                temp_temperature = sipo_temperatures.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<int8_t>(static_cast<t_internal>(temp_temperature.get(i)) / model_input->params.scale + model_input->params.zero_point);
                }
#else
#error "ATMONSAT_INPUT_TENSOR_ORDER has invalid value"
#endif
            }
        }
        else if (model_input->type == kTfLiteUInt8)
        {
            uint8_t *input = interpreter->typed_input_tensor<uint8_t>(0);
#if ATMONSAT_WINDOW_ORDER == ATMONSAT_WINDOW_ORDER_ASCENDING
            for (j = 0, k = 0; j < ATMONSAT_WINDOW_SIZE; ++j)
#elif ATMONSAT_WINDOW_ORDER == ATMONSAT_WINDOW_ORDER_DESCENDING
            for (j = ATMONSAT_WINDOW_SIZE - 1, k = 0; j >= 0; --j)
#else
#error "Unknown window order"
#endif
            {

#if ATMONSAT_INPUT_TENSOR_ORDER == ATMONSAT_INPUT_TENSOR_ORDER_TEMPERATURE_ISLC
                temp_temperature = sipo_temperatures.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<uint8_t>(static_cast<t_internal>(temp_temperature.get(i)) / model_input->params.scale + model_input->params.zero_point);
                }
                temp_islc = sipo_islc.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<uint8_t>(static_cast<t_internal>(temp_islc.get(i)) / model_input->params.scale + model_input->params.zero_point);
                }

#elif ATMONSAT_INPUT_TENSOR_ORDER == ATMONSAT_INPUT_TENSOR_ORDER_ISLC_TEMPERATURE
                temp_islc = sipo_islc.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<uint8_t>(static_cast<t_internal>(temp_islc.get(i)) / model_input->params.scale + model_input->params.zero_point);
                }
                temp_temperature = sipo_temperatures.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<uint8_t>(static_cast<t_internal>(temp_temperature.get(i)) / model_input->params.scale + model_input->params.zero_point);
                }
#else
#error "ATMONSAT_INPUT_TENSOR_ORDER has invalid value"
#endif
            }
        }
        else if (model_input->type == kTfLiteFloat32)
        {
            t_internal *input = interpreter->typed_input_tensor<t_internal>(0);
#if ATMONSAT_WINDOW_ORDER == ATMONSAT_WINDOW_ORDER_ASCENDING
            for (j = 0, k = 0; j < ATMONSAT_WINDOW_SIZE; ++j)
#elif ATMONSAT_WINDOW_ORDER == ATMONSAT_WINDOW_ORDER_DESCENDING
            for (j = ATMONSAT_WINDOW_SIZE - 1, k = 0; j >= 0; --j)
#else
#error "Unknown window order"
#endif
            {
#if ATMONSAT_INPUT_TENSOR_ORDER == ATMONSAT_INPUT_TENSOR_ORDER_TEMPERATURE_ISLC
                temp_temperature = sipo_temperatures.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<t_internal>(temp_temperature.get(i));
                }
                temp_islc = sipo_islc.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<t_internal>(temp_islc.get(i));
                }
#elif ATMONSAT_INPUT_TENSOR_ORDER == ATMONSAT_INPUT_TENSOR_ORDER_ISLC_TEMPERATURE
                temp_islc = sipo_islc.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<t_internal>(temp_islc.get(i));
                }
                temp_temperature = sipo_temperatures.get(j);
                for (i = 0; i < ATMONSAT_DIMENSIONS_PER_DATAPOINT; ++i)
                {
                    input[k++] = static_cast<t_internal>(temp_temperature.get(i));
                }
#else
#error "ATMONSAT_INPUT_TENSOR_ORDER has invalid value"
#endif
            }
        }
        else
        {
            do_callback_exception("Unsupported tensor type at model input.");
            return;
        }

        /* invoke tf lite micro inference */
        TfLiteStatus invoke_status = interpreter->Invoke();
        if (invoke_status != kTfLiteOk)
        {
            do_callback_exception("Failed to invoke TF Lite Micro interpreter.");
            return;
        }

        model_output = interpreter->output(0);

        /* de-quantize output into prediction */
        if (model_output->type == kTfLiteInt8)
        {
            for (i = 0; i < (2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT); ++i)
            {
                prediction.set(i, (model_output->data.int8[i] - model_output->params.zero_point) * model_output->params.scale);
            }
        }
        else if (model_output->type == kTfLiteUInt8)
        {
            for (i = 0; i < (2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT); ++i)
            {
                prediction.set(i, (model_output->data.uint8[i] - model_output->params.zero_point) * model_output->params.scale);
            }
        }
        else if (model_output->type == kTfLiteFloat32)
        {
            /* const */
            t_internal *output = interpreter->typed_output_tensor<t_internal>(0);

            for (i = 0; i < (2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT); ++i)
            {
                prediction.set(i, output[i]);
            }
        }
        else
        {
            do_callback_exception("Unsupported tensor type at model output.");
            return;
        }

        /* calculate error */
#if ATMONSAT_INPUT_TENSOR_ORDER == ATMONSAT_INPUT_TENSOR_ORDER_TEMPERATURE_ISLC
        prediction_error = stored_prediction - (datapoint.to<t_internal>() & islc.to<t_internal>()); /* prediction error */
#elif ATMONSAT_INPUT_TENSOR_ORDER == ATMONSAT_INPUT_TENSOR_ORDER_ISLC_TEMPERATURE
        prediction_error = stored_prediction - (islc.to<t_internal>() & datapoint.to<t_internal>()); /* prediction error */
#else
#error "ATMONSAT_INPUT_TENSOR_ORDER has invalid value"
#endif

        stored_prediction = prediction; /* update for next iteration */

        /* square of mahalanobis distance */
        t_distance md = mahalanobis.square_distance(prediction_error);
        threshold.input(md);

        /* report results */
#if 0
        error_reporter->Report("distance %f", md);
        error_reporter->Report("detection %d", threshold.decision());
#endif

        do_callback_distance(md);
        do_callback_detection(threshold.decision());
    }

    /**
     * @brief ISLCC interpolator
     */
    ISLCC_Interpolator<t_data,
                       t_iterations,
                       ATMONSAT_DIMENSIONS_PER_DATAPOINT,
                       ATMONSAT_ISLCC_WINDOW_SIZE>
        iislcc(iislcc_callback);

    /**
     * @brief setup the anomaly detection algorithm
     *
     * @return arc_t
     */

    arc_t atmonsat_anomaly_detection_setup(ad_message_callback message_callback,
                                           ad_exception_callback exception_callback,
                                           ad_detection_callback detection_callback,
                                           ad_distance_callback distance_callback)
    {
        TfLiteStatus status;

        /* callbacks for results */
        _message_callback = message_callback;
        _exception_callback = exception_callback;
        _detection_callback = detection_callback;
        _distance_callback = distance_callback;

        atmonsat_anomaly_detection_reset();

        /* initialize tensorflow lite micro */
        tflite::InitializeTarget();

        static AD_ErrorReporter ad_error_reporter;
        error_reporter = &ad_error_reporter;

        model = tflite::GetModel(atmonsat_model);
        if (model->version() != TFLITE_SCHEMA_VERSION)
        {
            error_reporter->Report("Model provided is schema version %d not equal "
                                   "to supported version %d.",
                                   model->version(), TFLITE_SCHEMA_VERSION);
            return ARC_SUCCESS;
        }

        static tflite::MicroMutableOpResolver<7> resolver;

        status = resolver.AddFullyConnected();
        if (status != kTfLiteOk)
        {
            do_callback_exception("AddFullyConnected failed.");
            return ARC_FAILED;
        }
        status = resolver.AddExpandDims();
        if (status != kTfLiteOk)
        {
            do_callback_exception("AddExpandDims failed.");
            return ARC_FAILED;
        }
        status = resolver.AddReshape();
        if (status != kTfLiteOk)
        {
            do_callback_exception("AddReshape failed.");
            return ARC_FAILED;
        }
        status = resolver.AddConv2D();
        if (status != kTfLiteOk)
        {
            do_callback_exception("AddConv2D failed.");
            return ARC_FAILED;
        }
        status = resolver.AddTanh();
        if (status != kTfLiteOk)
        {
            do_callback_exception("AddTanh failed.");
            return ARC_FAILED;
        }
        status = resolver.AddQuantize();
        if (status != kTfLiteOk)
        {
            do_callback_exception("AddQuantize failed.");
            return ARC_FAILED;
        }
        status = resolver.AddDequantize();
        if (status != kTfLiteOk)
        {
            do_callback_exception("AddDequantize failed.");
            return ARC_FAILED;
        }

        static tflite::MicroInterpreter static_interpreter(
            model,
            resolver,
            tensor_arena,
            kTensorArenaSize);

        interpreter = &static_interpreter;

        status = interpreter->AllocateTensors();
        if (status != kTfLiteOk)
        {
            do_callback_exception("AllocateTensors() failed");
            return ARC_FAILED;
        }

        model_input = interpreter->input(0);
        model_output = interpreter->output(0);

        /* check model input / output */
        if ((model_input->dims->size != 3) ||
            (model_input->dims->data[0] != 1) ||
            (model_input->dims->data[1] != ATMONSAT_WINDOW_SIZE) ||
            (model_input->dims->data[2] != (2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT)) ||
            ((model_input->type != kTfLiteUInt8) && (model_input->type != kTfLiteInt8) && (model_input->type != kTfLiteFloat32)))
        {
            do_callback_exception("Unsupported model input tensor parameters.");
            return ARC_FAILED;
        }
        if ((model_output->dims->size != 2) ||
            (model_output->dims->data[0] != 1) ||
            (model_output->dims->data[1] != (2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT)) ||
            ((model_output->type != kTfLiteUInt8) && (model_output->type != kTfLiteInt8) && (model_input->type != kTfLiteFloat32)))
        {
            do_callback_exception("Unsupported model output tensor parameters.");
            return ARC_FAILED;
        }

        return ARC_SUCCESS;
    }

    /**
     * @brief reset anomaly detection
     *
     * @return arc_t
     */
    arc_t atmonsat_anomaly_detection_reset(void)
    {
        mahalanobis_setup_precalculated_values(mahalanobis);
        sipo_temperatures.reset();
        sipo_islc.reset();
        prediction.zero();
        stored_prediction.zero();
        prediction_error.zero();
        iislcc.reset();
        threshold.reset();

        return ARC_SUCCESS;
    }

    /**
     * @brief run one iteration of the anomaly detection algorithm
     *
     * @return arc_t
     */
    arc_t atmonsat_anomaly_detection_run_once(t_datapoint<t_data, ATMONSAT_DIMENSIONS_PER_DATAPOINT> &datapoint)
    {
        iislcc.push_datapoint(datapoint);
        return ARC_SUCCESS;
    }
}
#endif
