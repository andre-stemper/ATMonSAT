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
#include <fstream>
#include <string>
#include <iterator>
#include <fcntl.h>
#include <cstdint>
#include <time.h>

#include "time_metric_native.h"

using namespace atmonsat;
using namespace std;

#define CLOCK_ID CLOCK_PROCESS_CPUTIME_ID

namespace atmonsat
{

    /**
     * @brief construct a new native time metric object
     * 
     */
    TimeMetricNative::TimeMetricNative()
    {
        zero();
    }

    /**
     * @brief zero duration
     *
     */
    void TimeMetricNative::zero()
    {
        _accumulated_time = 0;
    }

    /**
     * @brief start / resume timer
     *
     */
    void TimeMetricNative::start()
    {
        clock_gettime(CLOCK_ID, &_start_time);
    }

    /**
     * @brief stop / pause timer
     *
     */
    void TimeMetricNative::stop()
    {
        clock_gettime(CLOCK_ID, &_stop_time);
        _accumulated_time = _accumulated_time +
                            (_stop_time.tv_sec - _start_time.tv_sec) * 1000000000 +
                            (_stop_time.tv_nsec - _start_time.tv_nsec);
    }

    /**
     * @brief get accumulated duration
     *
     * @return t_time
     */
    t_time TimeMetricNative::duration(void)
    {
        return _accumulated_time;
    }
}
