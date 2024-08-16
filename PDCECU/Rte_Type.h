/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_Type.h                                                   */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_TYPE_H
#define RTE_TYPE_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "stdint.h"

/*----------------------------------------------------------------------------*/
/* type definitions                                                           */
/*----------------------------------------------------------------------------*/

typedef uint8_t USSensor_uint8_t;

typedef uint8_t* pUSSensor_uint8_t;

typedef struct {
    USSensor_uint8_t Distance_S0;
    USSensor_uint8_t Distance_S1;
    USSensor_uint8_t Distance_S2;
    USSensor_uint8_t Distance_S3;
} DistanceGroup_t;

typedef DistanceGroup_t* pDistanceGroup_t;

typedef uint8_t AlarmLevel_uint8_t;

typedef uint8_t PDC_Status_uint8_t;

#endif /* RTE_TYPE_H */

/* End 