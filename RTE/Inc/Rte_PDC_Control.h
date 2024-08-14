/******************************************************************************/
/* Copyright   : GROUP 3 Corporation                                          */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_PDC_Control.h                                                */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Nguyen Ngoc                                                    */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_PDC_CONTROL_H
#define RTE_PDC_CONTROL_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance( VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distance );
#define Rte_Read_R_RP_DistanceUS_ReadDistance Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance 

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_ParkDistanceControl_P_PP_Alarm_SendDistancetoAlarm( VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distance_to_alarm );
#define Rte_Write_P_PP_Alarm_SendDistancetoAlarm Rte_Write_ParkDistanceControl_P_PP_Alarm_SendDistancetoAlarm 







FUNC(void, AUTOMATIC) ProcessControl( VAR(void, AUTOMATIC) );
#define RTE_RUNNABLE_Run_ProcessControl ProcessControl

FUNC(void, AUTOMATIC) PDCService( VAR(void, AUTOMATIC) );
#define RTE_RUNNABLE_Run_PDCService PDCService

#endif /* RTE_PDC_CONTROL_H */

/* End of Rte_PDC_Control.h */