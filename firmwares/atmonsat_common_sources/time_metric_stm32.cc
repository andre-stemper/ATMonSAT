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
#include <cstdint>
#include <time.h>

#include "time_metric_stm32.h"
#include "stm32h7xx_hal.h"

using namespace atmonsat;
using namespace std;

namespace atmonsat
{
	/**
	 * @brief construct a new STM32H743 time metric object
	 *
	 */
	TimeMetricSTM32::TimeMetricSTM32()
	{
		zero();
	}

	/**
	 * @brief Initialize timer 2
	 * 4Mhz x 149/2 => core 299Mhz/4 => APB2 74.75Mhz
	 * APB2 74.75MHz 74750000
	 * prescaler: 7475 => 100uHz
	 * period 10000 => 1Hz10000
	 *
	 * 298Mhz /2
	 * 8Mhz x74/2 => core 298Mhz /1/2 => APB2 149Mhz
	 * APB2 149Mhz 149000000Hz
	 * prescaler 149 => 1uHz
	 *
	 */

	void TimeMetricSTM32::initialize()
	{
		/* Initialize TIM2 (32bit timer) */
		TIM_ClockConfigTypeDef sClockSourceConfig = {0};
		TIM_MasterConfigTypeDef sMasterConfig = {0};
		htim2.Instance = TIM2;
		htim2.Init.Prescaler = TIME_METRIC_PRESCALER; /* => us */
		htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
#ifdef TIME_METRIC_STM32_TEST_TIMING
		htim2.Init.Period = 1000000; /* ticks / second */
#else
		htim2.Init.Period = 4294967295;
#endif
		htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
#ifdef TIME_METRIC_STM32_TEST_TIMING
		htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
#else
		htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
#endif

		if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
		{
			__disable_irq();
			while (1)
				;
		}
		sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
		if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
		{
			__disable_irq();
			while (1)
				;
		}
		sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
		sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
		if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
		{
			__disable_irq();
			while (1)
				;
		}
#ifdef TIME_METRIC_STM32_TEST_TIMING
		__enable_irq();
#endif
	}

	/**
	 * @brief zero duration
	 *
	 */
	void TimeMetricSTM32::zero()
	{
		_accumulated_time = 0;
	}

	/**
	 * @brief start / resume timer
	 *
	 */
	void TimeMetricSTM32::start()
	{
		htim2.Instance->CNT = 0;
#ifdef TIME_METRIC_STM32_TEST_TIMING
		HAL_TIM_Base_Start_IT(&htim2);
#else
		HAL_TIM_Base_Start(&htim2);
#endif
	}

	/**
	 * @brief stop / pause timer
	 *
	 */
	void TimeMetricSTM32::stop()
	{
#ifdef TIME_METRIC_STM32_TEST_TIMING
		HAL_TIM_Base_Stop_IT(&htim2);
#else
		HAL_TIM_Base_Stop(&htim2);
#endif
		_accumulated_time = _accumulated_time + (htim2.Instance->CNT) * TIME_METRIC_STM32_NANOSECONDS_PER_TICK;
	}

	/**
	 * @brief get accumulated duration in nanoseconds
	 *
	 * @return t_time
	 */
	t_time TimeMetricSTM32::duration(void)
	{
		return _accumulated_time;
	}
}
