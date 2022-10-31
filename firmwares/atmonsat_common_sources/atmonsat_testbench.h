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
 
#ifndef __ATMONSAT_TESTBENCH_H__
#define __ATMONSAT_TESTBENCH_H__

#include <cstdint>
#include "atmonsat.h"
#include "protocol_datalink.h"
#include "time_metric.h"

/* define if datalink for communication is already defined elsewhere in the code */
#define ATMONSAT_TESTBENCH_EXTERNAL_DATALINK
#define ATMONSAT_TESTBENCH_EXTERNAL_TIME_METRIC

namespace atmonsat
{

#ifdef ATMONSAT_TESTBENCH_EXTERNAL_DATALINK
    extern DataLink *atmonsat_protocol_datalink;
#endif

#ifdef ATMONSAT_TESTBENCH_EXTERNAL_TIME_METRIC
    extern TimeMetric *time_metric;
#endif  

    void atmonsat_testbench_initialize();
    void atmonsat_testbench_run_once();
}

#endif
