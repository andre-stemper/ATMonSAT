ft download 4 10 0 5 -out data\20220520T085619\epsgeneraltelemetry.dat
delay 0
parser data\20220520T085619\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220520T085619\epsgeneraltelemetry.csv
delay 0
