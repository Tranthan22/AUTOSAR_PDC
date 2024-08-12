/******************************************************************************/
/* Copyright   : SCSK Corporation                                             */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_AppAdc.h                                                 */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator 2019.12 (Java)                          */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_APPADC_H
#define RTE_APPADC_H


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_AppAdc_Type.h"
#include "Rte_DataHandleType.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Rte_CDS_AppAdc {
    VAR(uint8, AUTOMATIC) Rte_Dummy;
};

extern CONSTP2CONST(struct Rte_CDS_AppAdc, RTE_CONST, RTE_CONST) Rte_Inst_AppAdc;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcGetGroupStatus( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) id, P2VAR(AppIo_IoHwAb_Q_AdcGroupStatusType, AUTOMATIC, RTE_APPL_DATA) value );
#define Rte_Call_R_App_AdcToIoHwAb_IoHwAb_Q_AdcGetGroupStatus Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcGetGroupStatus

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcGetStreamLastPointer( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) id, P2VAR(AppIo_IoHwAb_AdcValueGroupType, AUTOMATIC, RTE_APPL_DATA) value, P2VAR(AppIo_IoHwAb_Q_AdcStreamNumSampleType, AUTOMATIC, RTE_APPL_DATA) numsample );
#define Rte_Call_R_App_AdcToIoHwAb_IoHwAb_Q_AdcGetStreamLastPointer Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcGetStreamLastPointer

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcNotification( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) id );
#define Rte_Call_R_App_AdcToIoHwAb_IoHwAb_Q_AdcNotification Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcNotification

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcPeriodic( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) start_id, VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) end_id );
#define Rte_Call_R_App_AdcToIoHwAb_IoHwAb_Q_AdcPeriodic Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcPeriodic

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcReadGroup( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) id, P2VAR(AppIo_uint16p, AUTOMATIC, RTE_APPL_DATA) value );
#define Rte_Call_R_App_AdcToIoHwAb_IoHwAb_Q_AdcReadGroup Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcReadGroup

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcStart( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) start_id, VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) end_id );
#define Rte_Call_R_App_AdcToIoHwAb_IoHwAb_Q_AdcStart Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcStart

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcStop( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) start_id, VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) end_id );
#define Rte_Call_R_App_AdcToIoHwAb_IoHwAb_Q_AdcStop Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_AdcStop

#define AppAdc_START_SEC_CODE
#include "AppAdc_MemMap.h"
FUNC(void, AppAdc_CODE) AppAdc_10ms( VAR(void, AUTOMATIC) );
#define AppAdc_STOP_SEC_CODE
#include "AppAdc_MemMap.h"
#define RTE_RUNNABLE_Run_AppAdc_10ms AppAdc_10ms

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* RTE_APPADC_H */

/* End of Rte_AppAdc.h */
