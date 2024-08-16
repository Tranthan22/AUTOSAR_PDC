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
#include "Rte_Type.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

/******************************************************************************/

/******************************************************************************/
extern VAR(DistanceGroup_t, AUTOMATIC) DistanceGroup;
extern VAR(Std_ReturnType, AUTOMATIC) Rte_Read_PDC_Control_Value_status = RTE_E_NEVER_RECEIVED;

extern FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance( P2VAR(pDistanceGroup_t, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    data->Distance_S0 = DistanceGroup.Distance_S0;
    data->Distance_S1 = DistanceGroup.Distance_S1;
    data->Distance_S2 = DistanceGroup.Distance_S2;
    data->Distance_S3 = DistanceGroup.Distance_S3;
    ret_val = Rte_Read_PDC_Control_Value_status;
    RTE_Q_UNLOCK();

    return ret_val;
} 

/******************************************************************************/

/******************************************************************************/
extern VAR(AlarmLevel_uint8_t, AUTOMATIC) Rte_Read_AlarmSystem_AlarmLevel_Value;
extern VAR(Std_ReturnType, AUTOMATIC) Rte_Read_AlarmSystem_AlarmLevel_status = RTE_E_NEVER_RECEIVED;

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ParkDistanceControl_P_PP_Alarm_SendAlarmLevel( VAR(AlarmLevel_uint8_t, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;

    RTE_Q_LOCK();
    Rte_Read_AlarmSystem_AlarmLevel_Value = data;
    Rte_Read_AlarmSystem_AlarmLevel_status = RTE_E_OK;

    RTE_Q_UNLOCK();

    return ret_val;
}


/**********************************  Section 2 ******************************* */
extern FUNC(void, RTE_CODE) ProcessControl( VAR(void, AUTOMATIC) );

FUNC(void, RTE_CODE) Rte_ProcessControl( VAR(void, AUTOMATIC) ) {

    ProcessControl();

}
