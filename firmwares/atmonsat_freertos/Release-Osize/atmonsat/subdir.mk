################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../atmonsat/atmonsat_anomaly_detection.cc \
../atmonsat/atmonsat_model.cc \
../atmonsat/atmonsat_testbench.cc \
../atmonsat/main_stm32.cc \
../atmonsat/protocol_datalink_stm32_usart.cc \
../atmonsat/time_metric_stm32.cc 

CC_DEPS += \
./atmonsat/atmonsat_anomaly_detection.d \
./atmonsat/atmonsat_model.d \
./atmonsat/atmonsat_testbench.d \
./atmonsat/main_stm32.d \
./atmonsat/protocol_datalink_stm32_usart.d \
./atmonsat/time_metric_stm32.d 

OBJS += \
./atmonsat/atmonsat_anomaly_detection.o \
./atmonsat/atmonsat_model.o \
./atmonsat/atmonsat_testbench.o \
./atmonsat/main_stm32.o \
./atmonsat/protocol_datalink_stm32_usart.o \
./atmonsat/time_metric_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
atmonsat/%.o atmonsat/%.su: ../atmonsat/%.cc atmonsat/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -D__ARM_FEATURE_DSP=1 '-DCMSIS_DEVICE_ARM_CORTEX_M_XX_HEADER_FILE="stm32h743xx.h"' -DARMCM7 -DTF_LITE_DISABLE_X86_NEON -DTF_LITE_STATIC_MEMORY -DARMCM7 -DCMSIS_NN=1 -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/flatbuffers/include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/gemmlowp" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/ruy" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/kissfft" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis/CMSIS/DSP/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis" -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-atmonsat

clean-atmonsat:
	-$(RM) ./atmonsat/atmonsat_anomaly_detection.d ./atmonsat/atmonsat_anomaly_detection.o ./atmonsat/atmonsat_anomaly_detection.su ./atmonsat/atmonsat_model.d ./atmonsat/atmonsat_model.o ./atmonsat/atmonsat_model.su ./atmonsat/atmonsat_testbench.d ./atmonsat/atmonsat_testbench.o ./atmonsat/atmonsat_testbench.su ./atmonsat/main_stm32.d ./atmonsat/main_stm32.o ./atmonsat/main_stm32.su ./atmonsat/protocol_datalink_stm32_usart.d ./atmonsat/protocol_datalink_stm32_usart.o ./atmonsat/protocol_datalink_stm32_usart.su ./atmonsat/time_metric_stm32.d ./atmonsat/time_metric_stm32.o ./atmonsat/time_metric_stm32.su

.PHONY: clean-atmonsat

