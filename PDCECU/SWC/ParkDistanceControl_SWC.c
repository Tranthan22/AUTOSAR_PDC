#include "Rte_PDC_Control.h"
#include "Rte_PDC_Service.h"

FUNC(void, Alarm_CODE) ProcessControl( VAR(void, AUTOMATIC) )
{
    Rte_Call_WdgMCheckpointReached(SE2_ID,CP_ID_3);                         // Start checkpoint Deadline SE2
    Rte_Call_WdgMCheckpointReached(SE4_ID,CP_ID_7);                         // Start checkpoint Deadline SE4

	/*perform calcutate alarm level*/
    Rte_Read_R_RP_DistanceUS_ReadDistanceUS();

    Rte_Call_WdgMCheckpointReached(SE2_ID,CP_ID_4);                         // End checkpoint Deadline SE4
}