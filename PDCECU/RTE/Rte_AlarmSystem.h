/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_AlarmSystem.h                                            */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_ALARM_H
#define RTE_ALARM_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_Type.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AlarmSystem_R_IO_WarningAlarm( VAR(AlarmLevel_uint8_t, AUTOMATIC) data);
#define Rte_Call_R_IO_WarningAlarm Rte_Call_AlarmSystem_R_IO_WarningAlarm

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AlarmSystem_R_RP_Alarm_ReadAlarmLevel( P2VAR(AlarmLevel_uint8_t, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_R_RP_Alarm_ReadAlarmLevel Rte_Read_AlarmSystem_R_RP_Alarm_ReadAlarmLevel

FUNC(void, AppAlarm_CODE) ExecuteAlarmCommand( VAR(void, AUTOMATIC) );
#define RTE_RUNNABLE_Run_ExecuteAlarmCommand ExecuteAlarmCommand



#endif /* RTE_ALARM_H */

/* End of Rte_AlarmSystem.h */