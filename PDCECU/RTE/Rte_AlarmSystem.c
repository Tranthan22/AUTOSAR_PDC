/******************************************************************************/
/* Copyright   : Group 3 Corporation                                          */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_AlarmSystem.c                                              */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Ngoc Nguyen                                                    */
/* Note        :                                                              */
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_AlarmSystem.h"

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

/******************************************************************************/
VAR(AUTOSAR_uint8, AUTOMATIC) Rte_Read_AlarmSystem_AlarmLevel_Value;
VAR(Std_ReturnType, AUTOMATIC) Rte_Read_AlarmSystem__AlarmLevel_status = RTE_E_NEVER_RECEIVED;

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AlarmSystem_R_RP_Alarm_ReadAlarmLevel( P2VAR(AlarmSystem_uint8, AUTOMATIC, RTE_APPL_DATA) alarm_level ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    *alarm_level = Distance_Group;
    ret_val = Rte_Read_AppPDCControl_Value_status;
    RTE_Q_UNLOCK();

    return ret_val;
}


/**********************************  Section 2 ******************************* */
extern FUNC(void, AppAlarm_CODE) ExecuteAlarmCommand( VAR(void, AUTOMATIC) );

FUNC(void, RTE_CODE_EcucPartition_0) Rte_ExecuteAlarmCommand( VAR(void, AUTOMATIC) ) {

    ExecuteAlarmCommand();

}