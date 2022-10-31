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
 
#ifndef __ATMONSAT_DATAPOINT_H__
#define __ATMONSAT_DATAPOINT_H__

#include <cstring>
#include <cassert>

#include "atmonsat.h"

#ifdef ATMONSAT_DATAPOINT_SUPPORT_IOSTREAM
#include <iostream>
#endif

#define SUPPORT_MATRIX_SUBTRACTION_FROM_DATAPOINT

#ifdef SUPPORT_MATRIX_SUBTRACTION_FROM_DATAPOINT
namespace atmonsat
{
    template <unsigned RC, unsigned CC, typename T>
    class Matrix;
}
#endif

namespace atmonsat
{

    /**
     * @brief n-dimensional datapoint
     *
     * @tparam T data type of each coordinate
     * @tparam n dimension of datapoint
     */

    template <typename T, unsigned int N>
    class t_datapoint
    {
    public:
        T data[N];                          /*! variable to hold the values of one datapoint */
        static const unsigned int size = N; /*! size of a datapoint */

        /**
         * @brief fill all coordinates with zero
         *
         */
        inline void zero()
        {
#if 1
            memset(data, 0x00, sizeof(T) * N);
#else
            for (unsigned int i = 0; i < N; i++)
            {
                data[i] = static_cast<T>(0);
            }
#endif
        }

        /**
         * @brief get N-dimension array of coordinates of this datapoint
         *
         * @return const T*
         */
        inline const T &get(void) const
        {
            return data;
        }

        /**
         * @brief get data from field referenced by index
         *
         * @param index
         */
        inline const T &get(const unsigned int index) const
        {
            assert(index < size);
            return data[index];
        }

        /**
         * @brief set data into field referenced by index
         *
         * @param index
         * @param value
         */
        inline void set(const unsigned int index, const T &value)
        {
            assert(index < size);
            data[index] = value;
        }

        /**
         * @brief add value to coordinate i
         *
         * @param index
         * @param value
         */
        inline void add(const unsigned int index, const T value)
        {
            assert(index < size);
            data[index] += value;
        }

        /**
         * @brief add two datapoints
         *
         * @param other_datapoint
         * @return t_datapoint<T, N>
         */
        inline t_datapoint<T, N> operator+(const t_datapoint<T, N> &other_datapoint) const
        {
            t_datapoint<T, N> sum;
            for (int i = N - 1; i >= 0; --i)
            {
                sum.data[i] = data[i] + other_datapoint.data[i];
            }
            return sum;
        }

        /**
         * @brief subtracte two datapoints
         *
         * @param other_datapoint
         * @return t_datapoint<T, N>
         */
        inline t_datapoint<T, N> operator-(const t_datapoint<T, N> &other_datapoint) const
        {
            t_datapoint<T, N> difference;
            for (int i = N - 1; i >= 0; --i)
            {
                difference.data[i] = data[i] - other_datapoint.data[i];
            }
            return difference;
        }

#ifdef SUPPORT_MATRIX_SUBTRACTION_FROM_DATAPOINT

        /**
         * @brief subtracte matrix<1,N> from datapoint
         *
         * @param other_datapoint
         * @return t_datapoint<T, N>
         */
        inline Matrix<1, N, T> operator-(const Matrix<1, N, T> &matrix) const
        {
            Matrix<1, N, T> difference;
            for (int i = N - 1; i >= 0; --i)
            {
                difference.data[i] = data[i] - matrix.data[i];
            }
            return difference;
        }

#endif

        /**
         * @brief return as the same data type
         * 
         * @return t_datapoint<T, N> 
         */
        inline t_datapoint<T, N> to() const
        {
            return data;
        }

        /**
         * @brief cast result to a different datatype
         * 
         * @tparam M 
         * @return t_datapoint<M, N> 
         */
        template <typename M>
        inline t_datapoint<M, N> to() const
        {
            t_datapoint<M, N> x;
            for (int i = N - 1; i >= 0; --i)
            {
                x.data[i] = static_cast<M>(data[i]);
            }
            return x;
        }

        /**
         * @brief concatenate two datapoints of the same type
         *
         * @param other_datapoint
         * @return t_datapoint<T, N+M>
         */
        template <unsigned int M>
        inline t_datapoint<T, N + M> operator&(const t_datapoint<T, M> &other_datapoint) const
        {
            t_datapoint<T, N + M> cat;
#if 1
            memcpy(cat.data, data, sizeof(T) * N);
            memcpy(cat.data + N, other_datapoint.data, sizeof(T) * M);
#else
            unsigned int i, k;
            for (i = 0, k = 0; i < N; ++i)
            {
                cat.data[k++] = data[i];
            }
            for (i = 0; i < M; ++i)
            {
                cat.data[k++] = other_datapoint.data[i];
            }
#endif
            return cat;
        }

        /**
         * @brief Compare two datapoints for equality
         *
         * @param other_datapoint
         * @return true on equality
         * @return false on inequality
         */
        bool operator==(const t_datapoint<T, N> &other_datapoint) const
        {
#if 1
            return !memcmp(data, other_datapoint.data, sizeof(T) * N);
#else
            for (unsigned int i = 0; i < N; i++)
            {
                if (data[i] != other_datapoint.data[i])
                {
                    return false;
                }
            }
            return true;
#endif
        }

        /**
         * @brief Compare two datapoints for inequality
         *
         * @param other_datapoint
         * @return true on inequality
         * @return false on equality
         */

        bool operator!=(const t_datapoint<T, N> &other_datapoint) const
        {
#if 1
            return memcmp(data, other_datapoint.data, sizeof(T) * N);
#else
            return !(this->operator==(other_datapoint));
#endif
        }

        /**
         * @brief Copy operator
         *        Copy data from another point
         *
         * @param other_datapoint an other datapoint
         */
        void operator=(const t_datapoint<T, N> &other_datapoint)
        {
#ifdef ATMONSAT_USE_MEMCPY
            memcpy(data, other_datapoint.data, N * sizeof(T));
#else
            for (unsigned int i = 0; i < N; ++i)
            {
                data[i] = other_datapoint.data[i];
            }
#endif
        }

        /**
         * @brief << stream operator
         *
         * @param os
         * @param m
         * @return std::ostream&
         */

#ifdef ATMONSAT_DATAPOINT_SUPPORT_IOSTREAM
        friend std::ostream &operator<<(std::ostream &os, const t_datapoint<T, N> &point)
        {
            os << "dp(";
            for (unsigned int i = 0; i < N; ++i)
            {
                if (i != 0)
                {
                    os << ", ";
                }
                os << (unsigned int)point.data[i];
            }
            os << ")";

            return os;
        }
#endif
    };

}
#endif
