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

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S0( P2VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distanceUS0 );
#define Rte_Read_R_RP_DistanceUS_ReadDistance_S0 Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S0 

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S1( P2VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distanceUS1 );
#define Rte_Read_R_RP_DistanceUS_ReadDistance_S1 Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S1

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S2( P2VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distanceUS2 );
#define Rte_Read_R_RP_DistanceUS_ReadDistance_S2 Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S2

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S3( P2VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distanceUS3 );
#define Rte_Read_R_RP_DistanceUS_ReadDistance_S3 Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance_S3

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_ParkDistanceControl_P_PP_Alarm_SendDistancetoAlarm( VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distance_to_alarm );
#define Rte_Write_P_PP_Alarm_SendDistancetoAlarm Rte_Write_ParkDistanceControl_P_PP_Alarm_SendDistancetoAlarm 

FUNC(void, AUTOMATIC) ProcessControl( VAR(void, AUTOMATIC) );
#define RTE_RUNNABLE_Run_ProcessControl ProcessControl


#endif /* RTE_PDC_CONTROL_H */

/* End of Rte_PDC_Control.h */