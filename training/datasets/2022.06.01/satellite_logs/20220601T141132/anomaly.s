ft download 4 10 0 1240 -out data\20220601T141132\epsgeneraltelemetry.dat
delay 0
parser data\20220601T141132\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220601T141132\epsgeneraltelemetry.csv
delay 0
time get 4
remotecli 4 -c 'heater power100 '
remotecli 4 -c 'heater state 1 20'
time get 4
remotecli 4 -c 'heater power100 '
remotecli 4 -c 'heater state 1 20'
