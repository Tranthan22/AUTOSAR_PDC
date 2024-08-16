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
extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_AlarmWarning( VAR(AlarmLevel_uint8_t, AUTOMATIC) );

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AlarmSystem_R_IO_WarningAlarm( VAR(AlarmLevel_uint8_t, AUTOMATIC) data) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_AlarmWarning( data );
    return return_value;
}


/******************************************************************************/

/******************************************************************************/
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


/**********************************  Section 2 ******************************* */
extern FUNC(void, RTE_CODE) ExecuteAlarmCommand( VAR(void, AUTOMATIC) );

FUNC(void, RTE_CODE) Rte_ExecuteAlarmCommand( VAR(void, AUTOMATIC) ) {

    ExecuteAlarmCommand();

}