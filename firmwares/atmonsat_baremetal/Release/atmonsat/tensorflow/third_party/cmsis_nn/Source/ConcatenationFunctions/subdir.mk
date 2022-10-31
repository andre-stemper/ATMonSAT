################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.c \
../atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.c \
../atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.c \
../atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.c 

C_DEPS += \
./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.d \
./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.d \
./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.d \
./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.d 

OBJS += \
./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.o \
./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.o \
./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.o \
./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.o 


# Each subdirectory must supply rules for building sources it contributes
atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/%.o atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/%.su: ../atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/%.c atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -D__ARM_FEATURE_DSP=1 '-DCMSIS_DEVICE_ARM_CORTEX_M_XX_HEADER_FILE="stm32h743xx.h"' -DARMCM7 -DTF_LITE_DISABLE_X86_NEON -DTF_LITE_STATIC_MEMORY -DARMCM7 -DCMSIS_NN=1 -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/flatbuffers/include" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/gemmlowp" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/ruy" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/kissfft" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis_nn" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis_nn/Include" -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-atmonsat-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-ConcatenationFunctions

clean-atmonsat-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-ConcatenationFunctions:
	-$(RM) ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.d ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.o ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_w.su ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.d ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.o ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_x.su ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.d ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.o ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_y.su ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.d ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.o ./atmonsat/tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/arm_concatenation_s8_z.su

.PHONY: clean-atmonsat-2f-tensorflow-2f-third_party-2f-cmsis_nn-2f-Source-2f-ConcatenationFunctions

