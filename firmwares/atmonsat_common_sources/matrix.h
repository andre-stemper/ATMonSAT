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
 
#ifndef __ATMONSAT_MATRIX_H__
#define __ATMONSAT_MATRIX_H__

#include <iostream>
#include <initializer_list>
#include <cassert>
#include <cmath>

#include "atmonsat.h"
#include "datapoint.h"

#ifdef ATMONSAT_DATAPOINT_SUPPORT_IOSTREAM
#include <iostream>
#endif

using namespace std;
using namespace atmonsat;

namespace atmonsat
{

    /**
     * @brief Matrix structure.
     *
     * @tparam RC t.
     * @tparam CC
     * @tparam T
     */
    template <unsigned RC, unsigned CC, typename T>
    struct Matrix
    {
        static const int rc_ = RC; /*! row count */
        static const int cc_ = CC; /*! column count */

        T data[CC * RC];

        /**
         * @brief Construct a new Matrix object
         *
         * @param l
         */
        Matrix(std::initializer_list<T> l)
        {
            assert(l.size() == RC * CC);
            for (auto i = l.begin(); i != l.end(); ++i)
            {
                data[i - l.begin()] = *i;
            }
        }

        /**
         * @brief Construct a new matrix object
         *
         * @param l
         */
        Matrix(std::initializer_list<std::initializer_list<T>> l)
        {
            assert(l.size() == RC);
            for (auto r = l.begin(); r != l.end(); ++r)
            {
                assert(r->size() == CC);
                for (auto c = r->begin(); c != r->end(); ++c)
                {
                    data[(r - l.begin()) * CC + (c - r->begin())] = *c;
                }
            }
        }

#if 1
        /**
         * @brief Construct a new matrix object from datapoint
         *
         * @tparam DDIM dimensions of datapoint
         * @param datapoint datapoint to copy data from
         */
        template <unsigned int DDIM>
        Matrix(t_datapoint<T, DDIM> datapoint)
        {
            /*assert(DDIM == RC * CC);
            for (unsigned int i=0; i<DDIM; ++i)
            {
                data[i] = datapoint.data[i];
            }*/
            from_datapoint(datapoint);
        }
#endif 

        /**
         * @brief zero matrix
         * 
         */
        void zero(void)
        {
            for (unsigned int i = 0; i < RC * CC; ++i)
            {
                data[i] = static_cast<T>(0);
            }
        }

        /**
         * @brief Construct a new empty matrix object
         *
         */
        Matrix()
        {
        }

        /**
         * @brief get data
         *
         * @return T*
         */
        T *get()
        {
            return data;
        }

        /**
         * @brief set data into field referenced by row, column
         *
         * @param row
         * @param column
         * @param datapoint
         */
        void set(unsigned int row, unsigned int column, T &datapoint)
        {
            assert(row < RC);
            assert(column < CC);
            data[row * CC + column] = datapoint;
        }

        /**
         * @brief set data into field referenced by index
         *
         * @param index
         * @param datapoint
         */
        void set(unsigned int index, T &datapoint)
        {
            assert(index < RC * CC);
            data[index] = datapoint;
        }

        /**
         * @brief display matrix to cout
         *
         */
        void print()
        {
            for (unsigned int i = 0; i < RC; ++i)
            {
                for (unsigned int j = 0; j < CC; ++j)
                {
                    cout << data[i * CC + j] << " ";
                }
                cout << endl;
            }
        }

#ifdef ATMONSAT_MATRIX_SUPPORT_IOSTREAM
        /**
         * @brief stream operator to output matrix
         *
         * @param os stream
         * @param point
         * @return std::ostream&
         */
        friend std::ostream &operator<<(std::ostream &os, const Matrix<RC, CC, T> &matrix)
        {
            for (unsigned int i = 0; i < RC; ++i)
            {
                for (unsigned int j = 0; j < CC; ++j)
                {
                    os << matrix.data[i * CC + j] << " ";
                }
                os << endl;
            }
            return os;
        }
#endif

        /**
         * @brief Addition
         *
         * @tparam CC2
         * @param rhs
         * @return Matrix<RC, CC, T>
         */
        Matrix<RC, CC, T> operator+(const Matrix<RC, CC, T> &rhs)
        {
            Matrix<RC, CC, T> r;

            for (unsigned int j = 0; j < RC; ++j) /* for row in output */
            {
                for (unsigned int i = 0; i < CC; ++i) /* for column in output */
                {
                    r.data[j * CC + i] = data[j * CC + i] + rhs.data[j * CC + i];
                }
            }

            return r;
        }

        /**
         * @brief Subtration
         *
         * @tparam CC2
         * @param rhs
         * @return Matrix<RC, CC, T>
         */
        Matrix<RC, CC, T> operator-(const Matrix<RC, CC, T> &rhs)
        {
            Matrix<RC, CC, T> r;

            for (unsigned int j = 0; j < RC; ++j) /* for row in output */
            {
                for (unsigned int i = 0; i < CC; ++i) /* for column in output */
                {
                    r.data[j * CC + i] = data[j * CC + i] - rhs.data[j * CC + i];
                }
            }

            return r;
        }

        /**
         * @brief Matrix transposition
         *
         * @return Matrix<RC, CC2, T>
         */
        Matrix<CC, RC, T> transpose()
        {
            Matrix<CC, RC, T> r;

            for (unsigned int j = 0; j < RC; ++j)
            {
                for (unsigned int i = 0; i < CC; ++i)
                {
                    r.data[i * RC + j] = data[j * CC + i];
                }
            }

            return r;
        }

        /**
         * @brief Matrix multiplication operation
         *
         * @tparam RC1
         * @tparam CRC12
         * @tparam CC2
         * @tparam T
         * @param lhs
         * @param rhs
         * @return Matrix<RC1, CC2, T>
         */
        template <unsigned CC2>
        Matrix<RC, CC2, T> operator*(const Matrix<CC, CC2, T> &rhs)
        {
            Matrix<RC, CC2, T> r;

            for (unsigned int j = 0; j < RC; ++j) /* for row in output */
            {
                for (unsigned int i = 0; i < CC2; ++i) /* for column in output */
                {
                    T s = T();
                    for (unsigned int k = 0; k < CC; ++k) /* for internal index */
                    {
                        s += data[CC * j + k] * rhs.data[CC2 * k + i];
                    }
                    r.data[j * CC2 + i] = s;
                }
            }

            return r;
        }

        template <unsigned CC2>
        Matrix<RC, CC2, T> transpose_multiply(const Matrix<CC2, CC, T> &rhs)
        {
            Matrix<RC, CC2, T> r;

            for (unsigned int j = 0; j < RC; ++j) /* for every row in output */
            {
                for (unsigned int i = 0; i < CC2; ++i) /* for every column in output */
                {
                    T s = T();
                    for (unsigned int k = 0; k < CC; ++k) /* for internal index */
                    {
                        s += data[CC * j + k] * rhs.data[CC * i + k];
                    }
                    r.data[j * CC2 + i] = s;
                }
            }
            return r;
        }
    };

}

#endif
