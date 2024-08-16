/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_PDC_Service.h                                            */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_PDC_SERVICE_H
#define RTE_PDC_SERVICE_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PDCService_R_RP_PDCService_PDC_OnOff( P2VAR(PDC_Status_uint8_t, AUTOMATIC, RTE_APPL_DATA) data);
#define Rte_Read_R_PP_PDCService_PDC_OnOff Rte_Read_PDCService_R_RP_PDCService_PDC_OnOff 

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PDCService_R_IO_PDCStatus_SendPDCStatus( VAR(PDC_Status_uint8_t, AUTOMATIC) data );
#define Rte_Call_R_IO_SendPDCStatus Rte_Call_PDCService_R_IO_PDCStatus_SendPDCStatus 


FUNC(void, AppControl_CODE) PDCService ( VAR(void, AUTOMATIC) );
#define RTE_RUNNABLE_Run_Rte_PDCService PDCService

#endif /* RTE_PDC_SERVICE_H */

/* End of Rte_PDC_Service.h */