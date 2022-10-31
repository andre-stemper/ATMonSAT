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

#ifndef __TIME_METRIC_STM32_FREERTOS_H_
#define __TIME_METRIC_STM32_FREERTOS_H_

#include <cstdint>
#include <time.h>

#include "main_stm32_freertos.h"
#include "time_metric.h"
#include "stm32h7xx_hal.h"

/**
 * Core clock dependent settings
 */

/* 298 MHz */
#if defined(ATMONSAT_CLOCK_PROFILE) && (ATMONSAT_CLOCK_PROFILE == 298)
#define TIME_METRIC_PRESCALER 149
#define TIME_METRIC_STM32_NANOSECONDS_PER_TICK 1000
/* 146 MHz */
#elif defined(ATMONSAT_CLOCK_PROFILE) && (ATMONSAT_CLOCK_PROFILE == 146)
#define TIME_METRIC_PRESCALER 73
#define TIME_METRIC_STM32_NANOSECONDS_PER_TICK 1000
/* 78 MHz*/
#elif defined(ATMONSAT_CLOCK_PROFILE) && (ATMONSAT_CLOCK_PROFILE == 78)
#define TIME_METRIC_PRESCALER 39
#define TIME_METRIC_STM32_NANOSECONDS_PER_TICK 1000
/* 39 MHz */
#elif defined(ATMONSAT_CLOCK_PROFILE) && (ATMONSAT_CLOCK_PROFILE == 39)
#define TIME_METRIC_PRESCALER 39
#define TIME_METRIC_STM32_NANOSECONDS_PER_TICK 1000
#endif

/**
 * Defining TIME_METRIC_STM32_TEST_TIMING for counter checking timing:
 * enables an interrupt that toggles a GPIO output for time measurement
 * Start timer and then continue in a while(1); The GPIO pin should show
 * a 500ms (toggling) signal if the registers have been loaded correctly
 */
#undef TIME_METRIC_STM32_TEST_TIMING
// #define TIME_METRIC_STM32_TEST_TIMING

namespace atmonsat
{
    /**
     * @brief Metric to measure passed time
     *        Implementation for STM32H743
     *
     */
    class TimeMetricSTM32 : public TimeMetric
    {
    private:
#ifndef TIME_METRIC_STM32_TEST_TIMING
        TIM_HandleTypeDef htim2;
#endif
        t_time delta_time(timespec start, timespec end);

        timespec _start_time;
        timespec _stop_time;
        t_time _accumulated_time;

    public:
#ifdef TIME_METRIC_STM32_TEST_TIMING
        TIM_HandleTypeDef htim2;
#endif
        TimeMetricSTM32();
        void initialize();
        void zero(void) override;
        void start(void) override;
        void stop(void) override;
        t_time duration(void) override;
    };
#ifdef TIME_METRIC_STM32_TEST_TIMING
    extern TimeMetricSTM32 time_metric_stm32;
#endif
}

#endif