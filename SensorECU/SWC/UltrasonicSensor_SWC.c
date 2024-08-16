/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : UltrasonicSensor_SWC.c                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

#include "UltrasonicSensor_SWC.h"

FUNC(void, AppSensor_CODE) SensorOffset( P2VAR(pDistanceGroup_t, AUTOMATIC, RTE_APPL_DATA) distanceGroup, P2CONST(SensorOffset_t, AUTOMATIC, RTE_APPL_DATA) offSet ) {
    distanceGroup->Distance_S0 += offSet->SensorOffset_0;
    distanceGroup->Distance_S1 += offSet->SensorOffset_1;
    distanceGroup->Distance_S2 += offSet->SensorOffset_2;
    distanceGroup->Distance_S3 += offSet->SensorOffset_3;
}

FUNC(void, AppSensor_CODE) MeasureDistance( VAR(void, AUTOMATIC) )
{
    VAR(DistanceGroup_t, AUTOMATIC) DistanceGroup;
    VAR(SensorOffset_t, AUTOMATIC) SensorOffset;
    /* Read data from 4 sensors */
    Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_1);                                 // Start checkpoint Deadline SE1
    
    Rte_Call_R_IO_IO_GetDistance_S0(&DistanceGroup.Distance_S0);
    Rte_Call_R_IO_IO_GetDistance_S1(&DistanceGroup.Distance_S1);
    Rte_Call_R_IO_IO_GetDistance_S2(&DistanceGroup.Distance_S2);
    Rte_Call_R_IO_IO_GetDistance_S3(&DistanceGroup.Distance_S3);

    // Get sensor offset
    Rte_Call_NvM_Service_Readblock_NVM_Sensor(&SensorOffset)

    // Sensor calibration
    SensorOffset(&DistanceGroup, &SensorOffset);

    Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_2);                                 // End checkpoint Deadline SE1
    
    /* Send to PDCECU */
    Rte_Write_P_PP_DistanceUS_SendDistance(DistanceGroup);
	
    Rte_Call_WdgMCheckpointReached(SE1_ID,CP_ID_0);                                     // Alive SE1
}