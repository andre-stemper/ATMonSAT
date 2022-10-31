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
 
#ifndef __ATMONSAT_LINEAR_INTERPOLATION_H__
#define __ATMONSAT_LINEAR_INTERPOLATION_H__

#include <cassert>

namespace atmonsat
{
    template <typename Tx, typename Ty, typename Ti=float>
    Ty interpolate_linear(Tx x, Tx x0, Ty y0, Tx x1, Ty y1)
    {
        assert(x >= x0);
        assert(x <= x1);
        if (x0 == x1)
        {
            assert(y0 == y1);
            return (y0);
        }
        return (static_cast<Ty>(((static_cast<Ti>(y1) - static_cast<Ti>(y0)) / (static_cast<Ti>(x1) - static_cast<Ti>(x0))) * (static_cast<Ti>(x) - static_cast<Ti>(x0)) + static_cast<Ti>(y0)));
    }
}

#endif
