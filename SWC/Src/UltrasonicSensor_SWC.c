#include "UltrasonicSensor_SWC.h"


FUNC(void, AppSensor_CODE) MeasureDistance( VAR(void, AUTOMATIC) )
{
	static uint8[4] distance = 0;
    /* Read data from 4 sensors */
    for(uint8_t id = 0; i < NUM_OF_SENSOR; id++)
    {
        Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_1);                                 // Start checkpoint Deadline SE1
	    Rte_Call_R_IO_GetDistance(id , distance[id]);
        Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_2);                                 // End checkpoint Deadline SE1
    }
    Rte_Write_P_PP_DistanceUS_SendDistance_S1(distance[SENSOR_ID_0]);
    Rte_Write_P_PP_DistanceUS_SendDistance_S2(distance[SENSOR_ID_1]);
    Rte_Write_P_PP_DistanceUS_SendDistance_S3(distance[SENSOR_ID_2]);
    Rte_Write_P_PP_DistanceUS_SendDistance_S4(distance[SENSOR_ID_3]);
	Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_0);                                     // Alive SE1

    return;	
}