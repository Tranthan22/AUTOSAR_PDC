/******************************************************************************/
/* Copyright   : Group 3 Corporation                                          */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_PDC_Control.c                                              */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Ngoc Nguyen                                                    */
/* Note        :                                                              */
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_PDC_Control.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/
/*
*/
/******************************************************************************/

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_ReadDistanceUS( VAR(AlarmSystem_uint8, AUTOMATIC, RTE_APPL_DATA) );

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistanceUS( VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distanceUS ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_ReadDistanceUS( distanceUS );
    return return_value;
} 

/******************************************************************************/
/*
*/
/******************************************************************************/

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_WriteDistancetoAlarm( VAR(AlarmSystem_uint8, AUTOMATIC, RTE_APPL_DATA) );

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_ParkDistanceControl_P_PP_Alarm_SendDistancetoAlarm( VAR(ParkDistanceControl_uint8, AUTOMATIC, RTE_APPL_DATA) distance_to_alarm ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_WriteDistancetoAlarm( distance_to_alarm );
    return return_value;
}


/**********************************  Section 2 ******************************* */
extern FUNC(void, AppAlarm_CODE) ProcessControl( VAR(void, AUTOMATIC) );

FUNC(void, RTE_CODE_EcucPartition_0) Rte_ProcessControl( VAR(void, AUTOMATIC) ) {

    PDCService();

}
