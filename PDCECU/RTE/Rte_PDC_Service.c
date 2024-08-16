/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_PDC_Service.c                                            */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_PDC_Service.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*******************************************************************************/
/* Name        : Rte_Read_PDCService_R_RP_PDCService_StartPDCControl           */
/* Param       : P2VAR(PDC_Status_uint8_t, AUTOMATIC) Start_PDCControl         */
/* Return      : FUNC(Std_ReturnType, RTE_CODE)                                */
/* Brief       : Reads the status of PDC service activation from the system    */
/*               and updates the provided variable with the current status.    */
/* Note        :                                                               */
/*******************************************************************************/
VAR(PDC_Status_uint8_t, AUTOMATIC) Rte_Read_PDC_Service_active_Value;
VAR(Std_ReturnType, AUTOMATIC) Rte_Read_PDC_Service_active_status = RTE_E_NEVER_RECEIVED;

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PDCService_R_RP_PDCService_PDC_OnOff( P2VAR(PDC_Status_uint8_t, AUTOMATIC, RTE_APPL_DATA) data) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    *data = Rte_Read_PDC_Service_active_Value;
    ret_val = Rte_Read_PDC_Service_active_status;
    RTE_Q_UNLOCK();

    return ret_val;
}

/******************************************************************************/
/* Name        : Rte_Call_PDCService_R_IO_PDCStatus_SendPDCStatus              */
/* Param       : P2VAR(PDC_Status_uint8_t, AUTOMATIC, RTE_APPL_DATA) data      */
/* Return      : FUNC(Std_ReturnType, RTE_CODE)                                */
/* Brief       : Calls the IoHwAb layer function to send the current PDC       */
/*               (Park Distance Control) status and returns the result of the  */
/*               operation. The provided data pointer is used to pass the      */
/*               status information to the hardware abstraction layer.         */
/* Note        :                                                               */
/******************************************************************************/
extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_R_RP_PDCStatus_SendPDCStatus( P2VAR(PDC_Status_uint8_t, AUTOMATIC, RTE_APPL_DATA) );

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PDCService_R_IO_PDCStatus_SendPDCStatus( P2VAR(PDC_Status_uint8_t, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_R_RP_PDCStatus_SendPDCStatus( data );
    return return_value;
}

/*******************************************************************************/
/* Name        : Rte_PDCService                                                */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      : FUNC(void, RTE_CODE)                                          */
/* Brief       : This function acts as a wrapper to call the PDCService        */
/*               function, which handles the Park Distance Control (PDC)       */
/*               service logic.                                                */
/* Note        :                                                               */
/*******************************************************************************/
extern FUNC(void, AppControl_CODE) PDCService ( VAR(void, AUTOMATIC) );

FUNC(void, RTE_CODE) Rte_PDCService ( VAR(void, AUTOMATIC) ) {

    PDCService ();

}


