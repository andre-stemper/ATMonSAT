#!/usr/bin/env bash

TENSORFLOW_LITE_MICRO_GITHUB_URL=https://github.com/tensorflow/tflite-micro.git
TENSORFLOW_LITE_MICRO_COMMIT_ID=63510bb55e143987656ae3400c2463bdfc276c55
TENSORFLOW_LITE_MICRO_DIRECTORY=tflite-micro

CURRENT_WORKING_DIRECTORY=$(pwd)

HOW_TO_MESSAGE=

case "$1" in
native)
    ATMONSAT_CONFIG=native
    ATMONSAT_FIRMWARE_ROOT=${CURRENT_WORKING_DIRECTORY}/atmonsat_${ATMONSAT_CONFIG}
    ATMONSAT_TARGET_DIRECTORY=./atmonsat_native
    ATMONSAT_SOURCE_DIRECTORY=./atmonsat_common_sources
    #
    ATMONSAT_TARGET=
    ATMONSAT_TARGET_ARCH=
    ATMONSAT_OPTIONS=
    #
    TENSORFLOW_DIRECTORY=${CURRENT_WORKING_DIRECTORY}/3dparty/tensorflow
    TENSORFLOW_DISTILLED_DIRECTORY=${ATMONSAT_FIRMWARE_ROOT}/tensorflow
    TENSORFLOW_GENERATE_DIRECTORY=${CURRENT_WORKING_DIRECTORY}/3dparty/tensorflow/generate/${ATMONSAT_CONFIG}
    #
    ATMONSAT_DATA=(atmonsat_model.h5
        atmonsat_model_quantize.ipynb
        calibration_tensor.npy)
    #
    ATMONSAT_CC_SOURCES=(atmonsat_anomaly_detection.cc
        atmonsat_model.cc
        atmonsat_testbench.cc
        main_native.cc
        protocol_datalink_pipe.cc
        time_metric_native.cc)
    #
    ATMONSAT_CC_HEADERS=(atmonsat.h
        atmonsat_testbench.h
        atmonsat_anomaly_detection.h
        atmonsat_mahalanobis_precalculated_values.h
        atmonsat_mahalanobis_precalculated_threshold.h
        atmonsat_model.h
        islcc.h
        datapoint.h
        mahalanobis.h
        matrix.h
        main_native.h
        datawindow.h
        threshold.h
        islcc_interpolator.h
        linear_interpolation.h
        protocol.h
        protocol_definitions.h
        protocol_datalink.h
        protocol_datalink_pipe.h
        time_metric.h
        time_metric_native.h)
    #
    declare -A ATMONSAT_COPY_INSIDE_TARET=(  )
    declare -A ATMONSAT_MOVE_INSIDE_TARGET=(  )
    #
    ATMONSAT_REMOVE=(${TENSORFLOW_DISTILLED_DIRECTORY}/tensorflow/lite/micro/debug_log.cc)
    HOW_TO_MESSAGE=to compile change to ./atmonsat_native directory and run make
    ;;

clean-native)
    rm -f -r ./atmonsat_native/
    exit 0
    ;;

baremetal)
    ATMONSAT_CONFIG=baremetal
    ATMONSAT_FIRMWARE_ROOT=${CURRENT_WORKING_DIRECTORY}/atmonsat_${ATMONSAT_CONFIG}
    ATMONSAT_TARGET_DIRECTORY=./atmonsat_baremetal/atmonsat
    ATMONSAT_SOURCE_DIRECTORY=./atmonsat_common_sources
    #
    ATMONSAT_TARGET=TARGET=cortex_m_generic
    ATMONSAT_TARGET_ARCH=TARGET_ARCH=cortex-m7+fp
    ATMONSAT_OPTIONS=OPTIMIZED_KERNEL_DIR=cmsis_nn
    #
    TENSORFLOW_DIRECTORY=${CURRENT_WORKING_DIRECTORY}/3dparty/tensorflow
    TENSORFLOW_DISTILLED_DIRECTORY=${ATMONSAT_FIRMWARE_ROOT}/atmonsat/tensorflow
    TENSORFLOW_GENERATE_DIRECTORY=${CURRENT_WORKING_DIRECTORY}/3dparty/tensorflow/generate/${ATMONSAT_CONFIG}
    #
    ATMONSAT_DATA=(atmonsat_model.h5
        atmonsat_model_quantize.ipynb
        calibration_tensor.npy)
    #
    ATMONSAT_CC_SOURCES=(
        atmonsat_anomaly_detection.cc
        atmonsat_model.cc
        atmonsat_testbench.cc
        protocol_datalink_stm32_usart.cc
        time_metric_stm32.cc
        main_stm32.cc)
    #
    ATMONSAT_CC_HEADERS=(atmonsat.h
        atmonsat_testbench.h
        atmonsat_anomaly_detection.h
        atmonsat_mahalanobis_precalculated_values.h
        atmonsat_mahalanobis_precalculated_threshold.h
        atmonsat_model.h
        mahalanobis.h
        islcc.h
        datapoint.h
        matrix.h
        datawindow.h
        threshold.h
        islcc_interpolator.h
        linear_interpolation.h
        protocol.h
        protocol_definitions.h
        protocol_datalink.h
        protocol_datalink_stm32_usart.h
        time_metric.h
        time_metric_stm32.h
        main_stm32.h)
    #
    ATMONSAT_REMOVE=(${TENSORFLOW_DISTILLED_DIRECTORY}/tensorflow/lite/micro/cortex_m_generic/debug_log.cc)
    #
    declare -A ATMONSAT_COPY_INSIDE_TARET=( [atmonsat/tensorflow/third_party/cmsis/CMSIS/Core/Include/cmsis_gcc.h]=Drivers/CMSIS/Include/cmsis_gcc.h )
    declare -A ATMONSAT_MOVE_INSIDE_TARGET=(  )
    HOW_TO_MESSAGE=to build import the atmonsat_baremetal project into STM32CubeIDE and build.
    ;;

clean-baremetal)
    rm -f -r ./atmonsat_baremetal/atmonsat/
    exit 0
    ;;

baremetal-generic)
    ATMONSAT_CONFIG=baremetal
    ATMONSAT_FIRMWARE_ROOT=${CURRENT_WORKING_DIRECTORY}/atmonsat_${ATMONSAT_CONFIG}
    ATMONSAT_TARGET_DIRECTORY=./atmonsat_baremetal/atmonsat
    ATMONSAT_SOURCE_DIRECTORY=./atmonsat_common_sources
    #
    ATMONSAT_TARGET=
    ATMONSAT_TARGET_ARCH=
    ATMONSAT_OPTIONS=
    #
    TENSORFLOW_DIRECTORY=${CURRENT_WORKING_DIRECTORY}/3dparty/tensorflow
    TENSORFLOW_DISTILLED_DIRECTORY=${ATMONSAT_FIRMWARE_ROOT}/atmonsat/tensorflow
    TENSORFLOW_GENERATE_DIRECTORY=${CURRENT_WORKING_DIRECTORY}/3dparty/tensorflow/generate/${ATMONSAT_CONFIG}
    #
    ATMONSAT_DATA=(atmonsat_model.h5
        atmonsat_model_quantize.ipynb
        calibration_tensor.npy)
    #
    ATMONSAT_CC_SOURCES=(
        atmonsat_anomaly_detection.cc
        atmonsat_model.cc
        atmonsat_testbench.cc
        protocol_datalink_stm32_usart.cc
        time_metric_stm32.cc
        main_stm32.cc)
    #
    ATMONSAT_CC_HEADERS=(atmonsat.h
        atmonsat_testbench.h
        atmonsat_anomaly_detection.h
        atmonsat_mahalanobis_precalculated_values.h
        atmonsat_mahalanobis_precalculated_threshold.h
        atmonsat_model.h
        mahalanobis.h
        islcc.h
        datapoint.h
        matrix.h
        datawindow.h
        threshold.h
        islcc_interpolator.h
        linear_interpolation.h
        protocol.h
        protocol_definitions.h
        protocol_datalink.h
        protocol_datalink_stm32_usart.h
        time_metric.h
        time_metric_stm32.h
        main_stm32.h)
    #
    declare -A ATMONSAT_COPY_INSIDE_TARET=(  )
    declare -A ATMONSAT_MOVE_INSIDE_TARGET=(  )
    #
    ATMONSAT_REMOVE=(${TENSORFLOW_DISTILLED_DIRECTORY}/tensorflow/lite/micro/debug_log.cc)
    ;;

clean-baremetal-generic)
    rm -f -r ./atmonsat_baremetal/atmonsat/
    exit 0
    ;;

freertos)
    ATMONSAT_CONFIG=freertos
    ATMONSAT_FIRMWARE_ROOT=${CURRENT_WORKING_DIRECTORY}/atmonsat_${ATMONSAT_CONFIG}
    ATMONSAT_TARGET_DIRECTORY=./atmonsat_freertos/atmonsat
    ATMONSAT_SOURCE_DIRECTORY=./atmonsat_common_sources
    #
    ATMONSAT_TARGET=TARGET=cortex_m_generic
    ATMONSAT_TARGET_ARCH=TARGET_ARCH=cortex-m7+fp
    ATMONSAT_OPTIONS=OPTIMIZED_KERNEL_DIR=cmsis_nn
    #
    TENSORFLOW_DIRECTORY=${CURRENT_WORKING_DIRECTORY}/3dparty/tensorflow
    TENSORFLOW_DISTILLED_DIRECTORY=${ATMONSAT_FIRMWARE_ROOT}/atmonsat/tensorflow
    TENSORFLOW_GENERATE_DIRECTORY=${CURRENT_WORKING_DIRECTORY}/3dparty/tensorflow/generate/${ATMONSAT_CONFIG}
    #
    ATMONSAT_DATA=(atmonsat_model.h5
        atmonsat_model_quantize.ipynb
        calibration_tensor.npy)
    #
    ATMONSAT_CC_SOURCES=(
        atmonsat_anomaly_detection.cc
        atmonsat_model.cc
        atmonsat_testbench.cc
        protocol_datalink_stm32_usart.cc
        time_metric_stm32_freertos.cc
        main_stm32_freertos.cc)
    #
    ATMONSAT_CC_HEADERS=(atmonsat.h
        atmonsat_testbench.h
        atmonsat_anomaly_detection.h
        atmonsat_mahalanobis_precalculated_values.h
        atmonsat_mahalanobis_precalculated_threshold.h
        atmonsat_model.h
        mahalanobis.h
        islcc.h
        datapoint.h
        matrix.h
        datawindow.h
        threshold.h
        islcc_interpolator.h
        linear_interpolation.h
        protocol.h
        protocol_definitions.h
        protocol_datalink.h
        protocol_datalink_stm32_usart.h
        time_metric.h
        time_metric_stm32_freertos.h
        main_stm32_freertos.h)
    #
    declare -A ATMONSAT_COPY_INSIDE_TARET=( [atmonsat/tensorflow/third_party/cmsis/CMSIS/Core/Include/cmsis_gcc.h]=Drivers/CMSIS/Include/cmsis_gcc.h )
    declare -A ATMONSAT_MOVE_INSIDE_TARGET=(  )
    #
    ATMONSAT_REMOVE=(${TENSORFLOW_DISTILLED_DIRECTORY}/tensorflow/lite/micro/cortex_m_generic/debug_log.cc)
    #
    HOW_TO_MESSAGE=to build import the atmonsat_freertos project into STM32CubeIDE and build.
    ;;

clean-freertos)
    rm -f -r ./atmonsat_freertos/atmonsat/
    exit 0
    ;;

clean-3dparty)
    rm -f -r ./3dparty
    exit 0
    ;;

all)
    $0 native
    $0 baremetal
    exit 0
    ;;

clean)
    $0 clean-3dparty
    $0 clean-native
    $0 clean-baremetal
    $0 clean-freertos
    exit 0
    ;;

*)
    echo "command line argument required: all, native, baremetal or freertos"
    exit 1
    ;;
esac

echo "preparing for ${ATMONSAT_CONFIG} firmware."

# uncompress calibration tensor
if [ ! -e "${ATMONSAT_SOURCE_DIRECTORY}/calibration_tensor.npy" ]; then
    echo "unzipping calibration tensor"
    unzip "${ATMONSAT_SOURCE_DIRECTORY}/calibration_tensor.zip" -d "${ATMONSAT_SOURCE_DIRECTORY}"
fi

# clean target directory
if [ -d "${ATMONSAT_TARGET_DIRECTORY}/" ]; then
    rm -r ${ATMONSAT_TARGET_DIRECTORY}/
fi

# create target directory
mkdir --parents ${ATMONSAT_TARGET_DIRECTORY}

#-- copy files
# copy cc sources
for value in ${ATMONSAT_CC_SOURCES[@]}; do
    echo "copying ${value}"
    cp ${ATMONSAT_SOURCE_DIRECTORY}/${value} ${ATMONSAT_TARGET_DIRECTORY}
done

# copy cc headers
for value in ${ATMONSAT_CC_HEADERS[@]}; do
    echo "copying ${value}"
    cp ${ATMONSAT_SOURCE_DIRECTORY}/${value} ${ATMONSAT_TARGET_DIRECTORY}
done

# copy data
for value in ${ATMONSAT_DATA[@]}; do
    echo "copying ${value}"
    cp -r ${ATMONSAT_SOURCE_DIRECTORY}/${value} ${ATMONSAT_TARGET_DIRECTORY}
done

# copy makefile
cp ${ATMONSAT_SOURCE_DIRECTORY}/Makefile.native ${ATMONSAT_TARGET_DIRECTORY}/Makefile

#-- prepare tensorflow lite micro
# clean target location
if [ -d "${TENSORFLOW_DISTILLED_DIRECTORY}/" ]; then
    rm -r ${TENSORFLOW_DISTILLED_DIRECTORY}/
fi

# prepare directories
mkdir --parents ${TENSORFLOW_DIRECTORY}
mkdir --parents ${TENSORFLOW_DISTILLED_DIRECTORY}
mkdir --parents ${TENSORFLOW_GENERATE_DIRECTORY}

# clone tensorflow lite micro from github
cd ${TENSORFLOW_DIRECTORY}
if [ ! -d "./{TENSORFLOW_LITE_MICRO_DIRECTORY}" ]; then
    echo "cloning tensorflow lite micro from ${TENSORFLOW_LITE_MICRO_GITHUB_URL}"
    git clone --recursive ${TENSORFLOW_LITE_MICRO_GITHUB_URL}
    if [ $? -eq 1 ]; then
        echo "failed to clone tf lite micro. aborting"
        exit 1
    fi
fi

# change into tf lite micro directory
cd ${TENSORFLOW_LITE_MICRO_DIRECTORY}

# checkout commit
while true; do
    echo "--"
    echo "this release has been tested with tensorflow lite micro commit"
    echo "${TENSORFLOW_LITE_MICRO_COMMIT_ID}"
    echo "do you want to checkout this commit or try the newest release?"
    read -p "[t(his)| m(ain) | b(ash for manual checkout)]" answer
    case $answer in
        # the specified commit 
        [Tt]* ) 
            git checkout ${TENSORFLOW_LITE_MICRO_COMMIT_ID}
            if [ $? -eq 1 ]; then
                echo "failed to checkout commit id. aborting"
                exit 1
            fi
            break ;;
        # the head
        [Mm]* ) 
            git checkout main
            if [ $? -eq 1 ]; then
                echo "failed to branch. aborting"
                exit 1
            fi
            break ;;
        # open a bash shell an checkout manually
        [Bb]* ) 
            git status
            echo "---"
            echo "checkout example:"
            echo "git checkout -b atmonsat ${TENSORFLOW_LITE_MICRO_COMMIT_ID}"
            echo ""
            echo "when done type 'exit' <enter> to continue"
            echo "---"
            bash -c "exec bash"
            break ;; 
        * ) echo "answer not supported.";;
    esac
done

# generate one of the tf lite micro examples
echo "preparing tensorflow lite micro"
EXAMPLE=hello_world
make -f tensorflow/lite/micro/tools/make/Makefile ${ATMONSAT_TARGET} ${ATMONSAT_TARGET_ARCH} ${ATMONSAT_OPTIONS} microlite
if [ $? -eq 1 ]; then
    echo "aborting"
    exit 1
fi

# create tflm tree 
python3 tensorflow/lite/micro/tools/project_generation/create_tflm_tree.py --makefile_options="${ATMONSAT_TARGET} ${ATMONSAT_TARGET_ARCH} ${ATMONSAT_OPTIONS}" --examples ${EXAMPLE} ${TENSORFLOW_GENERATE_DIRECTORY}/
if [ $? -eq 1 ]; then
    echo "aborting"
    exit 1
fi

# copy the required files to the specified firmwares
echo "copying required tensorflow lite micro files"
cd ${CURRENT_WORKING_DIRECTORY}
cp -r ${TENSORFLOW_GENERATE_DIRECTORY}/third_party ${TENSORFLOW_DISTILLED_DIRECTORY}/
cp -r ${TENSORFLOW_GENERATE_DIRECTORY}/tensorflow ${TENSORFLOW_DISTILLED_DIRECTORY}/
cp ${TENSORFLOW_GENERATE_DIRECTORY}/LICENSE ${TENSORFLOW_DISTILLED_DIRECTORY}/

for FROM in "${!ATMONSAT_COPY_INSIDE_TARET[@]}"; do
    TO=${ATMONSAT_COPY_INSIDE_TARET[${FROM}]}
    if [ -e "${ATMONSAT_FIRMWARE_ROOT}/${FROM}" ] 
    then
        echo copying ${ATMONSAT_FIRMWARE_ROOT}/${FROM} to ${ATMONSAT_FIRMWARE_ROOT}/${TO}
        cp ${ATMONSAT_FIRMWARE_ROOT}/${FROM} ${ATMONSAT_FIRMWARE_ROOT}/${TO}
    else 
        echo missing ${ATMONSAT_FIRMWARE_ROOT}/${FROM}
    fi
done

for FROM in "${!ATMONSAT_MOVE_INSIDE_TARGET[@]}"; do
    TO=${ATMONSAT_MOVE_INSIDE_TARGET[${FROM}]}
    if [ -e "${ATMONSAT_FIRMWARE_ROOT}/${FROM}" ] 
    then
        echo moving ${ATMONSAT_FIRMWARE_ROOT}/${FROM} to ${ATMONSAT_FIRMWARE_ROOT}/${TO}
        mv ${ATMONSAT_FIRMWARE_ROOT}/${FROM} ${ATMONSAT_FIRMWARE_ROOT}/${TO}
    else 
        echo missing ${ATMONSAT_FIRMWARE_ROOT}/${FROM}
    fi
done

# remove some unnecessary files
for value in ${ATMONSAT_REMOVE[@]}; do
    if [ -e "${value}" ]; then
        echo "removing file ${value}"
        rm ${value}
    fi
done

echo "all files collected in ${ATMONSAT_TARGET_DIRECTORY}"
echo "${HOW_TO_MESSAGE}"
exit 0
