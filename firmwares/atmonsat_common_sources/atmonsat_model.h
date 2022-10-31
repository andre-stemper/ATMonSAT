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

#ifndef __ATMONSAT_MODEL_H__
#define __ATMONSAT_MODEL_H__

#include <cstdint>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Quantized tensorflow lite model size in bytes
 */
extern const uint32_t atmonsat_model_size;

/**
 * @brief Quantized tensorflow lite model
 */
extern const uint8_t atmonsat_model[];

#ifdef __cplusplus
}
#endif

#endif