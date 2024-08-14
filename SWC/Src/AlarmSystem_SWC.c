#include "Rte_AlarmSystem.h"


FUNC(void, Alarm_CODE) ExecuteAlarmCommand( VAR(void, AUTOMATIC) )
{
	static uint8 alarm_level = 0;

    Rte_Call_WdgMCheckpointReached(SE3_ID,CP_ID_5);                     // Start checkpoint Deadline SE3
    
    /* Read data from PDC control */
	Rte_Read_R_RP_Alarm_ReadAlarmLevel(alarm_level);                         
    
    // Receiver  through port RP_Alarm

	Rte_Call_WdgMCheckpointReached(SE4_ID,CP_ID_8);                     // End checkpoint Deadline SE4
    Rte_Call_WdgMCheckpointReached(SE3_ID,CP_ID_6);                     // End checkpoint Deadline SE3

    return;
}