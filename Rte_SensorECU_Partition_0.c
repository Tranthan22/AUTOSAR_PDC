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
#include "Rte_USSensor.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/




/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
TASK (DistanceMeasureTask) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OS_TE_50ms_DistanceMeasure );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( DistanceMeasureTask, &Event );
        (VAR(void, AUTOMATIC))ClearEvent( Event & ( OS_TE_50ms_DistanceMeasure ) );
        if( (Event & OS_TE_50ms_DistanceMeasure) > 0U ) {

            Rte_MeasureDistance();
            
        } else {
            /* No treatment */
        }
    }
}

