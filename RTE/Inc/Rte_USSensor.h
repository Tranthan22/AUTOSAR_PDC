/******************************************************************************/
/* Copyright   : GROUP 3 Corporation                                          */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_Sensor.h                                                 */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Tran Than                                                    */
/* Note        :                                                              */
/******************************************************************************/


#ifndef RTE_SENSOR_H
#define RTE_SENSOR_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_USSensor_R_IO_GetDistance( VAR(USSensor_IoHwAb_SensorIdType, AUTOMATIC) id, P2VAR(USSensor_uint8p, AUTOMATIC, RTE_APPL_DATA) value );
#define Rte_Call_R_IO_GetDistance Rte_Call_USSensor_R_IO_GetDistance

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_USSensor_P_PP_DistanceUS_SendDistance( VAR(USSensor_uint8, AUTOMATIC, RTE_APPL_DATA) value );
#define Rte_Call_P_PP_DistanceUS_SendDistance Rte_Write_USSensor_P_PP_DistanceUS_SendDistance

#define AppSensor_START_SEC_CODE
#include "AppSensor_MemMap.h"
FUNC(void, AUTOMATIC) MeasureDistance( VAR(void, AUTOMATIC) );
#define AppSensor_STOP_SEC_CODE
#define RTE_RUNNABLE_Run_MeasureDistance MeasureDistance





#endif /* RTE_SENSOR_H */

/* End of Rte_Sensor.h */