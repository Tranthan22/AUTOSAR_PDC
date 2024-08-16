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
extern extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance( P2VAR(pDistanceGroup_t, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_R_RP_DistanceUS_ReadDistance Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance 

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ParkDistanceControl_P_PP_Alarm_SendAlarmLevel( VAR(AlarmLevel_uint8_t, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Write_P_PP_Alarm_SendAlarmLevel Rte_Write_ParkDistanceControl_P_PP_Alarm_SendAlarmLevel 

FUNC(void, AUTOMATIC) ProcessControl( VAR(void, AUTOMATIC) );
#define RTE_RUNNABLE_Run_ProcessControl ProcessControl


#endif /* RTE_PDC_CONTROL_H */

/* End of Rte_PDC_Control.h */