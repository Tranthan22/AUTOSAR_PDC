/******************************************************************************/
/* Copyright   : SCSK Corporation                                             */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_AppComTxRx.h                                             */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator 2019.12 (Java)                          */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_APPCOMTXRX_H
#define RTE_APPCOMTXRX_H


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_AppComTxRx_Type.h"
#include "Rte_DataHandleType.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

struct Rte_CDS_AppComTxRx {
    VAR(uint8, AUTOMATIC) Rte_Dummy;
};

extern CONSTP2CONST(struct Rte_CDS_AppComTxRx, RTE_CONST, RTE_CONST) Rte_Inst_AppComTxRx;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_ModuleId( VAR(AUTOSAR_uint8, AUTOMATIC) data );
#define Rte_Write_AtmResp_AtmResp_Sig_ModuleId Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_ModuleId

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_TestFunction( VAR(AUTOSAR_uint8, AUTOMATIC) data );
#define Rte_Write_AtmResp_AtmResp_Sig_TestFunction Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_TestFunction

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_TestCaseNum( VAR(AUTOSAR_uint8, AUTOMATIC) data );
#define Rte_Write_AtmResp_AtmResp_Sig_TestCaseNum Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_TestCaseNum

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_Result( VAR(AUTOSAR_uint8, AUTOMATIC) data );
#define Rte_Write_AtmResp_AtmResp_Sig_Result Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_Result

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_AddExp1( VAR(AUTOSAR_uint8, AUTOMATIC) data );
#define Rte_Write_AtmResp_AtmResp_Sig_AddExp1 Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_AddExp1

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_AddExp2( VAR(AUTOSAR_uint8, AUTOMATIC) data );
#define Rte_Write_AtmResp_AtmResp_Sig_AddExp2 Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_AddExp2

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_AddExp3( VAR(AUTOSAR_uint8, AUTOMATIC) data );
#define Rte_Write_AtmResp_AtmResp_Sig_AddExp3 Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_AddExp3

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_AddExp4( VAR(AUTOSAR_uint8, AUTOMATIC) data );
#define Rte_Write_AtmResp_AtmResp_Sig_AddExp4 Rte_Write_AppComTxRx_AtmResp_AtmResp_Sig_AddExp4

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_ModuleId( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_AtmReq_AtmReq_Sig_ModuleId Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_ModuleId

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_TestFunction( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_AtmReq_AtmReq_Sig_TestFunction Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_TestFunction

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_TestCaseNum( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_AtmReq_AtmReq_Sig_TestCaseNum Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_TestCaseNum

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Cmd( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_AtmReq_AtmReq_Sig_Cmd Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Cmd

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Param1( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_AtmReq_AtmReq_Sig_Param1 Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Param1

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Param2( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_AtmReq_AtmReq_Sig_Param2 Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Param2

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Param3( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_AtmReq_AtmReq_Sig_Param3 Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Param3

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Param4( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_AtmReq_AtmReq_Sig_Param4 Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Param4

#define AppComTxRx_START_SEC_CODE
#include "AppComTxRx_MemMap.h"
FUNC(void, AppComTxRx_CODE) App_ComTxRx( VAR(void, AUTOMATIC) );
#define AppComTxRx_STOP_SEC_CODE
#include "AppComTxRx_MemMap.h"
#define RTE_RUNNABLE_Run_AppComTxRx App_ComTxRx

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* RTE_APPCOMTXRX_H */

/* End of Rte_AppComTxRx.h */
