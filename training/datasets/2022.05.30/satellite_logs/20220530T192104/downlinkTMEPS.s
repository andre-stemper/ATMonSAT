ft download 4 10 0 1240 -out data\20220530T192104\epsgeneraltelemetry.dat
delay 0
parser data\20220530T192104\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220530T192104\epsgeneraltelemetry.csv
delay 0