#include "UltrasonicSensor_SWC.h"

FUNC(void, AppSensor_CODE) MeasureDistance( VAR(void, AUTOMATIC) )
{
    VAR(DistanceGroup_t, AUTOMATIC) DistanceGroup;
    /* Read data from 4 sensors */
    Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_1);                                 // Start checkpoint Deadline SE1
    
    Rte_Call_R_IO_IO_GetDistance_S0(&DistanceGroup.Distance_S0);
    Rte_Call_R_IO_IO_GetDistance_S1(&DistanceGroup.Distance_S1);
    Rte_Call_R_IO_IO_GetDistance_S2(&DistanceGroup.Distance_S2);
    Rte_Call_R_IO_IO_GetDistance_S3(&DistanceGroup.Distance_S3);

    Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_2);                                 // End checkpoint Deadline SE1
    
    /* Send to PDCECU */
    Rte_Write_P_PP_DistanceUS_SendDistance(DistanceGroup);
	
    Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_0);                                     // Alive SE1
}

