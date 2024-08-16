/******************************************************************************/
/* Copyright   : SCSK Corporation                                             */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_Type.h                                                   */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator 2019.12 (Java)                          */
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

#endif /* RTE_TYPE_H */

/* End 