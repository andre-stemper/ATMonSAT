ft download 4 10 -p 50000 124 -out data\20220601T094434\epsgeneraltelemetry.dat
delay 0
parser data\20220601T094434\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220601T094434\epsgeneraltelemetry.csv
delay 0
