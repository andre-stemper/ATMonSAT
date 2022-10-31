# How to build

The AtMonSAT anomaly detection algorithm can be compiled for a PC as well as targeted to a microcontroller (e.g. STM32H743).

Before doing so the source code must be prepared by downloading dependencies and copying some of the source files from the atmonsat_common_sources directory to the correct locations for the different targets. 

## To prepare / compile for Linux (tested on Ubuntu 22.04)
~~~~~
./prepare.sh native
cd atmonsat_native
make
~~~~~

The placebo version (testbed without the anomaly detection algorithm) can be build using 
~~~~~
make PLACEBO=1
~~~~~

To test the binary, go to the testbench directory and load the atmonsat_testbench. 
~~~~~
jupyter notebook atmonsat_testbench.ipynb
~~~~~
Change the connection_type to 'local' to connect to the native implementation using pipes. Then run the notebook.

## To prepare the baremetal implementation for a STM32H743 on a NUCLEO-H743ZI using remote connection

The code must be prepared with 
~~~~~
./prepare.sh baremetal
~~~~~

Building and deployment requires the *[STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)* from *[STMicroelectronics](https://www.st.com/)*

Then in STM32CubeIDE import the firmwares/atmonsat_baremetal project into your workspace and build/run.

To test go to the testbench directory and load the atmonsat_testbench. 
~~~~~
jupyter notebook atmonsat_testbench.ipynb
~~~~~

Change the connection_type='remote' to connect to the native implementation. 
Ensure the development board is connected over USB and run the notebook.

## The freeRTOS implementation
Building the implementation with the freeRTOS kernel follows the same procedure then building the baremetal version.

The main difference is that it has to be prepared with
~~~~~
./prepare.sh freertos
~~~~~

The firmware files can then be found under  firmwares/atmonsat_freertos.
