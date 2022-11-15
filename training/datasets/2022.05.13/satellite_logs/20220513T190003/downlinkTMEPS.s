ft download 4 10 0 1240 -out data\20220513T190003\epsgeneraltelemetry.dat
delay 0
parser data\20220513T190003\epsgeneraltelemetry.dat ..\telemetryDecodingStructures\4_EPSGeneralTelemetry.c data\20220513T190003\epsgeneraltelemetry.csv
delay 0
