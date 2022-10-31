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
 
#ifndef __ATMONSAT_ANOMALY_DETECTION_H_
#define __ATMONSAT_ANOMALY_DETECTION_H_

#include "atmonsat.h"
#include "datapoint.h"
#include "mahalanobis.h"
#include "threshold.h"

#ifdef __cplusplus
extern "C"
{
#endif

    namespace atmonsat
    {

        /**
         * @brief settings that can be changed externally (e.g. protocol handlers)
         *
         */
        extern Threshold<t_distance, t_hold_off> threshold;
        extern t_hold_off anomaly_detection_hold_off;
        extern Mahalanobis<2 * ATMONSAT_DIMENSIONS_PER_DATAPOINT, t_distance> mahalanobis;

        /**
         * @brief callbacks to report results
         */
        typedef void (*ad_message_callback)(const char *str);
        typedef void (*ad_exception_callback)(const char *str);
        typedef void (*ad_detection_callback)(const bool detection);
        typedef void (*ad_distance_callback)(const float distance);

        arc_t atmonsat_anomaly_detection_setup(ad_message_callback message_callback = nullptr,
                                               ad_exception_callback exception_callback = nullptr,
                                               ad_detection_callback detection_callback = nullptr,
                                               ad_distance_callback distance_callback = nullptr);
        arc_t atmonsat_anomaly_detection_run_once(t_datapoint<t_data, ATMONSAT_DIMENSIONS_PER_DATAPOINT> &datapoint);
        arc_t atmonsat_anomaly_detection_reset(void);

    }

#ifdef __cplusplus
}
#endif

#endif
