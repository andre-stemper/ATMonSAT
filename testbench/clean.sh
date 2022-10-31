#!/usr/bin/bash

ATMONSAT_TESTBENCH_NOTEBOOKS=(atmonsat_testbench.ipynb
    dataset.ipynb
    postprocessing.ipynb
    postprocessing_aggregate_experiments_grid.ipynb
    postprocessing_render_experiment_plots.ipynb
    postprocessing_aggregate.ipynb
    postprocessing_calculate_power.ipynb
    postprocessing_validate_measurements.ipynb
    protocol.ipynb
)

ATMONSAT_TESSTBENCH_RESULTS_DIRECTORY=./results

# clean results directory
if [ -d "${ATMONSAT_TESSTBENCH_RESULTS_DIRECTORY}/" ]; then
    rm -r ${ATMONSAT_TESSTBENCH_RESULTS_DIRECTORY}/*
fi

rm ./atmonsat_testbench.txt

# copy cleaning notebook
JUPYTER=$(which jupyter)
for notebook in ${ATMONSAT_TESTBENCH_NOTEBOOKS[@]}; do
    echo "cleaning notebook '${notebook}'"
    ${JUPYTER} nbconvert --clear-output --inplace ${notebook}
done
