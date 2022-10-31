#ifndef __MAIN_H
#define __MAIN_H

/**
 * During power measurement disable all unnecessary consumers (e.g. leds)
 */
#define POWER_MEASUREMENT

/**
 * Clock profile to use
 * This changes the Core clock, APB2 clock, time metric settings
 */
#define ATMONSAT_CLOCK_PROFILE 298
// #define ATMONSAT_CLOCK_PROFILE 146
// #define ATMONSAT_CLOCK_PROFILE 78
// #define ATMONSAT_CLOCK_PROFILE 39


/* 298 MHz */
#if defined(ATMONSAT_CLOCK_PROFILE) && (ATMONSAT_CLOCK_PROFILE == 298)
#define ATMONSAT_COMMUNICATION_BAUDRATE 3686400; // 3686400, 1843200, 921600, 460800, 115200;
/* 146 MHz */
#elif defined(ATMONSAT_CLOCK_PROFILE) && (ATMONSAT_CLOCK_PROFILE == 146)
#define ATMONSAT_COMMUNICATION_BAUDRATE 1843200; //  3686400, 1843200, 921600, 460800, 115200;
/* 78 MHz*/
#elif defined(ATMONSAT_CLOCK_PROFILE) && (ATMONSAT_CLOCK_PROFILE == 78)
#define ATMONSAT_COMMUNICATION_BAUDRATE 921600; //  3686400, 1843200, 921600, 460800, 115200;
/* 39 MHz */
#elif defined(ATMONSAT_CLOCK_PROFILE) && (ATMONSAT_CLOCK_PROFILE == 39)
#define ATMONSAT_COMMUNICATION_BAUDRATE 460800; //  3686400, 1843200, 921600, 460800, 115200;
#endif



#ifdef __cplusplus
extern "C" {
#endif

#include "stm32h7xx_hal.h"

void Error_Handler(void);

#define LD1_Pin GPIO_PIN_0
#define LD1_GPIO_Port GPIOB
#define LD3_Pin GPIO_PIN_14
#define LD3_GPIO_Port GPIOB
#define STLINK_RX_Pin GPIO_PIN_8
#define STLINK_RX_GPIO_Port GPIOD
#define STLINK_TX_Pin GPIO_PIN_9
#define STLINK_TX_GPIO_Port GPIOD
#define LD2_Pin GPIO_PIN_1
#define LD2_GPIO_Port GPIOE

#ifdef __cplusplus
}
#endif

#endif 
