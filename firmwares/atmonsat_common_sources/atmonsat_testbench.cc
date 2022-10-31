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

#include <iostream>
#include <cstdint>

#include "atmonsat.h"
#include "atmonsat_anomaly_detection.h"
#include "atmonsat_testbench.h"
#include "protocol.h"
#include "time_metric.h"

using namespace atmonsat;
namespace atmonsat
{

    /* A datalink for communication must be defined somewhere in the code. */
#ifdef ATMONSAT_TESTBENCH_EXTERNAL_DATALINK
    extern DataLink *atmonsat_protocol_datalink;
#else
#include "protocol_datalink_pipe.h"
    ProtocolDatalinkPipe pipe;
    DataLink *atmonsat_protocol_datalink = &pipe;
#endif

#ifdef ATMONSAT_TESTBENCH_EXTERNAL_TIME_METRIC
    extern TimeMetric *time_metric;
#else
#include "time_metric_native.h"
    TimeMetricNative time_metric_native;
    TimeMetric *time_metric = &time_metric_native;
#endif

    /**
     * @brief Supported responses
     *
     */
    ProtocolResponseValue<float> response_value_float(PROTOCOL_COMMAND_ID_FLOAT, atmonsat_protocol_datalink);
    ProtocolResponseValue<uint8_t> response_value_detection(PROTOCOL_COMMAND_ID_DETECTION, atmonsat_protocol_datalink);
    ProtocolResponseValue<float> response_value_distance(PROTOCOL_COMMAND_ID_MAHALANOBIS_DISTANCE, atmonsat_protocol_datalink);
    ProtocolResponseComment response_comment(PROTOCOL_COMMAND_ID_COMMENT, atmonsat_protocol_datalink);
    ProtocolResponseComment response_exception(PROTOCOL_COMMAND_ID_EXCEPTION, atmonsat_protocol_datalink);
    ProtocolResponseValue<uint32_t> response_value_execution_time(PROTOCOL_COMMAND_ID_EXECUTION_TIME, atmonsat_protocol_datalink);

    /* anomaly detection callbacks forward definition */
    void ad_callback_exception(const char *str);
    void ad_callback_message(const char *str);
    void ad_callback_detection(const bool detection);
    void ad_callback_distance(const float distance);

    bool is_initialized = false;

/**
 * @brief Define DebugLog for tensorflow light
 *        This is required since commit:
 *        21bd77c62b75689b7ff713ace54fc3735b73dc40
 */
#include "tensorflow/tensorflow/lite/micro/debug_log.h"
    extern "C" void DebugLog(const char *str)
    {
        ad_callback_message(str);
    }

    /**
     * @brief protocol handler callback after receiving a initialize request
     *        initialization has been done within a callback to allow tf lite micro to report errors during setup
     *        (communication direction must the from mc->pc)
     *
     * @param handler
     * @return ipr_t
     */
    ipr_t protocol_handler_initialize_callback(VirtualProtocolHandler *handler)
    {
        (void)handler;
        response_comment.send_rply(); /* announce that there is a reply */

#ifndef PLACEBO
        /* setup anomaly detection */
        if (!is_initialized)
        {
            arc_t status = atmonsat_anomaly_detection_setup(ad_callback_message,
                                                            ad_callback_exception,
                                                            ad_callback_detection,
                                                            ad_callback_distance);
            if (status == ARC_SUCCESS)
            {
                response_comment.send("target initialized.");
                is_initialized = true;
            }
            else
            {
                response_exception.send("target initialization failed.");
            }
        }
        else
        {
            atmonsat_anomaly_detection_reset();
            response_comment.send("target is already initialized: resetting to zero instead.");
        }
#else
        response_comment.send("Target compiled with PLACEBO.");
#endif

        response_comment.send_erp(); /* send end of reply */
        /* keep default handler from sending ACK */
        return PROTOCOL_ALREADY_RESPONDED_ACK;
    }

    /**
     * @brief protocol handler callback after receiving a comment request
     *
     * @param handler
     * @return ipr_t
     */
    ipr_t protocol_handler_comment_request_callback(VirtualProtocolHandler *handler)
    {
        (void)handler;
        response_comment.send_rply(); /* announce that there is a reply */
        response_comment.send("hello");
        response_comment.send_erp(); /* send end of reply */

        /* keep default handler from sending ACK */
        return PROTOCOL_ALREADY_RESPONDED_ACK;
    }

    /**
     * @brief protocol handler callback after receiving a datapoint
     *
     * @param handler
     * @return ipr_t
     */
    ipr_t protocol_handler_datapoint_callback(VirtualProtocolHandler *handler)
    {
        t_datapoint<t_data, ATMONSAT_DIMENSIONS_PER_DATAPOINT> *datapoint =
            static_cast<t_datapoint<t_data, ATMONSAT_DIMENSIONS_PER_DATAPOINT> *>(handler->data());

        /* in any case initiate a reply */
        response_comment.send_rply();

#ifndef PLACEBO
        /* start measuring execution time */
        time_metric->zero();
        time_metric->start();

        /* run one iteration of anomaly detection */
        atmonsat_anomaly_detection_run_once(*datapoint);

        /* stop measuring execution time */
        time_metric->stop();

        /* report execution time */
        response_value_execution_time.send(time_metric->duration());
#endif
        /* send end of reply */
        response_comment.send_erp();

        /* keep default handler from sending ACK */
        return PROTOCOL_ALREADY_RESPONDED_ACK;
    }

    /**
     * @brief protocol handler callback after receiving a hold-off
     *
     * @param handler
     * @return ipr_t
     */
    ipr_t protocol_handler_hold_off_callback(VirtualProtocolHandler *handler)
    {
        (void)handler;
        response_comment.send_rply();
        response_comment.send("hold-off updated");
        response_comment.send_erp();
        return PROTOCOL_ALREADY_RESPONDED_ACK;
    }

    /**
     * @brief protocol handler callback after receiving a threshold
     *
     * @param handler
     * @return ipr_t
     */
    ipr_t protocol_handler_threshold_callback(VirtualProtocolHandler *handler)
    {
        (void)handler;
        response_comment.send_rply();
        response_comment.send("treshold updated");
        response_comment.send_erp();
        return PROTOCOL_ALREADY_RESPONDED_ACK;
    }

    /**
     * @brief protocol handler callback after mhalanobis inverse covariance matrix has been updated
     *
     * @param handler
     * @return ipr_t
     */
    ipr_t protocol_handler_mahalanobis_inverse_covariance_callback(VirtualProtocolHandler *handler)
    {
        (void)handler;
        response_comment.send_rply();
        response_comment.send("mahalanobis inverse covariance matrix has been updated");
        response_comment.send_erp();
        return PROTOCOL_ALREADY_RESPONDED_ACK;
    }

    /**
     * @brief protocol handler callback after mhalanobis mean matrix has been updated
     *
     * @param handler
     * @return ipr_t
     */
    ipr_t protocol_handler_mahalanobis_mean_callback(VirtualProtocolHandler *handler)
    {
        (void)handler;
        response_comment.send_rply();
        response_comment.send("mahalanobis mean matrix has been updated");
        response_comment.send_erp();
        return PROTOCOL_ALREADY_RESPONDED_ACK;
    }

    /*----------------------------------------------------------------------------*/
    /**
     * @brief message callback for anomaly detection algorithm
     *
     * @param str
     */
    void ad_callback_message(const char *str)
    {
        time_metric->stop(); /* exclude communication from measurement */
        response_comment.send(str);
        time_metric->start(); /* resume measurement after communication */
    }

    /**
     * @brief exception callback for anomaly detection algorithm
     *
     * @param str
     */
    void ad_callback_exception(const char *str)
    {
        time_metric->stop(); /* exclude communication from measurement */
        response_exception.send(str);
        time_metric->start(); /* resume measurement after communication */
    }

    /**
     * @brief detection callback for anomaly detection algorithm
     *
     * @param detection
     */
    void ad_callback_detection(const bool detection)
    {
        time_metric->stop(); /* exclude communication from measurement */
        if (detection)
        {
            response_value_detection.send(1);
        }
        else
        {
            response_value_detection.send(0);
        }
        time_metric->start(); /* resume measurement after communication */
    }

    /**
     * @brief distance callback for anomaly detection algorithm
     *
     * @param distance
     */
    void ad_callback_distance(const float distance)
    {
        time_metric->stop(); /* exclude communication from measurement */
        response_value_distance.send(distance);
        time_metric->start(); /* resume measurement after communication */
    }

    /*----------------------------------------------------------------------------*/

    /**
     * @brief variable to hold an incoming datapoint
     */
    t_datapoint<t_data, ATMONSAT_DIMENSIONS_PER_DATAPOINT> value_datapoint;

    /**
     * @brief Protocol handlers
     */
    ProtocolHandlerDatapoint<t_data, ATMONSAT_DIMENSIONS_PER_DATAPOINT> protocol_handler_datapoint(&value_datapoint, protocol_handler_datapoint_callback);
    ProtocolHandlerRequestComment protocol_handler_request_comment(protocol_handler_comment_request_callback);
    ProtocolHandlerInitialize protocol_handler_initialize(protocol_handler_initialize_callback);
#ifndef PLACEBO
    ProtocolHandlerValue<t_distance> protocol_handler_detection_threshold(&threshold.threshold, protocol_handler_threshold_callback);
    ProtocolHandlerValue<t_hold_off> protocol_handler_detection_hold_off(&threshold.hold_off, protocol_handler_hold_off_callback);
    ProtocolHandlerMatrix<2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT, 2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT, t_internal> protocol_handler_mahalanobis_inverse_covariance(&mahalanobis.inverse_covariance, protocol_handler_mahalanobis_inverse_covariance_callback);
    ProtocolHandlerMatrix<1, 2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT, t_internal> protocol_handler_mahalanobis_mean(&mahalanobis.mean, protocol_handler_mahalanobis_mean_callback);
#else
    /* dummy placeholders must be defined not to break the protocol during placebo run for memory size evaluation */
    t_distance dummy_threshold;
    t_hold_off dummy_hold_off;
    Matrix<2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT, 2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT, t_internal> dummy_matrix;
    Matrix<1, 2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT, t_internal> dummy_mean;
    ProtocolHandlerValue<t_distance> protocol_handler_detection_threshold(&dummy_threshold, protocol_handler_threshold_callback);
    ProtocolHandlerValue<t_hold_off> protocol_handler_detection_hold_off(&dummy_hold_off, protocol_handler_hold_off_callback);
    ProtocolHandlerMatrix<2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT, 2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT, t_internal> protocol_handler_mahalanobis_inverse_covariance(&dummy_matrix, protocol_handler_mahalanobis_inverse_covariance_callback);
    ProtocolHandlerMatrix<1, 2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT, t_internal> protocol_handler_mahalanobis_mean(&dummy_mean, protocol_handler_mahalanobis_mean_callback);
#endif

    /**
     * @brief array of all supported protocol handlers
     */
    VirtualProtocolHandler *protocol_handlers[] = {
        &protocol_handler_initialize,
        &protocol_handler_datapoint,
        &protocol_handler_request_comment,
        &protocol_handler_detection_threshold,
        &protocol_handler_detection_hold_off,
        &protocol_handler_mahalanobis_inverse_covariance,
        &protocol_handler_mahalanobis_mean};

    /**
     * @brief command triggers for the protocol handlers
     *        The order must be the same as in protocol_handlers
     *
     */
    uint8_t triggers[] = {
        static_cast<uint8_t>(PROTOCOL_COMMAND_ID_INITIALIZE),                            /* initialize host */
        static_cast<uint8_t>(PROTOCOL_COMMAND_ID_DATAPOINT_INT8),                        /* incoming datapoint -> runs iislcc -> anomaly dection -> results */
        static_cast<uint8_t>(PROTOCOL_COMMAND_ID_REQUEST_COMMENT),                       /* request a comment: for debugging. can be ignored */
        static_cast<uint8_t>(PROTOCOL_COMMAND_ID_THRESHOLD),                             /* modify detection threshold */
        static_cast<uint8_t>(PROTOCOL_COMMAND_ID_THRESHOLD_HOLD_OFF),                    /* modify threshold hold-off value */
        static_cast<uint8_t>(PROTOCOL_COMMAND_ID_MAHALANOBIS_INVERSE_COVARIANCE_MATRIX), /* modify mahalanobis inverse covariance matrix */
        static_cast<uint8_t>(PROTOCOL_COMMAND_ID_MAHALANOBIS_MEAN)                       /* modify mahalanobis mean vector */
    };

    /**
     * @brief Protocol instance
     */
    Protocol protocol(triggers, protocol_handlers, sizeof(triggers), atmonsat_protocol_datalink);

    /**
     * @brief initialize testbench
     *
     */
    void atmonsat_testbench_initialize()
    {
        /* note that setup cannot be done here as tf lite micro would try to use the error reporter
           while the communication direction is still PC->MC. This direction can only be changed in a callback
        */
    }

    /**
     * @brief run one testbench iteration
     *
     */
    void atmonsat_testbench_run_once()
    {
        /* handle one next step in the protocol */
        protocol.handle();
    }

}
