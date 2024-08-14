#include "UltrasonicSensor_SWC.h"


FUNC(void, AppSensor_CODE) MeasureDistance( VAR(void, AUTOMATIC) )
{
	static uint8[4] distance = 0;
    /* Read data from 4 sensors */
    for(uint8_t id = 0; i < 4; i++)
    {
        Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_1);                                 // Start checkpoint Deadline SE1
	    Rte_Call_R_IO_GetDistance(id , distance[i]);
        Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_2);                                 // End checkpoint Deadline SE
    }
	Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_0);                                     // Alive SE
    
    // Send through port PP_DistanceUS

    return;	
}

FUNC(void, AppSensor_CODE) WarningAlarm(VAR(void, AUTOMATIC))
{
    
}