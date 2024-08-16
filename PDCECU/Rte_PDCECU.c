/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_PDCECU.c                                                 */
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
/* Name        : DistanceAlarmTask                                             */
/* Trigger     : OS_CE_AlarmCommand, OS_CE_DistanceDataReceived                */
/* Param       : None                                                          */
/* Return      : TASK                                                          */
/* Contents    : This task handles two main events related to distance alarms: */
/*               1. `OS_CE_AlarmCommand`: When this event is triggered, the    */
/*                  task calls `Rte_ExecuteAlarmCommand` to execute any alarm  */
/*                  related commands.                                          */
/*               2. `OS_CE_DistanceDataReceived`: When this event is triggered,*/
/*                  the task calls `Rte_ProcessControl` to process the received*/
/*                  distance data and control the system accordingly.          */
/*               The task operates in an infinite loop, waiting for either of  */
/*               these events to occur, and clears the event flags after       */
/*               processing them.                                              */
/* Note        : The task uses event-based scheduling to respond to the alarm  */
/*               commands and distance data reception events efficiently.      */
/*******************************************************************************/
extern FUNC(void, RTE_CODE) Rte_ProcessControl( VAR(void, AUTOMATIC) );
extern FUNC(void, RTE_CODE) Rte_ExecuteAlarmCommand( VAR(void, AUTOMATIC) );

TASK (DistanceAlarmTask) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OS_CE_AlarmCommand | OS_CE_DistanceDataReceived );
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

/*******************************************************************************/
/* Name        : ServiceTask                                                   */
/* Trigger     : OS_CE_PDCService                                              */
/* Param       : None                                                          */
/* Return      : TASK                                                          */
/* Contents    : This task waits for the `OS_CE_PDCService` event to be        */
/*               triggered, indicating that the Park Distance Control (PDC)    */
/*               service needs to be processed. The task performs the          */
/*               following steps:                                              */
/*               1. Waits for the `OS_CE_PDCService` event to occur.           */
/*               2. Once the event is detected, it retrieves the event flag    */
/*                  using `GetEvent` and then clears the event flag using      */
/*                  `ClearEvent`.                                              */
/*               3. If the `OS_CE_PDCService` event is set, the task will      */
/*                  execute the PDC service logic by calling `Rte_PDCService`. */
/* Note        : This task is designed to run in an infinite loop, and it will */
/*               execute the PDC service logic whenever the relevant event     */
/*               is triggered.                                                 */
/*******************************************************************************/
extern FUNC(void, RTE_CODE) Rte_PDCService ( VAR(void, AUTOMATIC) );

TASK (ServiceTask) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( c );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( ServiceTask, &Event );
        (VAR(void, AUTOMATIC))ClearEvent( Event & ( OS_CE_PDCService ) );

        if( (Event & OS_CE_PDCService) > 0U ) {
            // Runnale Service
            
        }
    }
}
