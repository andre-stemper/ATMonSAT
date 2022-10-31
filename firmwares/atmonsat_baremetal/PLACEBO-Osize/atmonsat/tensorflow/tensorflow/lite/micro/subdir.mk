################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../atmonsat/tensorflow/tensorflow/lite/micro/all_ops_resolver.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/fake_micro_context.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/flatbuffer_utils.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/memory_helpers.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/micro_allocation_info.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/micro_allocator.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/micro_context.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/micro_error_reporter.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/micro_graph.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/micro_interpreter.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/micro_log.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/micro_profiler.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/micro_resource_variable.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/micro_string.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/micro_utils.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/mock_micro_graph.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/recording_micro_allocator.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/system_setup.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/test_helper_custom_ops.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/test_helpers.cc 

CC_DEPS += \
./atmonsat/tensorflow/tensorflow/lite/micro/all_ops_resolver.d \
./atmonsat/tensorflow/tensorflow/lite/micro/fake_micro_context.d \
./atmonsat/tensorflow/tensorflow/lite/micro/flatbuffer_utils.d \
./atmonsat/tensorflow/tensorflow/lite/micro/memory_helpers.d \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_allocation_info.d \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_allocator.d \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_context.d \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_error_reporter.d \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_graph.d \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_interpreter.d \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_log.d \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_profiler.d \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_resource_variable.d \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_string.d \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_utils.d \
./atmonsat/tensorflow/tensorflow/lite/micro/mock_micro_graph.d \
./atmonsat/tensorflow/tensorflow/lite/micro/recording_micro_allocator.d \
./atmonsat/tensorflow/tensorflow/lite/micro/system_setup.d \
./atmonsat/tensorflow/tensorflow/lite/micro/test_helper_custom_ops.d \
./atmonsat/tensorflow/tensorflow/lite/micro/test_helpers.d 

OBJS += \
./atmonsat/tensorflow/tensorflow/lite/micro/all_ops_resolver.o \
./atmonsat/tensorflow/tensorflow/lite/micro/fake_micro_context.o \
./atmonsat/tensorflow/tensorflow/lite/micro/flatbuffer_utils.o \
./atmonsat/tensorflow/tensorflow/lite/micro/memory_helpers.o \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_allocation_info.o \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_allocator.o \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_context.o \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_error_reporter.o \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_graph.o \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_interpreter.o \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_log.o \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_profiler.o \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_resource_variable.o \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_string.o \
./atmonsat/tensorflow/tensorflow/lite/micro/micro_utils.o \
./atmonsat/tensorflow/tensorflow/lite/micro/mock_micro_graph.o \
./atmonsat/tensorflow/tensorflow/lite/micro/recording_micro_allocator.o \
./atmonsat/tensorflow/tensorflow/lite/micro/system_setup.o \
./atmonsat/tensorflow/tensorflow/lite/micro/test_helper_custom_ops.o \
./atmonsat/tensorflow/tensorflow/lite/micro/test_helpers.o 


# Each subdirectory must supply rules for building sources it contributes
atmonsat/tensorflow/tensorflow/lite/micro/%.o atmonsat/tensorflow/tensorflow/lite/micro/%.su: ../atmonsat/tensorflow/tensorflow/lite/micro/%.cc atmonsat/tensorflow/tensorflow/lite/micro/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -D__ARM_FEATURE_DSP=1 '-DCMSIS_DEVICE_ARM_CORTEX_M_XX_HEADER_FILE="stm32h743xx.h"' -DARMCM7 -DTF_LITE_DISABLE_X86_NEON -DTF_LITE_STATIC_MEMORY -DCMSIS_NN=1 -DSTM32H743xx -DPLACEBO=1 -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_baremetal/atmonsat" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_baremetal/atmonsat/tensorflow/third_party/flatbuffers/include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_baremetal/atmonsat/tensorflow/third_party/gemmlowp" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_baremetal/atmonsat/tensorflow/third_party/ruy" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_baremetal/atmonsat/tensorflow" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_baremetal/atmonsat/tensorflow/third_party/kissfft" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis/CMSIS/NN/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis/CMSIS/DSP/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/andre/STM32CubeIDE/workspace_1.7.0/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis" -Os -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro

clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro:
	-$(RM) ./atmonsat/tensorflow/tensorflow/lite/micro/all_ops_resolver.d ./atmonsat/tensorflow/tensorflow/lite/micro/all_ops_resolver.o ./atmonsat/tensorflow/tensorflow/lite/micro/all_ops_resolver.su ./atmonsat/tensorflow/tensorflow/lite/micro/fake_micro_context.d ./atmonsat/tensorflow/tensorflow/lite/micro/fake_micro_context.o ./atmonsat/tensorflow/tensorflow/lite/micro/fake_micro_context.su ./atmonsat/tensorflow/tensorflow/lite/micro/flatbuffer_utils.d ./atmonsat/tensorflow/tensorflow/lite/micro/flatbuffer_utils.o ./atmonsat/tensorflow/tensorflow/lite/micro/flatbuffer_utils.su ./atmonsat/tensorflow/tensorflow/lite/micro/memory_helpers.d ./atmonsat/tensorflow/tensorflow/lite/micro/memory_helpers.o ./atmonsat/tensorflow/tensorflow/lite/micro/memory_helpers.su ./atmonsat/tensorflow/tensorflow/lite/micro/micro_allocation_info.d ./atmonsat/tensorflow/tensorflow/lite/micro/micro_allocation_info.o ./atmonsat/tensorflow/tensorflow/lite/micro/micro_allocation_info.su ./atmonsat/tensorflow/tensorflow/lite/micro/micro_allocator.d ./atmonsat/tensorflow/tensorflow/lite/micro/micro_allocator.o ./atmonsat/tensorflow/tensorflow/lite/micro/micro_allocator.su ./atmonsat/tensorflow/tensorflow/lite/micro/micro_context.d ./atmonsat/tensorflow/tensorflow/lite/micro/micro_context.o ./atmonsat/tensorflow/tensorflow/lite/micro/micro_context.su ./atmonsat/tensorflow/tensorflow/lite/micro/micro_error_reporter.d ./atmonsat/tensorflow/tensorflow/lite/micro/micro_error_reporter.o ./atmonsat/tensorflow/tensorflow/lite/micro/micro_error_reporter.su ./atmonsat/tensorflow/tensorflow/lite/micro/micro_graph.d ./atmonsat/tensorflow/tensorflow/lite/micro/micro_graph.o ./atmonsat/tensorflow/tensorflow/lite/micro/micro_graph.su ./atmonsat/tensorflow/tensorflow/lite/micro/micro_interpreter.d ./atmonsat/tensorflow/tensorflow/lite/micro/micro_interpreter.o ./atmonsat/tensorflow/tensorflow/lite/micro/micro_interpreter.su ./atmonsat/tensorflow/tensorflow/lite/micro/micro_log.d ./atmonsat/tensorflow/tensorflow/lite/micro/micro_log.o ./atmonsat/tensorflow/tensorflow/lite/micro/micro_log.su ./atmonsat/tensorflow/tensorflow/lite/micro/micro_profiler.d ./atmonsat/tensorflow/tensorflow/lite/micro/micro_profiler.o ./atmonsat/tensorflow/tensorflow/lite/micro/micro_profiler.su ./atmonsat/tensorflow/tensorflow/lite/micro/micro_resource_variable.d ./atmonsat/tensorflow/tensorflow/lite/micro/micro_resource_variable.o ./atmonsat/tensorflow/tensorflow/lite/micro/micro_resource_variable.su ./atmonsat/tensorflow/tensorflow/lite/micro/micro_string.d ./atmonsat/tensorflow/tensorflow/lite/micro/micro_string.o ./atmonsat/tensorflow/tensorflow/lite/micro/micro_string.su ./atmonsat/tensorflow/tensorflow/lite/micro/micro_utils.d ./atmonsat/tensorflow/tensorflow/lite/micro/micro_utils.o ./atmonsat/tensorflow/tensorflow/lite/micro/micro_utils.su ./atmonsat/tensorflow/tensorflow/lite/micro/mock_micro_graph.d ./atmonsat/tensorflow/tensorflow/lite/micro/mock_micro_graph.o ./atmonsat/tensorflow/tensorflow/lite/micro/mock_micro_graph.su ./atmonsat/tensorflow/tensorflow/lite/micro/recording_micro_allocator.d ./atmonsat/tensorflow/tensorflow/lite/micro/recording_micro_allocator.o ./atmonsat/tensorflow/tensorflow/lite/micro/recording_micro_allocator.su ./atmonsat/tensorflow/tensorflow/lite/micro/system_setup.d ./atmonsat/tensorflow/tensorflow/lite/micro/system_setup.o ./atmonsat/tensorflow/tensorflow/lite/micro/system_setup.su ./atmonsat/tensorflow/tensorflow/lite/micro/test_helper_custom_ops.d ./atmonsat/tensorflow/tensorflow/lite/micro/test_helper_custom_ops.o ./atmonsat/tensorflow/tensorflow/lite/micro/test_helper_custom_ops.su ./atmonsat/tensorflow/tensorflow/lite/micro/test_helpers.d ./atmonsat/tensorflow/tensorflow/lite/micro/test_helpers.o ./atmonsat/tensorflow/tensorflow/lite/micro/test_helpers.su

.PHONY: clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro

