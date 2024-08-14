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

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SendAlarmWarning( VAR(AlarmSystem_IoHwAb_AlarmLevel, AUTOMATIC) );


FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AlarmSystem_R_IO_WarningAlarm( VAR(AlarmSystem_IoHwAb_AlarmLevel, AUTOMATIC) alarm_warning) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_SendAlarmWarning( alarm_warning );
    return return_value;
}


/******************************************************************************/
/*
*/
/******************************************************************************/

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_ReadAlarmLevel( VAR(AlarmSystem_uint8, AUTOMATIC, RTE_APPL_DATA) );

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AlarmSystem_R_RP_Alarm_ReadAlarmLevel( VAR(AlarmSystem_uint8, AUTOMATIC, RTE_APPL_DATA) alarm_level ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_Q_SensorGet( alarm_level );
    return return_value;
}


/**********************************  Section 2 ******************************* */
extern FUNC(void, AppAlarm_CODE) ExecuteAlarmCommand( VAR(void, AUTOMATIC) );

FUNC(void, RTE_CODE_EcucPartition_0) Rte_ExecuteAlarmCommand( VAR(void, AUTOMATIC) ) {

    ExecuteAlarmCommand();

}