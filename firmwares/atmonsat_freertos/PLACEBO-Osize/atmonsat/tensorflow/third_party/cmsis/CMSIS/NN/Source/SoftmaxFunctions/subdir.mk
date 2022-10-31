################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.c \
../atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q15.c \
../atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q7.c \
../atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s16.c \
../atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8.c \
../atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8_s16.c \
../atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_u8.c \
../atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_with_batch_q7.c 

C_DEPS += \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.d \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q15.d \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q7.d \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s16.d \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8.d \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8_s16.d \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_u8.d \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_with_batch_q7.d 

OBJS += \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.o \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q15.o \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q7.o \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s16.o \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8.o \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8_s16.o \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_u8.o \
./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_with_batch_q7.o 


# Each subdirectory must supply rules for building sources it contributes
atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/%.o atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/%.su: ../atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/%.c atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -D__ARM_FEATURE_DSP=1 '-DCMSIS_DEVICE_ARM_CORTEX_M_XX_HEADER_FILE="stm32h743xx.h"' -DARMCM7 -DTF_LITE_DISABLE_X86_NEON -DTF_LITE_STATIC_MEMORY -DCMSIS_NN=1 -DSTM32H743xx -DPLACEBO=1 -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/flatbuffers/include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/gemmlowp" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/ruy" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/kissfft" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis/CMSIS/DSP/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_freertos/atmonsat/tensorflow/third_party/cmsis" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-atmonsat-2f-tensorflow-2f-third_party-2f-cmsis-2f-CMSIS-2f-NN-2f-Source-2f-SoftmaxFunctions

clean-atmonsat-2f-tensorflow-2f-third_party-2f-cmsis-2f-CMSIS-2f-NN-2f-Source-2f-SoftmaxFunctions:
	-$(RM) ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.d ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.o ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_nn_softmax_common_s8.su ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q15.d ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q15.o ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q15.su ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q7.d ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q7.o ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_q7.su ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s16.d ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s16.o ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s16.su ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8.d ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8.o ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8.su ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8_s16.d ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8_s16.o ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_s8_s16.su ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_u8.d ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_u8.o ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_u8.su ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_with_batch_q7.d ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_with_batch_q7.o ./atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Source/SoftmaxFunctions/arm_softmax_with_batch_q7.su

.PHONY: clean-atmonsat-2f-tensorflow-2f-third_party-2f-cmsis-2f-CMSIS-2f-NN-2f-Source-2f-SoftmaxFunctions

