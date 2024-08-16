/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_PDC_Control.h                                            */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_PDC_CONTROL_H
#define RTE_PDC_CONTROL_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_Type.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance( P2VAR(pDistanceGroup_t, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_R_RP_DistanceUS_ReadDistance Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance 

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ParkDistanceControl_P_PP_Alarm_SendAlarmLevel( VAR(AlarmLevel_uint8_t, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Write_P_PP_Alarm_SendAlarmLevel Rte_Write_ParkDistanceControl_P_PP_Alarm_SendAlarmLevel 

FUNC(void, AppControl_CODE) ProcessControl( VAR(void, AUTOMATIC) );
#define RTE_RUNNABLE_Run_ProcessControl ProcessControl


#endif /* RTE_PDC_CONTROL_H */

/* End of Rte_PDC_Control.h */