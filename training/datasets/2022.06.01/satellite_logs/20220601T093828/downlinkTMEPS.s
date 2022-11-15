ft download 4 10 -p 500 124 -out data\20220601T093828\epsgeneraltelemetry.dat
delay 0
parser data\20220601T093828\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220601T093828\epsgeneraltelemetry.csv
delay 0
