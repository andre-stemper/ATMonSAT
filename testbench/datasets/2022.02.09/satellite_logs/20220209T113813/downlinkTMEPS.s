ft download 4 10 0 500 -out data\20220209T113813\epsgeneraltelemetry.dat
delay 0
parser data\20220209T113813\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220209T113813\epsgeneraltelemetry.csv
delay 0
