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
#include <time.h>

#include "atmonsat.h"
#include "atmonsat_testbench.h"
#include "main_native.h"

/* create datalink for communication */
#ifdef ATMONSAT_TESTBENCH_EXTERNAL_DATALINK
#include "protocol_datalink_pipe.h"
namespace atmonsat
{
    ProtocolDatalinkPipe pipe;
    DataLink *atmonsat_protocol_datalink = &pipe;
}
#endif

/* create metric for time measurement */
#ifdef ATMONSAT_TESTBENCH_EXTERNAL_TIME_METRIC
#include "time_metric_native.h"
namespace atmonsat
{
    TimeMetricNative time_metric_native;
    TimeMetric *time_metric = &time_metric_native;
}
#endif

#define HANDLE_SIGNALS

volatile bool keep_running = true;
#ifdef HANDLE_SIGNALS
#include <signal.h>

void sigint_handler(int d) 
{
    keep_running = false;
}
#endif

/**
 * @brief Main
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
    /* initialize testbench */
    atmonsat_testbench_initialize();

#ifdef HANDLE_SIGNALS
    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigint_handler);
    signal(SIGKILL, sigint_handler);
#endif

    /* main loop */
#ifdef HANDLE_SIGNALS
    keep_running = true;
    while (keep_running)
#else
    while(1)
#endif
    {
        /* run one iteration of the testbench */
        atmonsat::atmonsat_testbench_run_once();

        /* free some time to the kernel */
        struct timespec remaining, request = {0, 200};
        nanosleep(&request, &remaining);
    }

    return 1;
}
