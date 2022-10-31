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
 
#ifndef __ATMONSAT_ITERATIONS_SINCE_LAST_CHANGE_COUNTER_INTERPOLATOR_H__
#define __ATMONSAT_ITERATIONS_SINCE_LAST_CHANGE_COUNTER_INTERPOLATOR_H__

#include <functional>

#include "datapoint.h"
#include "linear_interpolation.h"

namespace atmonsat
{
    template <typename Tdata, typename Tcnt, unsigned int DWidth>
    using ISLCC_Interpolator_Callback = void (*)(t_datapoint<Tdata, DWidth>, t_datapoint<Tcnt, DWidth>, bool);

    template <typename Tdata, typename Tcnt, unsigned int DWidth, unsigned int WSize>
    class ISLCC_Interpolator
    {
    private:
        unsigned int _next_row_index = 0;
        t_datapoint<Tdata, DWidth> _last_datapoint;
        t_datapoint<Tcnt, DWidth> _islc;
        t_datapoint<Tdata, DWidth> _window_data[WSize];
        t_datapoint<Tcnt, DWidth> _window_islc[WSize];
        ISLCC_Interpolator_Callback<Tdata, Tcnt, DWidth> _callback;

    public:
        ISLCC_Interpolator(ISLCC_Interpolator_Callback<Tdata, Tcnt, DWidth>
                               callback = nullptr) : _callback(callback){};

        /**
         * @brief reset
         *
         */
        void reset()
        {
            _next_row_index = 0;
            _last_datapoint.zero();
            _islc.zero();
            for (unsigned i = 0; i < WSize; ++i)
            {
                _window_data[i].zero();
                _window_islc[i].zero();
            }
        }

        /**
         * @brief callback inference algorithm
         *
         */
        void _callback_inference(t_datapoint<Tdata, DWidth> datapoint,
                                 t_datapoint<Tcnt, DWidth> islc,
                                 bool forced = false)
        {
            if (_callback != nullptr)
            {
                _callback(datapoint, islc, forced);
            }
        }

        /**
         * @brief roll windows by 1 step, removing the first data points(data, islc).
         *
         */
        void _roll_windows()
        {
            assert(_next_row_index > 0);
            for (unsigned int i = 0; i < _next_row_index - 1; ++i)
            {
                _window_data[i] = _window_data[i + 1];
                _window_islc[i] = _window_islc[i + 1];
            }
            _next_row_index--;
        }

        /**
         * @brief Append one datapoint + islc to the window at the current position++
         *
         * @param datapoint datapoint to append
         * @param islc islc to append
         */
        void _append(t_datapoint<Tdata, DWidth> datapoint, t_datapoint<Tcnt, DWidth> islc)
        {
            assert(_next_row_index < WSize);
            _window_data[_next_row_index] = datapoint;
            _window_islc[_next_row_index] = islc;
            _next_row_index++;
        }

        /**
         * @brief Push new datapoint into ISLC-Interpolator.
         *
         * @param datapoint
         */
        void push_datapoint(t_datapoint<Tdata, DWidth> datapoint)
        {
            unsigned int i, j;

            /* Increase all isl-counters */
            for (i = 0; i < DWidth; ++i)
            {
                _islc.add(i, 1);
            }

            /* If no change happend just append new datapoint
             * (maybe discard the first one first to free up some space)
             */
            if (datapoint == _last_datapoint)
            {
                if (_next_row_index == WSize)
                {
                    _callback_inference(_window_data[0], _window_islc[0], true);
                    _roll_windows();
                }
                _append(datapoint, _islc);
            }
            else /* if a change happend */
            {
                /* for every coordinate in datapoint */
                for (i = 0; i < DWidth; ++i)
                {
                    /* compare if datapoint does not match the last_datapoint */
                    if (datapoint.get(i) != _last_datapoint.get(i))
                    {
                        _islc.set(i, 0); /* reset the corresponding counter */
                        /* revisit all rows above the current row */
                        for (j = 0; j < _next_row_index; ++j)
                        {
                            /* replace by the interpolation of the first rows data to 0 */
                            _window_islc[j].set(i, interpolate_linear<unsigned int, Tcnt>(j,
                                                                                          0, _window_islc[0].get(i),
                                                                                          _next_row_index, 0));
                        }
                    }
                }
                /* run the inference on all rows till now, eptying the windows */
                while (_next_row_index > 0)
                {
                    _callback_inference(_window_data[0], _window_islc[0], false);
                    _roll_windows();
                }

                /* append the current datapoint at the top of the window*/
                _append(datapoint, _islc);

                /* make current datapoint the next last_datapoint */
                _last_datapoint = datapoint;
            }
        }
    };
}

#endif
