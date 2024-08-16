/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_SensorECU.c                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*******************************************************************************/
/* Task        : DistanceMeasureTask                                           */
/* Description : This task is responsible for periodically measuring the        */
/*               distance at a defined interval. It waits for an event to be    */
/*               triggered and then calls the function `Rte_MeasureDistance`    */
/*               to perform the measurement.                                    */
/*               The task operates in the following manner:                     */
/*               1. Waits for the event `OS_TE_50ms_DistanceMeasure`, which is  */
/*                  expected to be triggered every 50 milliseconds.            */
/*               2. Once the event is triggered, it retrieves the event mask    */
/*                  and clears the event.                                       */
/*               3. If the event `OS_TE_50ms_DistanceMeasure` is present, it    */
/*                  calls the `Rte_MeasureDistance` function to perform the     */
/*                  distance measurement.                                       */
/*               4. If the event is not present (else case), no action is      */
/*                  taken.                                                      */
/* Note        : Ensure that the event `OS_TE_50ms_DistanceMeasure` is correctly */
/*               configured in the operating system to trigger at the desired   */
/*               interval. This task is crucial for ensuring regular distance    */
/*               measurements.                                                */
/*******************************************************************************/

extern FUNC(void, RTE_CODE) Rte_MeasureDistance( VAR(void, AUTOMATIC) );

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

