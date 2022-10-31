ft download 1 10 0 600 -out data\20220209T114721\comgeneraltelemetry.dat
delay 0
parser data\20220209T114721\comgeneraltelemetry.dat ..\telemetryDecodingStructures\1_COMMGeneralTelemetry.c data\20220209T114721\comgeneraltelemetry.csv
delay 0
