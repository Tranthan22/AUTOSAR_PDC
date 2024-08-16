/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_AlarmSystem.h                                            */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
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
extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_AlarmWarning( VAR(AlarmLevel_uint8_t, AUTOMATIC) );

/*******************************************************************************/
/* Name        : Rte_Call_AlarmSystem_R_IO_WarningAlarm                        */
/* Param       : VAR(AlarmLevel_uint8_t, AUTOMATIC)                            */
/* Return      : FUNC(Std_ReturnType, RTE_CODE)                                */
/* Contents    : The `Rte_Call_AlarmSystem_R_IO_WarningAlarm` function is used */
/*               to trigger an alarm warning in the system,passing the         */
/*               provided alarm level as a parameter. The result of the        */
/*               operation is returned, indicating whether the alarm was       */
/*               successfully triggered or if an error occurred.               */
/* Note        :                                                               */
/*******************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AlarmSystem_R_IO_WarningAlarm( VAR(AlarmLevel_uint8_t, AUTOMATIC) data) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_AlarmWarning( data );
    return return_value;
}


/*******************************************************************************/
/* Name        : Rte_Read_AlarmSystem_R_RP_Alarm_ReadAlarmLevel                */
/* Param       : P2VAR(AlarmSystem_uint8, AUTOMATIC, RTE_APPL_DATA) alarm_level*/
/* Return      : FUNC(Std_ReturnType, RTE_CODE)                                */
/* Contents    : Reads the current alarm level and returns the status of the   */
/*               operation.                                                    */
/* Note        :                                                               */
/*******************************************************************************/
VAR(AlarmLevel_uint8_t, AUTOMATIC) Rte_Read_AlarmSystem_AlarmLevel_Value;
VAR(Std_ReturnType, AUTOMATIC) Rte_Read_AlarmSystem_AlarmLevel_status = RTE_E_NEVER_RECEIVED;

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AlarmSystem_R_RP_Alarm_ReadAlarmLevel( P2VAR(AlarmSystem_uint8, AUTOMATIC, RTE_APPL_DATA) alarm_level ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    *data = Rte_Read_AlarmSystem_AlarmLevel_Value;
    ret_val = Rte_Read_AlarmSystem_AlarmLevel_status;
    RTE_Q_UNLOCK();

    return ret_val;
}



extern FUNC(void, AppAlarm_CODE) ExecuteAlarmCommand( VAR(void, AUTOMATIC) );

/*******************************************************************************/
/* Name        : Rte_ExecuteAlarmCommand                                       */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      :                                                               */
/* Contents    :                                                               */
/* Note        :                                                               */
/*******************************************************************************/
FUNC(void, RTE_CODE) Rte_ExecuteAlarmCommand( VAR(void, AUTOMATIC) ) {

    ExecuteAlarmCommand();

}