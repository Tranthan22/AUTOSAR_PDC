#include "Rte_PDC_Control.h"
#include "Rte_PDC_Service.h"

FUNC(void, RTE_CODE) ProcessControl( VAR(void, AUTOMATIC) )
{
    DistanceGroup_t DistanceGroup;
    USSensor_uint8_t MinDistance; 
    AlarmLevel_uint8_t AlarmLevel;
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

    // Calculate AlarmLevel (5 levels)
    if (MinDistance >= 100 && MinDistance < 250) {
        AlarmLevel = 1;
    } else if (MinDistance >= 50) {
        AlarmLevel = 2;
    } else if (MinDistance >= 30) {
        AlarmLevel = 3;
    } else if (MinDistance >= 15) {
        AlarmLevel = 4;
    } else if (MinDistance > 0) {
        AlarmLevel = 5;
    } else {
        return 0;                                   // beyond the range 0 - 250 cm
    }

    // Send alarm level
    Rte_Write_P_PP_Alarm_SendAlarmLevel(AlarmLevel);

    Rte_Call_WdgMCheckpointReached(SE2_ID,CP_ID_4);                         // End checkpoint Deadline SE4
}