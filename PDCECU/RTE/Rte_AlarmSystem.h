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

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Call_AlarmSystem_R_IO_WarningAlarm( VAR(AlarmLevel_uint8_t, AUTOMATIC) data);
#define Rte_Call_R_IO_WarningAlarm Rte_Call_AlarmSystem_R_IO_WarningAlarm

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_AlarmSystem_R_RP_Alarm_ReadAlarmLevel( P2VAR(AlarmLevel_uint8_t, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_R_RP_Alarm_ReadAlarmLevel Rte_Read_AlarmSystem_R_RP_Alarm_ReadAlarmLevel

FUNC(void, RTE_CODE) ExecuteAlarmCommand( VAR(void, AUTOMATIC) );
#define RTE_RUNNABLE_Run_ExecuteAlarmCommand ExecuteAlarmCommand



#endif /* RTE_ALARM_H */

/* End of Rte_AlarmSystem.h */