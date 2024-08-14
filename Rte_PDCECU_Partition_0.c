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
        (VAR(void, AUTOMATIC))GetEvent( DistanceAlarmTask, &Event );
        (VAR(void, AUTOMATIC))ClearEvent( Event & ( OS_CE_AlarmCommand | OS_CE_DistanceDataReceived ) );

        if( (Event & OS_CE_AlarmCommand) > 0U ) {
            
            Rte_ExecuteAlarmCommand();               

        }
        if((Event & OS_CE_DistanceDataReceived) > 0U) {

            Rte_ProcessControl();

        }
    }
}


TASK (ServiceTask) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OS_CE_PDCService );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( ServiceTask, &Event );
        (VAR(void, AUTOMATIC))ClearEvent( Event & ( OS_CE_PDCService ) );

        if( (Event & OS_TE_50ms_DistanceMeasure) > 0U ) {

            // Runnale Service
            if() {

            }            
        }
    }
}
