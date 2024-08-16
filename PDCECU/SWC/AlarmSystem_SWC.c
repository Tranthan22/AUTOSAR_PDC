/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : AlarmSystem_SWC.c                                            */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

#include "Rte_AlarmSystem.h"


FUNC(void, AppAlarm_CODE) ExecuteAlarmCommand( VAR(void, AUTOMATIC) )
{
    AlarmLevel_uint8_t AlarmLevel = 0;
    Rte_Call_WdgMCheckpointReached(SE3_ID,CP_ID_5);                     // Start checkpoint Deadline SE3
    
    /* Read data from PDC control */
	Rte_Read_R_RP_Alarm_ReadAlarmLevel(&AlarmLevel);                         
    
    // Perform alarm
    Rte_Call_R_IO_WarningAlarm(AlarmLevel);
    
	Rte_Call_WdgMCheckpointReached(SE4_ID,CP_ID_8);                     // End checkpoint Deadline SE4
    Rte_Call_WdgMCheckpointReached(SE3_ID,CP_ID_6);                     // End checkpoint Deadline SE3

    return;
}