ft download 4 10 0 2 -out data\20220603T085625\epsgeneraltelemetry.dat
delay 0
parser data\20220603T085625\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220603T085625\epsgeneraltelemetry.csv
delay 0
