/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : ParkDistanceControl_SWC.c                                    */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

#include "Rte_PDC_Control.h"
#include "Rte_PDC_Service.h"

FUNC(void, AppControl_CODE) ProcessControl( VAR(void, AUTOMATIC) )
{
    DistanceGroup_t DistanceGroup;
    USSensor_uint8_t MinDistance; 
    AlarmLevel_uint8_t AlarmLevel;
    AlarmLevel_t Threshold;
    Rte_Call_WdgMCheckpointReached(SE2_ID,CP_ID_3);                         // Start checkpoint Deadline SE2
    Rte_Call_WdgMCheckpointReached(SE4_ID,CP_ID_7);                         // Start checkpoint Deadline SE4
    
    // Read group information about distance of obstacles
    Rte_Read_R_RP_DistanceUS_ReadDistance(&DistanceGroup);

    // Find out min distance of obstacles
    MinDistance = DistanceGroup.Distance_S0;
    if (DistanceGroup.Distance_S2 < MinDistance) {
        MinDistance = DistanceGroup.Distance_S2;
    }
    if (DistanceGroup.Distance_S3 < MinDistance) {
        MinDistance = DistanceGroup.Distance_S3;
    }
    if (DistanceGroup.Distance_S4 < MinDistance) {
        MinDistance = DistanceGroup.Distance_S4;
    }
    // Read threshold from NvM
    Rte_Call_NvM_Service_Readblock_NVM_Alarm(&Threshold);

    // Calculate AlarmLevel (5 levels)
    if (MinDistance >= Threshold.AlarmLevel_4 && MinDistance < 250) {
        AlarmLevel = 5;
    } else if (MinDistance >= Threshold.AlarmLevel_3) {
        AlarmLevel = 4;
    } else if (MinDistance >= Threshold.AlarmLevel_2) {
        AlarmLevel = 3;
    } else if (MinDistance >= Threshold.AlarmLevel_1) {
        AlarmLevel = 2;
    } else if (MinDistance > 0) {
        AlarmLevel = 1;
    } else {
        return 0;                                   // beyond the range 0 - 250 cm
    }

    // Send alarm level
    Rte_Write_P_PP_Alarm_SendAlarmLevel(AlarmLevel);

    Rte_Call_WdgMCheckpointReached(SE2_ID,CP_ID_4);                         // End checkpoint Deadline SE4
}