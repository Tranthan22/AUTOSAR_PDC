/******************************************************************************/
/* Copyright   : Group 3 Corporation                                          */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_PDC_Service.c                                              */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : DungDT55                                                 */
/* Note        :                                                              */
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_PDC_Service.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_R_RP_PDCService_StartPDCControl( VAR(PackDistanceControl_Service_uint8, AUTOMATIC,RTE_APPL_DATA) );


FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_PDCService_R_RP_PDCService_StartPDCControl( VAR(PackDistanceControl_Service_uint8, AUTOMATIC) Start_PDCControl) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_R_RP_PDCService_StartPDCControl( Start_PDCControl );
    return return_value;
}


/******************************************************************************/
/*
*/
/******************************************************************************/


extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_R_RP_PDCStatus_SendStatusPDCControl( VAR(PDCService_Status_uint8, AUTOMATIC,RTE_APPL_DATA) );


FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_PDCService_R_IO_PDCStatus_GetPDCStatus( VAR(PDCService_Status_uint8, AUTOMATIC) ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;
    return_value = IoHwAb_R_RP_PDCStatus_SendStatusPDCControl( getPDCStatus );
    return return_value;
}

/**********************************  Section 2 ******************************* */
extern FUNC(void, AppAlarm_CODE) PDCService ( VAR(void, AUTOMATIC) );

FUNC(void, RTE_CODE_EcucPartition_0) Rte_PDCService ( VAR(void, AUTOMATIC) ) {

    PDCService ();

}


