/******************************************************************************/
/* Copyright   :                                              */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_Partition_EcucPartition_0.c                              */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      :                           */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_PDC_Control.h"
#include "Rte_PDC_Service.h"
#include "Rte_PDC_AlarmSystem.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/




/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
TASK (DistanceAlarmTask) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OS_CE_AlarmCommand );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( OS_Task_DistanceAlarmTask, &Event );
        (VAR(void, AUTOMATIC))ClearEvent( OS_CE_AlarmCommand );
        if( (Event & OS_TE_50ms_DistanceMeasure) > 0U ) {
            

            Rte_ExecuteAlarmCommand();               

        }
        
        if((Event & OS_CE_DistanceDataReceived) > 0U){
            (VAR(void, AUTOMATIC))ClearEvent( OS_CE_DistanceDataReceived );

            Rte_ProcessControl();

        } else {
            (VAR(void, AUTOMATIC))ClearEvent( Event );
        }
    }
}


TASK (ServiceTask) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OS_CE_PDCService );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( OS_Task_DistanceAlarmTask, &Event );

        if( (Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_EcucPartition_0 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OS_TE_50ms_DistanceMeasure) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OS_CE_AlarmCommand );

                // Runnale Service
                if() {
                    
                }            

            } else {
              /* No treatment */
            }
        } else {
            (VAR(void, AUTOMATIC))ClearEvent( Event );
        }
    }
}
