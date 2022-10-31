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
 
#ifndef __ATMONSAT_DATA_WINDOW_H__
#define __ATMONSAT_DATA_WINDOW_H__

#include <cstring>

#include "atmonsat.h"

#ifdef ATMONSAT_DATAWINDOW_SUPPORT_IOSTREAM
#include <iostream>
#endif

#include "datapoint.h"

namespace atmonsat
{
    /**
     * @brief Window of datapoints
     *
     * data               index              zi
     * 00|01|02|03|04|05  00|01|02|03|04|05  00
     * 06|01|02|03|04|05  05|00|01|02|03|04  01
     * 06|07|02|03|04|05  04|05|00|01|02|03  02
     * 06|07|08|03|04|05  03|04|05|00|01|02  03
     * 06|07|08|09|04|05  02|03|04|05|00|01  04
     * 06|07|08|09|10|05  01|02|03|04|05|00  05
     * 06|07|08|09|10|11  00|01|02|03|04|05  00
     * 12|07|08|09|10|11  05|00|01|02|03|04  01
     * 12|13|08|09|10|11  04|05|00|01|02|03  02 
     *
     * @tparam T Type of each datapoints (e.g. double)
     * @tparam N Dimension of each datapoint
     * @tparam W Window size
     *
     * @example DataWindow<t_datapoint<t_data, DIMENSIONS_PER_DATAPOINT>, WINDOW_SIZE> window;
     * T = t_datapoint<t_data, DIMENSIONS_PER_DATAPOINT>
     */
    template <typename T, unsigned int W>
    class DataWindow
    {
    private:
        T _datapoints[W];
        unsigned int _zero_index = 0;

    public:
        /**
         * @brief reset
         *
         */
        void reset(void)
        {
            for (unsigned int i = 0; i < W; i++)
            {
                _datapoints[i].zero();
            }
            _zero_index = 0;
        }

        /**
         * @brief get datapoint at <index>
         *
         * @param index
         * @return const T&
         */
        const T &get(unsigned int index) const
        {
            if ((_zero_index + index) >= W)
            {
                return _datapoints[(_zero_index + index) - W];
            }
            return _datapoints[_zero_index + index];
        }

        /**
         * @brief push a new datapoint into the window
         *        the oldest datapoint will drop out
         *
         * @param datapoint
         */
        void push(const T &datapoint)
        {
            _datapoints[_zero_index++] = datapoint;
            if (_zero_index >= W)
            {
                _zero_index = 0;
            }
        }

#ifdef ATMONSAT_DATAWINDOW_SUPPORT_IOSTREAM
        friend std::ostream &operator<<(std::ostream &os, const DataWindow<T, W> &window)
        {
            os << "dw(";
            for (unsigned int i = 0; i < W; ++i)
            {
                if (i != 0)
                {
                    os << ", ";
                }

                os << window.get(i);
            }
            os << ")";

            return os;
        }
#endif
    };

}

#endif
