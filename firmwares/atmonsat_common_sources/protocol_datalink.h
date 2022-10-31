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
 
#ifndef __PROTOCOL_DATALINK_H_
#define __PROTOCOL_DATALINK_H_

#include <cstdint>
#include "protocol_definitions.h"

namespace atmonsat
{
    /**
     * @brief input/output from/to the data link layer
     *
     */
    class DataLink
    {
    public:
        virtual ipr_t input(uint8_t *byte, bool blocking = false) = 0;
        virtual ipr_t output(uint8_t byte) = 0;
        virtual bool done() = 0;
    };
}

#endif
