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
 
#ifndef __ATMONSAT_DEFINITIONS_H__
#define __ATMONSAT_DEFINITIONS_H__

#include <cstdint>

namespace atmonsat
{

#define ATMONSAT_DATAPOINT_SUPPORT_IOSTREAM
#define ATMONSAT_DATAWINDOW_SUPPORT_IOSTREAM
#define ATMONSAT_MATRIX_SUPPORT_IOSTREAM

#define ATMONSAT_USE_MEMCPY

#define ATMONSAT_DIMENSIONS_PER_DATAPOINT 9
#define ATMONSAT_WINDOW_SIZE 150
#define ATMONSAT_TFLM_ARENA_SIZE 23000 

#include "atmonsat_mahalanobis_precalculated_threshold.h"

#define ATMONSAT_ANOMALY_DETECTION_HOLD_OFF 0

#define ATMONSAT_ISLCC_WINDOW_SIZE 100

/* model input order (temperature / islc first) */
#define ATMONSAT_INPUT_TENSOR_ORDER_ISLC_TEMPERATURE 1
#define ATMONSAT_INPUT_TENSOR_ORDER_TEMPERATURE_ISLC 2
#define ATMONSAT_INPUT_TENSOR_ORDER ATMONSAT_INPUT_TENSOR_ORDER_ISLC_TEMPERATURE 

#define ATMONSAT_WINDOW_ORDER_ASCENDING 1
#define ATMONSAT_WINDOW_ORDER_DESCENDING 2
#define ATMONSAT_WINDOW_ORDER ATMONSAT_WINDOW_ORDER_ASCENDING

#define PROTOCOL_RESPONSE_COMMENT_SUPPORT_VARIADIC
#define PROTOCOL_RESPONSE_COMMENT_FORMAT_BUFFER 128

    /**
     * @brief Type definitions
     *
     */
    typedef uint8_t t_data;        /*! type of a data value */
    // typedef uint32_t t_iterations; /*! type of a iteration count */
    typedef float t_iterations; /*! type of a iteration count */

    typedef float t_internal;      /*! type after inferance before mahalanobis */
    typedef float t_distance;      /*! type of a distance */
    typedef bool t_bool;           /*! type of a bool */
    typedef uint32_t t_hold_off;   /*! type of a hold-off value */

    typedef enum
    {
        ARC_FAILED = 0,
        ARC_SUCCESS = 1
    } arc_t;

}

#endif
