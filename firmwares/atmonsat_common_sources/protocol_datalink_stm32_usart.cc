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

#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <fcntl.h>

#include "protocol_datalink_stm32_usart.h"
#include "stm32h7xx_hal.h"

using namespace atmonsat;
using namespace std;

extern UART_HandleTypeDef huart3;

/**
 * @brief input: get one byte
 *
 * @param byte
 * @return ipr_t
 */
ipr_t ProtocolDatalinkSTM32USART::input(uint8_t *byte, bool blocking)
{
	if (blocking)
	{
		while (HAL_UART_Receive(&huart3, byte, 1, PROTOCOL_DATALINK_STM32_USART_RECEPTION_TIMEOUT) != HAL_OK)
			;
		return PROTOCOL_DONE;
	}
	else
	{
		HAL_StatusTypeDef status;
		status = HAL_UART_Receive(&huart3, byte, 1, PROTOCOL_DATALINK_STM32_USART_RECEPTION_TIMEOUT);
		if (status == HAL_OK)
		{
			return PROTOCOL_DONE;
		}
		if (status == HAL_TIMEOUT)
		{
			return PROTOCOL_TIMEOUT;
		}
		return PROTOCOL_ERROR;
	}
}

/**
 * @brief output - emit one byte
 *
 * @param byte
 * @return ipr_t
 */
ipr_t ProtocolDatalinkSTM32USART::output(uint8_t byte)
{
	HAL_UART_Transmit(&huart3, &byte, 1, PROTOCOL_DATALINK_STM32_USART_TRANSMISSION_TIMEOUT);
	return PROTOCOL_DONE;
}
