ft download 4 10 0 1200 -out data\20220216T111000\epsgeneraltelemetry.dat
delay 0
parser data\20220216T111000\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220216T111000\epsgeneraltelemetry.csv
delay 0
