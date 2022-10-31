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
 
#ifndef __ATMONSAT_MAHALANOBIS_H__
#define __ATMONSAT_MAHALANOBIS_H__

#include <cmath>

#include "atmonsat.h"
#include "datapoint.h"
#include "matrix.h"

namespace atmonsat
{

    template <unsigned DDIM = ATMONSAT_DIMENSIONS_PER_DATAPOINT, typename T = float>
    class Mahalanobis
    {
    public:
        Matrix<1, DDIM, T> mean = {};
        Matrix<DDIM, DDIM, T> inverse_covariance = {};

        /**
         * @brief Square of mahalanobis distance to mean value
         *
         * @param dp
         * @return T
         */
        T square_distance(Matrix<1, DDIM, T> dp)
        {
            return square_distance(dp, mean);
        }


#ifdef SUPPORT_MATRIX_SUBTRACTION_FROM_DATAPOINT
        /**
         * @brief Square of mahalanobis distance to mean value
         *
         * @param dp
         * @return T
         */
        T square_distance(t_datapoint<T, DDIM> dp)
        {
            return square_distance(dp, mean);
        }
#endif

        /**
         * @brief Square of mahalanobis distance
         *
         * @param dp1 point one
         * @param dp2 point two
         * @return T square of distance
         */
        T square_distance(Matrix<1, DDIM, T> dp1, Matrix<1, DDIM, T> dp2)
        {
            Matrix<1, DDIM, T> di = dp1 - dp2;
            Matrix<1, 1, T> r = di * inverse_covariance.transpose_multiply(di);
            return r.data[0];
        }

#ifdef SUPPORT_MATRIX_SUBTRACTION_FROM_DATAPOINT
        /**
         * @brief Square of mahalanobis distance
         *
         * @param dp1 point one (datapoint)
         * @param dp2 point two (matrix)
         * @return T square of distance
         */
        T square_distance(t_datapoint<T, DDIM> dp1, Matrix<1, DDIM, T> dp2)
        {
            Matrix<1, DDIM, T> di = dp1 - dp2;
            Matrix<1, 1, T> r = di * inverse_covariance.transpose_multiply(di);
            return r.data[0];
        }
#endif

        /**
         * @brief mahalanobis distance to mean value
         *
         * @param dp
         * @return T
         */
        T distance(Matrix<1, DDIM, T> dp)
        {
            return distance(dp, mean);
        }

        /**
         * @brief mahalanobis distance
         *
         * @param dp1 point one
         * @param dp2 point two
         * @return T distance
         */
        T distance(Matrix<1, DDIM, T> dp1, Matrix<1, DDIM, T> dp2)
        {
            return (sqrt(square_distance(dp1, dp2)));
        }
    };
}

#endif
