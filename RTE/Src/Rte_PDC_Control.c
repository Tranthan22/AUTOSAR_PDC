#include "Rte_PDC_Control.h"

static VAR(void, AUTOMATIC) Distance_S1;
static VAR(void, AUTOMATIC) Distance_S2;
static VAR(void, AUTOMATIC) Distance_S3;
static VAR(void, AUTOMATIC) Distance_S4;

VAR(Com_SignalGroupIdType, AUTOMATIC) DistanceGroup;

FUNC(void, RTE_CODE_EcucPartition_0) Rte_COMCbk_RP_DistanceUS(void) {

    VAR(void, AUTOMATIC)Com_ReceiveSignalGroup(DistanceGroup);

    VAR(void, AUTOMATIC)Com_ReceiveSignal(signal_Fold, &angle_Fold); //check lại

    VAR(void, AUTOMATIC)SetEvent(DistanceAlarmTask, OS_CE_DistanceDataReceived);
}