/******************************************************************************/
/* Copyright   : SCSK Corporation                                             */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_Cbk.c                                                    */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator 2019.12 (Java)                          */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_Type.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/
VAR(DistanceGroup_t, AUTOMATIC) DistanceGroup;

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
FUNC(void, RTE_CODE) Rte_COMCbk_ComISignal_RP_DistanceUS(void) {
    //Copy the received signal group from the I-PDU to the shadow buffer.
    VAR(void, AUTOMATIC)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_ComISignal_HS_CAN1_Distance);

    //Copy the data of the signal from the shadow buffer to the referenced position
    VAR(void, AUTOMATIC)Com_ReceiveSignal(ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S0, &DistanceGroup.Distance_S1);
    VAR(void, AUTOMATIC)Com_ReceiveSignal(ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S1, &DistanceGroup.Distance_S1);
    VAR(void, AUTOMATIC)Com_ReceiveSignal(ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S2, &DistanceGroup.Distance_S3);
    VAR(void, AUTOMATIC)Com_ReceiveSignal(ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S3, &DistanceGroup.Distance_S4);

    //Set event CE_DistanceDataReceived
    VAR(void, AUTOMATIC)SetEvent(DistanceAlarmTask, OS_CE_DistanceDataReceived);
}
