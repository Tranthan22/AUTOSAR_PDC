#include "UltrasonicSensor_SWC.h"


FUNC(void, AppAlarm_CODE) ExecuteAlarmCommand( VAR(void, AUTOMATIC) )
{
	static uint8 alarm_level = 0;
    /* Read data from PDC control */

	Rte_Read_R_RP_Alarm_ReadAlarmLevel(alarm_level);                         
    
    // Receiver  through port RP_Alarm

    return;	
}