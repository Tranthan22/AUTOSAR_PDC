/******************************************************************************/
/* Copyright   : Group 3 Corporation                                          */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_PDC_Control.c                                              */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Ngoc Nguyen                                                    */
/* Note        :                                                              */
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_PDC_Control.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/
static VAR(USSensor_uint8, AUTOMATIC) Distance_S0;
static VAR(USSensor_uint8, AUTOMATIC) Distance_S1;
static VAR(USSensor_uint8, AUTOMATIC) Distance_S2;
static VAR(USSensor_uint8, AUTOMATIC) Distance_S3;


/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
FUNC(void, RTE_CODE_EcucPartition_0) Rte_COMCbk_RP_DistanceUS(void) {

    //Copy the data of the signal to the referenced position
    VAR(void, AUTOMATIC)Com_ReceiveSignal(, &Distance_S1);
    VAR(void, AUTOMATIC)Com_ReceiveSignal(, &Distance_S2);
    VAR(void, AUTOMATIC)Com_ReceiveSignal(, &Distance_S3);
    VAR(void, AUTOMATIC)Com_ReceiveSignal(, &Distance_S4);

    //Set event CE_DistanceDataReceived
    VAR(void, AUTOMATIC)SetEvent(DistanceAlarmTask, OS_CE_DistanceDataReceived);
}

/******************************************************************************/
/*
*/
/******************************************************************************/

VAR(Std_ReturnType, AUTOMATIC) Rte_Read_AppUSSensor_Value_status = RTE_E_NEVER_RECEIVED;

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S0( P2VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distanceUS0 ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    *distanceUS0 = Distance_S0;
    ret_val = Rte_Read_AppUSSensor_Value_status;
    RTE_Q_UNLOCK();

    return ret_val;
} 


FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S1( P2VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distanceUS1 ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    *distanceUS1 = Distance_S1;
    ret_val = Rte_Read_AppUSSensor_Value_status;
    RTE_Q_UNLOCK();

    return ret_val;
}

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S2( P2VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distanceUS3 ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    *distanceUS2 = Distance_S2;
    ret_val = Rte_Read_AppUSSensor_Value_status;
    RTE_Q_UNLOCK();

    return ret_val;
}

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S3( P2VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distanceUS4 ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    *distanceUS3 = Distance_S3;
    ret_val = Rte_Read_AppUSSensor_Value_status;
    RTE_Q_UNLOCK();

    return ret_val;
}
/******************************************************************************/
/*
*/
/******************************************************************************/


FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_ParkDistanceControl_P_PP_Alarm_SendDistancetoAlarm( VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distance_to_alarm ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(AUTOSAR_uint8, AUTOMATIC) tmp_data = data;

    ret = Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_DistanceUS, &tmp_data );
    switch( ret ) {
    case COM_SERVICE_NOT_AVAILABLE:
        ret_val = RTE_E_COM_STOPPED;
        break;
    case COM_BUSY:
        ret_val = RTE_E_COM_BUSY;
        break;
    default:
        /* nothing */
        break;
    }

    return ret_val;
}


/**********************************  Section 2 ******************************* */
extern FUNC(void, AppAlarm_CODE) ProcessControl( VAR(void, AUTOMATIC) );

FUNC(void, RTE_CODE_EcucPartition_0) Rte_ProcessControl( VAR(void, AUTOMATIC) ) {

    ProcessControl();

}