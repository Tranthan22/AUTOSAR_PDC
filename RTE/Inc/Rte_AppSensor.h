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
#include "Rte_Sensor_Type.h"
#include "Rte_DataHandleType.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppSensor_R_AppSensorToIoHwAb_IoHwAb_Q_SensorGet( VAR(AppIo_IoHwAb_Q_SensorIdType, AUTOMATIC) id, P2VAR(AppIo_IoHwAb_Q_SensorGroupStatusType, AUTOMATIC, RTE_APPL_DATA) value );
#define Rte_Call_R_AppSensorToIoHwAb_IoHwAb_Q_SensorGet Rte_Call_AppSensor_R_AppSensorToIoHwAb_IoHwAb_Q_SensorGet


#define AppSensor_START_SEC_CODE
#include "AppSensor_MemMap.h"
FUNC(void, AppSensor_CODE) MeasureDistance( VAR(void, AUTOMATIC) );
#define AppSensor_STOP_SEC_CODE
#define RTE_RUNNABLE_Run_MeasureDistance MeasureDistance





#endif /* RTE_SENSOR_H */

/* End of Rte_Sensor.h */