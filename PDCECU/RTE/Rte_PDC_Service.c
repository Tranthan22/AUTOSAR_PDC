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

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
VAR(PDC_Status_uint8_t, AUTOMATIC) Rte_Read_PDC_Service_active_Value;
VAR(Std_ReturnType, AUTOMATIC) Rte_Read_PDC_Service_active_status = RTE_E_NEVER_RECEIVED;

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PDCService_R_RP_PDCService_StartPDCControl( P2VAR(PackDistanceControl_Service_uint8, AUTOMATIC) Start_PDCControl) {
    
}

/******************************************************************************/

/******************************************************************************/
extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_R_RP_PDCStatus_SendPDCStatus( P2VAR(PDC_Status_uint8_t, AUTOMATIC, RTE_APPL_DATA) );

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PDCService_R_IO_PDCStatus_SendPDCStatus( P2VAR(PDC_Status_uint8_t, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_R_RP_PDCStatus_SendPDCStatus( data );
    return return_value;
}

/**********************************  Section 2 ******************************* */
extern FUNC(void, AppControl_CODE) PDCService ( VAR(void, AUTOMATIC) );

FUNC(void, RTE_CODE) Rte_PDCService ( VAR(void, AUTOMATIC) ) {

    PDCService ();

}


