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
 
#ifndef __ATMONSAT_THRESHOLD_H__
#define __ATMONSAT_THRESHOLD_H__

#include "atmonsat.h"

#define DEFAULT_THRESHOLD ATMONSAT_ANOMALY_DETECTION_THRESHOLD
#define DEFAULT_HOLD_OFF ATMONSAT_ANOMALY_DETECTION_HOLD_OFF

namespace atmonsat
{

    /**
     * @brief Implements threshold with hold-off counter.
     *
     * @tparam T data type
     */
    template <typename T, typename H>
    class Threshold
    {

    private:
        bool _decision = false;
        H _hold_off_counter = 0;
     
    public:

       /**
         * @brief anomaly detection threshold
         *
         */
        T threshold = DEFAULT_THRESHOLD;

        /**
         * @brief anomaly detection hold-off
         * 
         */
        H hold_off = DEFAULT_HOLD_OFF;

        /**
         * @brief input new value 
         * 
         * @param value 
         */
        T input(T value)
        {
            if(_hold_off_counter == 0)
            {
                if(value >= threshold)
                {
                    _decision = true;
                    _hold_off_counter = hold_off;
                }
                else
                {
                    _decision = false;
                }
            }
            else
            {
                _hold_off_counter --;
                _decision = false;
            }

            return _decision;
        }

        /**
         * @brief get last decision
         * 
         */
        bool decision()
        {
            return _decision;
        }
        
        /**
         * @brief reset 
         * 
         */
        void reset(void) 
        {
            _decision = false;
            hold_off = DEFAULT_HOLD_OFF;
            _hold_off_counter = 0;
        }
    };
}

#endif
