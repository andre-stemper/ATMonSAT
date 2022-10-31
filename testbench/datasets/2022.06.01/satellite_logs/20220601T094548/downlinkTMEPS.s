ft download 4 10 -once0 124 -out data\20220601T094548\epsgeneraltelemetry.dat
delay 0
parser data\20220601T094548\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220601T094548\epsgeneraltelemetry.csv
delay 0
