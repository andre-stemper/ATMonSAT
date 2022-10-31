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

#ifndef __PROTOCOL_DATALINK_STM32_H__
#define __PROTOCOL_DATALINK_STM32_H__

#include <cstdint>
#include "atmonsat.h"
#include "protocol.h"
#include "protocol_datalink.h"

#define PROTOCOL_DATALINK_STM32_USART_RECEPTION_TIMEOUT 250
#define PROTOCOL_DATALINK_STM32_USART_TRANSMISSION_TIMEOUT 250

namespace atmonsat
{
    class ProtocolDatalinkSTM32USART : public DataLink
    {
    public:
        ProtocolDatalinkSTM32USART(){};
        bool done() override { return false; };
        ipr_t input(uint8_t *byte, bool blocking = false) override;
        ipr_t output(uint8_t byte) override;
    };
}

#endif
