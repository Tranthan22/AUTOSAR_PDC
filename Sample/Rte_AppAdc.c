/******************************************************************************/
/* Copyright   : SCSK Corporation                                             */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_AppAdc.c                                                 */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator 2019.12 (Java)                          */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Os.h"
#include "Rte_Internal.h"
#include "Com.h"
#include "Rte_AppAdc.h"

/* AUTOSAR Version Check : Com */
#if ( ( COM_AR_RELEASE_MINOR_VERSION != RTE_AR_RELEASE_MINOR_VERSION )\
|| ( COM_AR_RELEASE_MAJOR_VERSION != RTE_AR_RELEASE_MAJOR_VERSION ) )
#error "AUTOSAR Release Version error between Com and RTE." 
#endif

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
extern FUNC(void, AUTOMATIC) Rte_Memcpy( P2VAR(void, AUTOMATIC, RTE_APPL_DATA) dst, P2CONST(void, AUTOMATIC, RTE_APPL_DATA) src, CONST(uint32, AUTOMATIC) size);

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_Q_AdcGetGroupStatus( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC), P2VAR(AppIo_IoHwAb_Q_AdcGroupStatusType, AUTOMATIC, RTE_APPL_DATA) );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcGetGroupStatus */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcGetGroupStatus( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) id, P2VAR(AppIo_IoHwAb_Q_AdcGroupStatusType, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_Q_AdcGetGroupStatus( id, value );
    return return_value;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_Q_AdcGetStreamLastPointer( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC), P2VAR(AppIo_IoHwAb_AdcValueGroupType, AUTOMATIC, RTE_APPL_DATA), P2VAR(AppIo_IoHwAb_Q_AdcStreamNumSampleType, AUTOMATIC, RTE_APPL_DATA) );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcGetStreamLastPointer */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcGetStreamLastPointer( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) id, P2VAR(AppIo_IoHwAb_AdcValueGroupType, AUTOMATIC, RTE_APPL_DATA) value, P2VAR(AppIo_IoHwAb_Q_AdcStreamNumSampleType, AUTOMATIC, RTE_APPL_DATA) numsample ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_Q_AdcGetStreamLastPointer( id, value, numsample );
    return return_value;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, IoHwAb_CODE) IoHwAb_Q_AdcNotification( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcNotification   */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcNotification( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) id ) {
    IoHwAb_Q_AdcNotification( id );
    return RTE_E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, IoHwAb_CODE) IoHwAb_Q_AdcPeriodic( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC), VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcPeriodic       */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcPeriodic( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) start_id, VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) end_id ) {
    IoHwAb_Q_AdcPeriodic( start_id, end_id );
    return RTE_E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_Q_AdcReadGroup( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC), P2VAR(AppIo_uint16p, AUTOMATIC, RTE_APPL_DATA) );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcReadGroup      */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcReadGroup( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) id, P2VAR(AppIo_uint16p, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_Q_AdcReadGroup( id, value );
    return return_value;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_Q_AdcStart( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC), VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcStart          */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcStart( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) start_id, VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) end_id ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_Q_AdcStart( start_id, end_id );
    return return_value;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_Q_AdcStop( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC), VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcStop           */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcStop( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) start_id, VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) end_id ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_Q_AdcStop( start_id, end_id );
    return return_value;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, AppAdc_CODE) AppAdc_10ms( VAR(void, AUTOMATIC) );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_AppAdc_10ms                                              */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_AppAdc_10ms( VAR(void, AUTOMATIC) ) {

    AppAdc_10ms();

}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"



/* End of Rte_AppAdc.c */
