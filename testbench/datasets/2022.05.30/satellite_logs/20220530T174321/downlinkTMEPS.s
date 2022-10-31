ft download 4 10 0 1240 -out data\20220530T174321\epsgeneraltelemetry.dat
delay 0
parser data\20220530T174321\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220530T174321\epsgeneraltelemetry.csv
delay 0
