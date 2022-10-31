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

#ifndef __ATMONSAT_ITERATIONS_SINCE_LAST_CHANGE_COUNTER_H__
#define __ATMONSAT_ITERATIONS_SINCE_LAST_CHANGE_COUNTER_H__

#include "datapoint.h"

namespace atmonsat
{

    /**
     * @brief Iterations Since Last Change Counter.
     *        Implements a n-dimensional counter that counts the number of iterations per coordinate
     *        since the last change of that coordinate in the input.
     *
     * @tparam Tdata the type of an input datapoint
     * @tparam Tcnt the type of the counting datapoint.
     * @tparam n number of dimensions in the input/output data point.
     */

    template <typename Tdata, typename Tcnt>
    class ISLCC
    {
    private:
        Tdata last_datapoint;                     /*! variable to hold the last <n>-dimensional datapoint */
        Tcnt iterations_since_last_change_vector; /*! */

    public:
        ISLCC() : last_datapoint(), iterations_since_last_change_vector(){};

        /**
         * @brief Get the iterations since last change vector object
         *
         * @return Tcnt* returns an datapoint with the iterations count
         *               since the last change in each dimension
         */
        Tcnt &get()
        {
            return iterations_since_last_change_vector;
        }

        /**
         * @brief Update the interations counter with a new datapoint
         *
         * @param datapoint new datapoint to consider
         */
        void update(Tdata &datapoint)
        {
            for (unsigned int i = 0; i < sizeof(last_datapoint.data)/sizeof(last_datapoint.data[0]); i++)
            {
                if (datapoint.data[i] != last_datapoint.data[i])
                {
                    iterations_since_last_change_vector.data[i] = 0;
                }
                else
                {
                    iterations_since_last_change_vector.data[i]++;
                }

               //  last_datapoint.data[i] = datapoint.data[i];
            }
            last_datapoint = datapoint;
        }
    };

}

#endif