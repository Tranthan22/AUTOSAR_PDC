/******************************************************************************/
/* Copyright   : GROUP 3 Corporation                                          */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_AlarmSystem.h                                                */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Nguyen Ngoc                                                    */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_ALARM_H
#define RTE_ALARM_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AlarmSystem_R_IO_WarningAlarm( VAR(AlarmSystem_IoHwAb_AlarmLevel, AUTOMATIC) value);
#define Rte_Call_R_IO_WarningAlarm Rte_Call_AlarmSystem_R_IO_WarningAlarm

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AlarmSystem_R_RP_Alarm_ReadAlarmLevel( VAR(AlarmSystem_uint8, AUTOMATIC, RTE_APPL_DATA) value );
#define Rte_Read_R_RP_Alarm_ReadAlarmLevel Rte_Read_AlarmSystem_R_RP_Alarm_ReadAlarmLevel

#define AppAlarm_START_SEC_CODE
#include "AppAlarm_MemMap.h"
FUNC(void, AUTOMATIC) ExecuteAlarmCommand( VAR(void, AUTOMATIC) );
#define AppAlarm_STOP_SEC_CODE
#define RTE_RUNNABLE_Run_ExecuteAlarmCommand ExecuteAlarmCommand





#endif /* RTE_ALARM_H */

/* End of Rte_AlarmSystem.h */