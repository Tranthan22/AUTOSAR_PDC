/******************************************************************************/
/* Copyright   : GROUP 3 Corporation                                          */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_PDC_Service.h                                            */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : DungDT                                                       */
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

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_PDCService_R_RP_PDCService_StartPDCControl( P2VAR(PackDistanceControl_Service_uint8, AUTOMATIC) Start_PDCControl);
#define Rte_Read_R_PP_PDCService_StartPDCControl Rte_Read_PDCService_R_RP_PDCService_StartPDCControl 

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_PDCService_R_IO_PDCStatus_SendPDCStatus( VAR(PDC_Status_uint8_t, AUTOMATIC) data );
#define Rte_Call_R_IO_SendPDCStatus Rte_Call_PDCService_R_IO_PDCStatus_SendPDCStatus 


FUNC(void, AppControl_CODE) PDCService ( VAR(void, AUTOMATIC) );
#define RTE_RUNNABLE_Run_Rte_PDCService PDCService

#endif /* RTE_PDC_SERVICE_H */

/* End of Rte_PDC_Service.h */