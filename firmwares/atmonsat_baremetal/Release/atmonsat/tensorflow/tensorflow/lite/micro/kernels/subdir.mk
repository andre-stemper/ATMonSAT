################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_n.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/arg_min_max.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/assign_variable.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/batch_to_space_nd.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_args.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_to.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/call_once.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/cast.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/ceil.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/comparisons.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/concatenation.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/conv_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/cumsum.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/depth_to_space.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/depthwise_conv_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/detection_postprocess.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/div.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/elementwise.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/elu.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/ethosu.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/exp.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/expand_dims.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/fill.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_div.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_mod.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/fully_connected_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather_nd.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/if.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_runner.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_util.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2_pool_2d.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2norm.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/log_softmax.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/lstm_eval.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/maximum_minimum.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/micro_tensor_utils.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/mirror_pad.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/mul_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/neg.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/pack.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/pad.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/pooling_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/read_variable.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/reshape.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_bilinear.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_nearest_neighbor.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/round.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/select.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/shape.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/slice.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/softmax_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_batch_nd.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_depth.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/split.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/split_v.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/squared_difference.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/squeeze.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/strided_slice.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/svdf_common.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/tanh.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose_conv.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/unidirectional_sequence_lstm.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/unpack.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/var_handle.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/while.cc \
../atmonsat/tensorflow/tensorflow/lite/micro/kernels/zeros_like.cc 

CC_DEPS += \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_n.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/arg_min_max.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/assign_variable.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/batch_to_space_nd.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_args.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_to.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/call_once.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/cast.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/ceil.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/comparisons.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/concatenation.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/conv_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/cumsum.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/depth_to_space.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/depthwise_conv_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/detection_postprocess.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/div.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/elementwise.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/elu.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/ethosu.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/exp.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/expand_dims.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/fill.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_div.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_mod.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/fully_connected_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather_nd.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/if.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_runner.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_util.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2_pool_2d.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2norm.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/log_softmax.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/lstm_eval.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/maximum_minimum.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/micro_tensor_utils.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/mirror_pad.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/mul_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/neg.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pack.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pad.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pooling_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/read_variable.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reshape.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_bilinear.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_nearest_neighbor.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/round.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/select.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/shape.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/slice.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/softmax_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_batch_nd.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_depth.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/split.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/split_v.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/squared_difference.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/squeeze.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/strided_slice.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/svdf_common.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/tanh.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose_conv.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/unidirectional_sequence_lstm.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/unpack.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/var_handle.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/while.d \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/zeros_like.d 

OBJS += \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_n.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/arg_min_max.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/assign_variable.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/batch_to_space_nd.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_args.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_to.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/call_once.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/cast.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/ceil.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/comparisons.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/concatenation.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/conv_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/cumsum.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/depth_to_space.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/depthwise_conv_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/detection_postprocess.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/div.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/elementwise.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/elu.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/ethosu.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/exp.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/expand_dims.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/fill.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_div.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_mod.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/fully_connected_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather_nd.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/if.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_runner.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_util.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2_pool_2d.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2norm.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/log_softmax.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/lstm_eval.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/maximum_minimum.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/micro_tensor_utils.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/mirror_pad.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/mul_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/neg.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pack.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pad.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pooling_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/read_variable.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reshape.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_bilinear.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_nearest_neighbor.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/round.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/select.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/shape.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/slice.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/softmax_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_batch_nd.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_depth.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/split.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/split_v.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/squared_difference.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/squeeze.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/strided_slice.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/svdf_common.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/tanh.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose_conv.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/unidirectional_sequence_lstm.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/unpack.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/var_handle.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/while.o \
./atmonsat/tensorflow/tensorflow/lite/micro/kernels/zeros_like.o 


# Each subdirectory must supply rules for building sources it contributes
atmonsat/tensorflow/tensorflow/lite/micro/kernels/%.o atmonsat/tensorflow/tensorflow/lite/micro/kernels/%.su: ../atmonsat/tensorflow/tensorflow/lite/micro/kernels/%.cc atmonsat/tensorflow/tensorflow/lite/micro/kernels/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -DUSE_HAL_DRIVER -D__ARM_FEATURE_DSP=1 '-DCMSIS_DEVICE_ARM_CORTEX_M_XX_HEADER_FILE="stm32h743xx.h"' -DARMCM7 -DTF_LITE_DISABLE_X86_NEON -DTF_LITE_STATIC_MEMORY -DARMCM7 -DCMSIS_NN=1 -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/flatbuffers/include" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/gemmlowp" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/ruy" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/kissfft" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis_nn" -I"/home/andre/Workspace/Projects/AtMonSat/release/firmwares/atmonsat_baremetal/atmonsat/tensorflow/third_party/cmsis_nn/Include" -Ofast -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-kernels

clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-kernels:
	-$(RM) ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/activations_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_n.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_n.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/add_n.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/arg_min_max.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/arg_min_max.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/arg_min_max.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/assign_variable.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/assign_variable.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/assign_variable.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/batch_to_space_nd.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/batch_to_space_nd.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/batch_to_space_nd.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_args.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_args.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_args.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_to.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_to.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/broadcast_to.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/call_once.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/call_once.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/call_once.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/cast.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/cast.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/cast.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/ceil.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/ceil.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/ceil.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/circular_buffer_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/comparisons.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/comparisons.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/comparisons.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/concatenation.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/concatenation.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/concatenation.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/conv_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/conv_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/conv_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/cumsum.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/cumsum.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/cumsum.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/depth_to_space.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/depth_to_space.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/depth_to_space.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/depthwise_conv_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/depthwise_conv_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/depthwise_conv_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/dequantize_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/detection_postprocess.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/detection_postprocess.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/detection_postprocess.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/div.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/div.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/div.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/elementwise.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/elementwise.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/elementwise.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/elu.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/elu.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/elu.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/ethosu.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/ethosu.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/ethosu.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/exp.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/exp.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/exp.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/expand_dims.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/expand_dims.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/expand_dims.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/fill.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/fill.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/fill.su
	-$(RM) ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_div.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_div.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_div.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_mod.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_mod.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/floor_mod.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/fully_connected_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/fully_connected_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/fully_connected_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather_nd.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather_nd.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/gather_nd.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/hard_swish_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/if.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/if.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/if.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_runner.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_runner.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_runner.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_util.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_util.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/kernel_util.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2_pool_2d.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2_pool_2d.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2_pool_2d.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2norm.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2norm.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/l2norm.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/leaky_relu_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/log_softmax.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/log_softmax.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/log_softmax.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logical_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/logistic_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/lstm_eval.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/lstm_eval.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/lstm_eval.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/maximum_minimum.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/maximum_minimum.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/maximum_minimum.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/micro_tensor_utils.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/micro_tensor_utils.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/micro_tensor_utils.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/mirror_pad.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/mirror_pad.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/mirror_pad.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/mul_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/mul_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/mul_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/neg.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/neg.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/neg.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pack.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pack.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pack.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pad.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pad.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pad.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pooling_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pooling_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/pooling_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu_common.d
	-$(RM) ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/prelu_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/quantize_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/read_variable.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/read_variable.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/read_variable.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reduce_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reshape.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reshape.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/reshape.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_bilinear.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_bilinear.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_bilinear.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_nearest_neighbor.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_nearest_neighbor.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/resize_nearest_neighbor.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/round.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/round.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/round.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/select.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/select.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/select.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/shape.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/shape.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/shape.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/slice.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/slice.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/slice.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/softmax_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/softmax_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/softmax_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_batch_nd.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_batch_nd.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_batch_nd.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_depth.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_depth.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/space_to_depth.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/split.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/split.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/split.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/split_v.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/split_v.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/split_v.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/squared_difference.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/squared_difference.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/squared_difference.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/squeeze.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/squeeze.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/squeeze.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/strided_slice.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/strided_slice.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/strided_slice.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/sub_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/svdf_common.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/svdf_common.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/svdf_common.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/tanh.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/tanh.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/tanh.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose_conv.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose_conv.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/transpose_conv.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/unidirectional_sequence_lstm.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/unidirectional_sequence_lstm.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/unidirectional_sequence_lstm.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/unpack.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/unpack.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/unpack.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/var_handle.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/var_handle.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/var_handle.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/while.d
	-$(RM) ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/while.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/while.su ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/zeros_like.d ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/zeros_like.o ./atmonsat/tensorflow/tensorflow/lite/micro/kernels/zeros_like.su

.PHONY: clean-atmonsat-2f-tensorflow-2f-tensorflow-2f-lite-2f-micro-2f-kernels

