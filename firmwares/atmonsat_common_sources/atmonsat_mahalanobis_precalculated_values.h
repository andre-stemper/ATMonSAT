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
 
#ifndef __ATMONSAT_MAHALANOBIS_PRECALCULATED_H_
#define __ATMONSAT_MAHALANOBIS_PRECALCULATED_H_

#include <cstdint>
#include "mahalanobis.h"

namespace atmonsat
{
    /**
     * @brief setup precalculated values for calculating mahalanobis distance
     */
    template<unsigned DDIM, typename T>
    void mahalanobis_setup_precalculated_values(Mahalanobis<DDIM, T> &mahalanobis)
    {
        /* mahalanobis distance precalculated mean value */
        mahalanobis.mean = {
            +7.95353270, +11.10413170, -7.32661724, +0.46507657,
            -11.11803913, -2.60292888, -1.33531725, -0.10060628,
            -2.14502859, +1.59808254, +1.39533210, +1.40844417,
            +0.71294290, +0.58751166, +0.65969288, +0.73500240,
            +0.95862436, +0.35387069
        };

        /* mahalanobis distance precalculated inverse covariance */
        mahalanobis.inverse_covariance = {
            +0.00223101, +0.00269355, +0.00147449, +0.00073840,
            -0.00019548, +0.00057878, -0.00040924, -0.00030904,
            +0.00057357, -0.00066785, +0.00224624, -0.00785897,
            +0.00363407, +0.00646867, -0.00155506, -0.00299281,
            -0.00017478, -0.00004541, +0.00269355, +0.00407294,
            +0.00198428, +0.00101984, -0.00031698, +0.00072440,
            -0.00032415, -0.00030834, -0.00014615, -0.00479953,
            +0.00458010, -0.00902575, +0.00481733, +0.00960853,
            -0.00202358, -0.00314205, -0.00087065, -0.00087589,
            +0.00147449, +0.00198428, +0.00134872, +0.00054040,
            -0.00022673, +0.00023667, -0.00008490, -0.00012413,
            +0.00020093, -0.00067108, +0.00069074, -0.00536911,
            +0.00362478, +0.00402192, -0.00274712, -0.00169959,
            +0.00103718, +0.00001329, +0.00073840, +0.00101984,
            +0.00054040, +0.00074788, +0.00011675, +0.00057336,
            -0.00009951, -0.00010909, -0.00005734, +0.00044124,
            +0.00023612, -0.00099271, +0.00081903, +0.00256800,
            -0.00079611, -0.00177180, -0.00216667, +0.00060172,
            -0.00019548, -0.00031698, -0.00022673, +0.00011675,
            +0.00116274, +0.00164969, +0.00042761, +0.00002654,
            +0.00005323, -0.00053326, -0.00181135, +0.00930308,
            -0.00554689, -0.00480254, +0.00331482, +0.00546421,
            -0.00136040, -0.00355385, +0.00057878, +0.00072440,
            +0.00023667, +0.00057336, +0.00164969, +0.00373231,
            +0.00046032, -0.00017734, +0.00016629, -0.00161179,
            -0.00334948, +0.01217021, -0.01046731, -0.00487230,
            +0.00597174, +0.00742177, -0.00117299, -0.00239743,
            -0.00040924, -0.00032415, -0.00008490, -0.00009951,
            +0.00042761, +0.00046032, +0.00376077, -0.00018705,
            -0.00007442, -0.00078888, -0.00272936, +0.00475162,
            +0.00078116, -0.00543684, +0.00028548, +0.00065595,
            +0.00693147, -0.00255607, -0.00030904, -0.00030834,
            -0.00012413, -0.00010909, +0.00002654, -0.00017734,
            -0.00018705, +0.00316893, -0.00026590, -0.00157969,
            -0.00177621, +0.00103008, +0.00292430, +0.00066644,
            -0.00112162, -0.00070294, -0.00241494, +0.00238811,
            +0.00057357, -0.00014615, +0.00020093, -0.00005734,
            +0.00005323, +0.00016629, -0.00007442, -0.00026590,
            +0.00727846, +0.00428253, -0.00053862, -0.00426303,
            +0.00021659, -0.00431958, +0.00108443, -0.00013835,
            +0.00345587, +0.00342213, -0.00066785, -0.00479953,
            -0.00067108, +0.00044124, -0.00053326, -0.00161179,
            -0.00078888, -0.00157969, +0.00428253, +1.55465257,
            -0.88286358, -0.48463520, +0.05978963, +0.26006031,
            +0.04598301, -0.21697517, -0.16158909, -0.19747901,
            +0.00224624, +0.00458010, +0.00069074, +0.00023612,
            -0.00181135, -0.00334948, -0.00272936, -0.00177621,
            -0.00053862, -0.88286358, +1.67739177, -0.41444325,
            -0.21364191, -0.02284520, -0.03427520, -0.00010024,
            -0.08240040, -0.04397962, -0.00785897, -0.00902575,
            -0.00536911, -0.00099271, +0.00930308, +0.01217021,
            +0.00475162, +0.00103008, -0.00426303, -0.48463520,
            -0.41444325, +1.85140109, -0.62096882, -0.00658682,
            -0.00034392, -0.13288616, -0.08360312, -0.14205092,
            +0.00363407, +0.00481733, +0.00362478, +0.00081903,
            -0.00554689, -0.01046731, +0.00078116, +0.00292430,
            +0.00021659, +0.05978963, -0.21364191, -0.62096882,
            +0.94397682, -0.37723473, -0.15517321, +0.18584366,
            +0.22867149, -0.05581168, +0.00646867, +0.00960853,
            +0.00402192, +0.00256800, -0.00480254, -0.00487230,
            -0.00543684, +0.00066644, -0.00431958, +0.26006031,
            -0.02284520, -0.00658682, -0.37723473, +1.69239867,
            -0.91514128, -0.56342441, -0.18768573, +0.12405245,
            -0.00155506, -0.00202358, -0.00274712, -0.00079611,
            +0.00331482, +0.00597174, +0.00028548, -0.00112162,
            +0.00108443, +0.04598301, -0.03427520, -0.00034392,
            -0.15517321, -0.91514128, +2.17318773, -0.46548355,
            -0.30327529, -0.34154135, -0.00299281, -0.00314205,
            -0.00169959, -0.00177180, +0.00546421, +0.00742177,
            +0.00065595, -0.00070294, -0.00013835, -0.21697517,
            -0.00010024, -0.13288616, +0.18584366, -0.56342441,
            -0.46548355, +1.95353901, -0.57949173, -0.15611878,
            -0.00017478, -0.00087065, +0.00103718, -0.00216667,
            -0.00136040, -0.00117299, +0.00693147, -0.00241494,
            +0.00345587, -0.16158909, -0.08240040, -0.08360312,
            +0.22867149, -0.18768573, -0.30327529, -0.57949173,
            +1.65025795, -0.47881234, -0.00004541, -0.00087589,
            +0.00001329, +0.00060172, -0.00355385, -0.00239743,
            -0.00255607, +0.00238811, +0.00342213, -0.19747901,
            -0.04397962, -0.14205092, -0.05581168, +0.12405245,
            -0.34154135, -0.15611878, -0.47881234, +1.40924728
        };
    }
}

#endif