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
 
#ifndef __PROTOCOL_TIME_METRIC_NATIVE_H_
#define __PROTOCOL_TIME_METRIC_NATIVE_H_

#include <cstdint>
#include <time.h>

#include "time_metric.h"

namespace atmonsat
{
    /**
     * @brief Metric to measure passed time
     *        Implementation for posix
     *
     */
    class TimeMetricNative : public TimeMetric
    {
    private:
        t_time delta_time(timespec start, timespec end);

        timespec _start_time;
        timespec _stop_time;
        t_time _accumulated_time;

    public:
        TimeMetricNative();
        void zero(void) override;
        void start(void) override;
        void stop(void) override;
        t_time duration(void) override;
    };
}

#endif
