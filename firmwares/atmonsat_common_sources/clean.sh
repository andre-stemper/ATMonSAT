#!/usr/bin/bash

ATMONSAT_COMMON_NOTEBOOKS=(atmonsat_model_quantize.ipynb)

# copy cleaning notebook
JUPYTER=$(which jupyter)
for notebook in ${ATMONSAT_COMMON_NOTEBOOKS[@]}; do
    echo "cleaning notebook '${notebook}'"
    ${JUPYTER} nbconvert --clear-output --inplace ${notebook}
done

if [ -e "calibration_tensor.npy" ]; then
    echo "removing calibration tensor"
    rm "calibration_tensor.npy"
fi