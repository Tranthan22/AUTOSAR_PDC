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
/* type definition                                                            */
/*----------------------------------------------------------------------------*/
typedef uint8_t USSensor_uint8_t;

typedef uint8_t* pUSSensor_uint8_t;

typedef struct {
    USSensor_uint8 Distance_S0;
    USSensor_uint8 Distance_S1;
    USSensor_uint8 Distance_S2;
    USSensor_uint8 Distance_S3;
} DistanceGroup_t;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S0( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value );
#define Rte_Call_R_IO_IO_GetDistance_S0 Rte_Call_USSensor_R_IO_GetDistance_S0

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S1( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value );
#define Rte_Call_R_IO_IO_GetDistance_S1 Rte_Call_USSensor_R_IO_GetDistance_S1

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S2( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value );
#define Rte_Call_R_IO_IO_GetDistance_S2 Rte_Call_USSensor_R_IO_GetDistance_S2

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S3( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value );
#define Rte_Call_R_IO_IO_GetDistance_S3 Rte_Call_USSensor_R_IO_GetDistance_S3

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_USSensor_P_PP_DistanceUS_SendDistance ( VAR(USSensor_uint8_t, AUTOMATIC) data );
#define Rte_Write_P_PP_DistanceUS_SendDistance Rte_Write_USSensor_P_PP_DistanceUS_SendDistance

/*----------------------------------------------------------------------------*/
/* Runnable                                                                   */
/*----------------------------------------------------------------------------*/
FUNC(void, AUTOMATIC) MeasureDistance( VAR(void, AUTOMATIC) );
#define RTE_RUNNABLE_Run_MeasureDistance MeasureDistance

#endif /* RTE_SENSOR_H */

/* End of Rte_Sensor.h */