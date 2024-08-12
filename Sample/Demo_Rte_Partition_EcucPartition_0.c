/******************************************************************************/
/* Copyright   : SCSK Corporation                                             */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_Partition_EcucPartition_0.c                              */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator 2019.12 (Java)                          */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_Type.h"

#include "Os.h"
#include "Com.h"
#include "Rte_Internal.h"

/* AUTOSAR Version Check : Com */
#if ( ( COM_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION )\
|| ( COM_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION ) )
#error "AUTOSAR Release Version error between Com and RTE." 
#endif

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/
extern VAR(uint8, AUTOMATIC) Rte_status;
extern VAR(uint8, AUTOMATIC) SchM_status;
extern VAR(boolean, AUTOMATIC) Rte_periodically_event_activation;
extern VAR(boolean, AUTOMATIC) SchM_periodically_event_activation;
extern VAR(uint8, AUTOMATIC) Rte_partition_status_EcucPartition_0;
extern VAR(uint32, AUTOMATIC) Rte_DisableEventList[83];


/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
extern VAR(EcuM_ModeType, AUTOMATIC) Rte_EcuM_currentMode_currentMode_prev_mode;
extern VAR(EcuM_ModeType, AUTOMATIC) Rte_EcuM_currentMode_currentMode_curr_mode;
extern VAR(Std_ReturnType, AUTOMATIC) Rte_EcuM_currentMode_currentMode_mode_status;
extern VAR(uint32, AUTOMATIC) Rte_EcuM_currentMode_currentMode_mode_queuenum;
extern VAR(uint32, AUTOMATIC) Rte_EcuM_currentMode_currentMode_mode_queuehead;
extern VAR(EcuM_ModeType, AUTOMATIC) Rte_EcuM_currentMode_currentMode_mode_queue[6];
extern FUNC(uint32, RTE_CODE_EcucPartition_0) Rte_ModeToIndex_EcuM_currentMode_currentMode( VAR(EcuM_ModeType, AUTOMATIC) mode );
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_ModeSwitch_EcuM_currentMode_currentMode( VAR(EcuM_ModeType, AUTOMATIC) mode );

/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_PostModeTransition_EcucPartition_0                       */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_PostModeTransition_EcucPartition_0(CONST(EventMaskType, AUTOMATIC) event ) {

    VAR(TaskType, AUTOMATIC) now_task;
    VAR(EventMaskType, AUTOMATIC) now_ev;

    now_task = 0;
    now_ev = 0U;

    if( E_OK == GetTaskID( &now_task ) ){
        (VAR(void, AUTOMATIC))GetEvent( now_task, &now_ev );

        if( ((now_ev & (OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode | OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode | OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode | OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode | OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode)) == 0U)
            && ((event & (OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode | OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode | OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode | OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode | OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode)) > 0U) ) {

            Rte_EcuM_currentMode_currentMode_mode_status = RTE_E_TRANSMIT_ACK;
            RTE_Q_LOCK();
            if( Rte_EcuM_currentMode_currentMode_mode_queuenum > 0U ) {
                Rte_EcuM_currentMode_currentMode_mode_queuenum--;
                Rte_EcuM_currentMode_currentMode_mode_queuehead = (Rte_EcuM_currentMode_currentMode_mode_queuehead + 1U) % 6U;

            }
            if( Rte_EcuM_currentMode_currentMode_mode_queuenum > 0U ) {
                Rte_EcuM_currentMode_currentMode_mode_status = RTE_E_NO_DATA;
                Rte_EcuM_currentMode_currentMode_prev_mode = Rte_EcuM_currentMode_currentMode_curr_mode;
                Rte_EcuM_currentMode_currentMode_curr_mode = Rte_EcuM_currentMode_currentMode_mode_queue[Rte_EcuM_currentMode_currentMode_mode_queuehead];
                RTE_Q_UNLOCK();
                Rte_ModeSwitch_EcuM_currentMode_currentMode( Rte_EcuM_currentMode_currentMode_mode_queue[Rte_EcuM_currentMode_currentMode_mode_queuehead] );
                RTE_Q_LOCK();
            }
            RTE_Q_UNLOCK();
        }
    }
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Executable_MonitoringTimeout_EcucPartition_0             */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_Executable_MonitoringTimeout_EcucPartition_0( VAR(void, AUTOMATIC) ) {
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_App_ComTxRx(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_AppDiag_20ms(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_AppWdgM_20ms(VAR(void, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : ASWTask_20ms                                                 */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

TASK (ASWTask_20ms) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OsEvent_ASW_20ms );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( OsTask_ASWTask_20ms, &Event );

        if( (Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_EcucPartition_0 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_ASW_20ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_ASW_20ms );

                if ( Rte_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[3] == 0U ) {
                        Rte_App_ComTxRx();
                    }
                }
                if ( Rte_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[12] == 0U ) {
                        Rte_AppDiag_20ms();
                    }
                }
                if ( Rte_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[36] == 0U ) {
                        Rte_AppWdgM_20ms();
                    }
                }
            } else {
              /* No treatment */
            }
        } else {
            (VAR(void, AUTOMATIC))ClearEvent( Event );
        }
    }
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, RTE_CODE_EcucPartition_0) Can_MainFunction_BusOff(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Can_MainFunction_Wakeup(VAR(void, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : BusDiagTask_100ms                                            */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

TASK (BusDiagTask_100ms) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OsEvent_ComBusDiagTask_100ms );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( OsTask_BusDiagTask_100ms, &Event );

        if( (Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_EcucPartition_0 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_ComBusDiagTask_100ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_ComBusDiagTask_100ms );

                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[56] == 0U ) {
                        Can_MainFunction_BusOff();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[59] == 0U ) {
                        Can_MainFunction_Wakeup();
                    }
                }
            } else {
              /* No treatment */
            }
        } else if( ((Rte_status != RTE_STATUS_RUN) || (Rte_partition_status_EcucPartition_0 != RTE_PARTITION_STATUS_RUNNING)) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_ComBusDiagTask_100ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_ComBusDiagTask_100ms );
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[56] == 0U ) {
                        Can_MainFunction_BusOff();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[59] == 0U ) {
                        Can_MainFunction_Wakeup();
                    }
                }
            } else {
                (VAR(void, AUTOMATIC))ClearEvent( Event );
            }
        } else {
            (VAR(void, AUTOMATIC))ClearEvent( Event );
        }
    }
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, RTE_CODE_EcucPartition_0) Can_MainFunction_Mode(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) CanTrcv_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) CanNm_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) ComM_MainFunction_0(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) ComM_MainFunction_1(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Nm_MainFunction(VAR(void, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : ComCtrlTask_10ms                                             */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

TASK (ComCtrlTask_10ms) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OsEvent_ComCtrlTask_10ms );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( OsTask_ComCtrlTask_10ms, &Event );

        if( (Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_EcucPartition_0 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_ComCtrlTask_10ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_ComCtrlTask_10ms );

                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[57] == 0U ) {
                        Can_MainFunction_Mode();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[41] == 0U ) {
                        CanTrcv_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[38] == 0U ) {
                        CanNm_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[44] == 0U ) {
                        ComM_MainFunction_0();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[45] == 0U ) {
                        ComM_MainFunction_1();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[51] == 0U ) {
                        Nm_MainFunction();
                    }
                }
            } else {
              /* No treatment */
            }
        } else if( ((Rte_status != RTE_STATUS_RUN) || (Rte_partition_status_EcucPartition_0 != RTE_PARTITION_STATUS_RUNNING)) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_ComCtrlTask_10ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_ComCtrlTask_10ms );
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[57] == 0U ) {
                        Can_MainFunction_Mode();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[41] == 0U ) {
                        CanTrcv_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[38] == 0U ) {
                        CanNm_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[44] == 0U ) {
                        ComM_MainFunction_0();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[45] == 0U ) {
                        ComM_MainFunction_1();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[51] == 0U ) {
                        Nm_MainFunction();
                    }
                }
            } else {
                (VAR(void, AUTOMATIC))ClearEvent( Event );
            }
        } else {
            (VAR(void, AUTOMATIC))ClearEvent( Event );
        }
    }
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, RTE_CODE_EcucPartition_0) Com_MainFunctionRx(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Com_MainFunctionTx(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) IpduM_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Dcm_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) CanTp_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Can_MainFunction_Read(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Can_MainFunction_Write(VAR(void, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : ComTxRxTask_5ms                                              */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

TASK (ComTxRxTask_5ms) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OsEvent_ComTxRxTask_5ms );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( OsTask_ComTxRxTask_5ms, &Event );

        if( (Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_EcucPartition_0 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_ComTxRxTask_5ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_ComTxRxTask_5ms );

                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[42] == 0U ) {
                        Com_MainFunctionRx();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[43] == 0U ) {
                        Com_MainFunctionTx();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[50] == 0U ) {
                        IpduM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[46] == 0U ) {
                        Dcm_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[40] == 0U ) {
                        CanTp_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[58] == 0U ) {
                        Can_MainFunction_Read();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[60] == 0U ) {
                        Can_MainFunction_Write();
                    }
                }
            } else {
              /* No treatment */
            }
        } else if( ((Rte_status != RTE_STATUS_RUN) || (Rte_partition_status_EcucPartition_0 != RTE_PARTITION_STATUS_RUNNING)) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_ComTxRxTask_5ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_ComTxRxTask_5ms );
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[42] == 0U ) {
                        Com_MainFunctionRx();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[43] == 0U ) {
                        Com_MainFunctionTx();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[50] == 0U ) {
                        IpduM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[46] == 0U ) {
                        Dcm_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[40] == 0U ) {
                        CanTp_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[58] == 0U ) {
                        Can_MainFunction_Read();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[60] == 0U ) {
                        Can_MainFunction_Write();
                    }
                }
            } else {
                (VAR(void, AUTOMATIC))ClearEvent( Event );
            }
        } else {
            (VAR(void, AUTOMATIC))ClearEvent( Event );
        }
    }
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_AppDio_10ms(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_AppAdc_10ms(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_AppPwm_10ms(VAR(void, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : IO_CtrlTask_10ms                                             */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

TASK (IO_CtrlTask_10ms) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OsEvent_IO_CtrlTask_10ms );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( OsTask_IO_CtrlTask_10ms, &Event );

        if( (Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_EcucPartition_0 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_IO_CtrlTask_10ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_IO_CtrlTask_10ms );

                if ( Rte_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[14] == 0U ) {
                        Rte_AppDio_10ms();
                    }
                }
                if ( Rte_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[13] == 0U ) {
                        Rte_AppAdc_10ms();
                    }
                }
                if ( Rte_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[15] == 0U ) {
                        Rte_AppPwm_10ms();
                    }
                }
            } else {
              /* No treatment */
            }
        } else {
            (VAR(void, AUTOMATIC))ClearEvent( Event );
        }
    }
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, RTE_CODE_EcucPartition_0) NvM_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Fee_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Fls_MainFunction(VAR(void, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : MemRWTask_50ms                                               */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

TASK (MemRWTask_50ms) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OsEvent_MemRW_50ms );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( OsTask_MemRWTask_50ms, &Event );

        if( (Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_EcucPartition_0 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_MemRW_50ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_MemRW_50ms );

                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[52] == 0U ) {
                        NvM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[49] == 0U ) {
                        Fee_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[61] == 0U ) {
                        Fls_MainFunction();
                    }
                }
            } else {
              /* No treatment */
            }
        } else if( ((Rte_status != RTE_STATUS_RUN) || (Rte_partition_status_EcucPartition_0 != RTE_PARTITION_STATUS_RUNNING)) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_MemRW_50ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_MemRW_50ms );
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[52] == 0U ) {
                        NvM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[49] == 0U ) {
                        Fee_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[61] == 0U ) {
                        Fls_MainFunction();
                    }
                }
            } else {
                (VAR(void, AUTOMATIC))ClearEvent( Event );
            }
        } else {
            (VAR(void, AUTOMATIC))ClearEvent( Event );
        }
    }
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, RTE_CODE_EcucPartition_0) BswM_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) CanSM_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) EcuM_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) WdgM_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Dem_MainFunction(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_Run_App_ModeMngModeSwitched(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_Run_AppNm_ComMRequestMode(VAR(void, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : ModeCtrlTask_10ms                                            */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

TASK (ModeCtrlTask_10ms) {
    VAR(EventMaskType, AUTOMATIC) Event;

    while( 1 )
    {
        (VAR(void, AUTOMATIC))WaitEvent( OsEvent_ModeCtrlTask_10ms | OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( OsTask_ModeCtrlTask_10ms, &Event );

        if( (Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_EcucPartition_0 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_ModeCtrlTask_10ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_ModeCtrlTask_10ms );

                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[37] == 0U ) {
                        BswM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[39] == 0U ) {
                        CanSM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[48] == 0U ) {
                        EcuM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[53] == 0U ) {
                        WdgM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[47] == 0U ) {
                        Dem_MainFunction();
                    }
                }
            } else if ( (Event & OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_ModeCtrlTask_10ms_EcuMCurrentMode );

                if( (Rte_DisableEventList[29] == 0U) && (Rte_DisableEventList[30] == 0U) && (Rte_DisableEventList[31] == 0U) && (Rte_DisableEventList[32] == 0U) && (Rte_DisableEventList[33] == 0U) ) {
                    Rte_Run_App_ModeMngModeSwitched();
                }
                if( Rte_DisableEventList[35] == 0U ) {
                    Rte_Run_AppNm_ComMRequestMode();
                }
            } else {
              /* No treatment */
            }

            Rte_PostModeTransition_EcucPartition_0( Event );
        } else if( ((Rte_status != RTE_STATUS_RUN) || (Rte_partition_status_EcucPartition_0 != RTE_PARTITION_STATUS_RUNNING)) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & OsEvent_ModeCtrlTask_10ms) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( OsEvent_ModeCtrlTask_10ms );
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[37] == 0U ) {
                        BswM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[39] == 0U ) {
                        CanSM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[48] == 0U ) {
                        EcuM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[53] == 0U ) {
                        WdgM_MainFunction();
                    }
                }
                if ( SchM_periodically_event_activation == TRUE ) {
                    if( Rte_DisableEventList[47] == 0U ) {
                        Dem_MainFunction();
                    }
                }
            } else {
                (VAR(void, AUTOMATIC))ClearEvent( Event );
            }
        } else {
            (VAR(void, AUTOMATIC))ClearEvent( Event );
        }
    }
}

#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"



/* End of Rte_Partition_EcucPartition_0.c */
