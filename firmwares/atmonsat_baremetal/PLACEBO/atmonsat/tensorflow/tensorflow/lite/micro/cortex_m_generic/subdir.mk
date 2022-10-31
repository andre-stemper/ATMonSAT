################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../atmonsat/tensorflow/tensorflow/lite/micro/cortex_m_generic/micro_time.cc 

CC_DEPS += \
./atmonsat/tensorflow/tensorflow/lite/micro/cortex_m_generic/micro_time.d 

OBJS += \
./atmonsat/tensorflow/tensorflow/lite/micro/cortex_m_generic/micro_time.o 


# Each subdirectory must supply rules for building sources it contributes
atmonsat/tensorflow/tensorflow/lite/micro/cortex_m_generic/%.o atmonsat/tensorflow/tensorflow/lite/micro/cortex_m_generic/%.su: ../atmonsat/tensorflow/tensorflow/lite/micro/cortex_m_generic/%.cc atmonsat/tensorflow/tensorflow/lite/micro/cortex_m_generic/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -D__ARM_FEATURE_DSP=1 '-DCMSIS_DEVICE_ARM_CORTEX_M_XX_HEADER_FILE="stm32h743xx.h"' -DARMCM7 -DTF_LITE_DISABLE_X86_NEON -DTF_LITE_STATIC_MEMORY -DCMSIS_NN=1 -DSTM32H743xx -DPLACEBO=1 -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/flatbuffers/include" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/gemmlowp" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/ruy" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/kissfft" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis_nn/Include" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis_nn" -Ofast -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-cortex_m_generic

clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-cortex_m_generic:
	-$(RM) ./atmonsat/tensorflow/tensorflow/lite/micro/cortex_m_generic/micro_time.d ./atmonsat/tensorflow/tensorflow/lite/micro/cortex_m_generic/micro_time.o ./atmonsat/tensorflow/tensorflow/lite/micro/cortex_m_generic/micro_time.su

.PHONY: clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-cortex_m_generic

