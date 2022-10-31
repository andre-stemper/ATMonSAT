ft download 4 10 0 3 -out data\20220530T192044\epsgeneraltelemetry.dat
delay 0
parser data\20220530T192044\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220530T192044\epsgeneraltelemetry.csv
delay 0
