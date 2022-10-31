################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../atmonsat/tensorflow/third_party/kissfft/kiss_fft.c 

C_DEPS += \
./atmonsat/tensorflow/third_party/kissfft/kiss_fft.d 

OBJS += \
./atmonsat/tensorflow/third_party/kissfft/kiss_fft.o 


# Each subdirectory must supply rules for building sources it contributes
atmonsat/tensorflow/third_party/kissfft/%.o atmonsat/tensorflow/third_party/kissfft/%.su: ../atmonsat/tensorflow/third_party/kissfft/%.c atmonsat/tensorflow/third_party/kissfft/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -D__ARM_FEATURE_DSP=1 '-DCMSIS_DEVICE_ARM_CORTEX_M_XX_HEADER_FILE="stm32h743xx.h"' -DARMCM7 -DTF_LITE_DISABLE_X86_NEON -DTF_LITE_STATIC_MEMORY -DCMSIS_NN=1 -DSTM32H743xx -DPLACEBO=1 -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/flatbuffers/include" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/gemmlowp" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/ruy" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/kissfft" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis_nn/Include" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis_nn" -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-atmonsat-2f-tensorflow-2f-third_party-2f-kissfft

clean-atmonsat-2f-tensorflow-2f-third_party-2f-kissfft:
	-$(RM) ./atmonsat/tensorflow/third_party/kissfft/kiss_fft.d ./atmonsat/tensorflow/third_party/kissfft/kiss_fft.o ./atmonsat/tensorflow/third_party/kissfft/kiss_fft.su

.PHONY: clean-atmonsat-2f-tensorflow-2f-third_party-2f-kissfft

