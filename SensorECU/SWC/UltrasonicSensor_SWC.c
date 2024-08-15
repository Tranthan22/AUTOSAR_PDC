#include "UltrasonicSensor_SWC.h"

FUNC(void, RTE_CODE) MeasureDistance( VAR(void, AUTOMATIC) )
{
	DistanceGroup_t Distance;

    /* Read data from 4 sensors */
    Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_1);                                 // Start checkpoint Deadline SE1
    
    Rte_Call_R_IO_IO_GetDistance_S0(&Distance.Distance_S0);
    Rte_Call_R_IO_IO_GetDistance_S1(&Distance.Distance_S1);
    Rte_Call_R_IO_IO_GetDistance_S2(&Distance.Distance_S2);
    Rte_Call_R_IO_IO_GetDistance_S3(&Distance.Distance_S3);

    Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_2);                                 // End checkpoint Deadline SE1
    
    /* Send to PDCECU */
    Rte_Write_P_PP_DistanceUS_SendDistance(Distance);
	
    Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_0);                                     // Alive SE1
}

