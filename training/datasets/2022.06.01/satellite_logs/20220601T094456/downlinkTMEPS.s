ft download 4 10 -p 15000 124 -out data\20220601T094456\epsgeneraltelemetry.dat
delay 0
parser data\20220601T094456\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220601T094456\epsgeneraltelemetry.csv
delay 0
