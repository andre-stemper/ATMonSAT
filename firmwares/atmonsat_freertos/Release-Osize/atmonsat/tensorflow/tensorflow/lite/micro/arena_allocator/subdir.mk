################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.cc 

CC_DEPS += \
./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.d \
./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.d \
./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.d \
./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.d 

OBJS += \
./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.o \
./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.o \
./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.o \
./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.o 


# Each subdirectory must supply rules for building sources it contributes
atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/%.o atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/%.su: ../atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/%.cc atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -D__ARM_FEATURE_DSP=1 '-DCMSIS_DEVICE_ARM_CORTEX_M_XX_HEADER_FILE="stm32h743xx.h"' -DARMCM7 -DTF_LITE_DISABLE_X86_NEON -DTF_LITE_STATIC_MEMORY -DARMCM7 -DCMSIS_NN=1 -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/flatbuffers/include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/gemmlowp" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/ruy" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/kissfft" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis/CMSIS/DSP/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis" -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-arena_allocator

clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-arena_allocator:
	-$(RM) ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.d ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.o ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/non_persistent_arena_buffer_allocator.su ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.d ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.o ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/persistent_arena_buffer_allocator.su ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.d ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.o ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/recording_single_arena_buffer_allocator.su ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.d ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.o ./atmonsat/tensorflow/tensorflow/lite/micro/arena_allocator/single_arena_buffer_allocator.su

.PHONY: clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-arena_allocator

