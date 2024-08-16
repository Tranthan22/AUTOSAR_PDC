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
VAR(DistanceGroup_t, AUTOMATIC) Rte_Read_PDC_Control_DistanceGroup_Value;
VAR(Std_ReturnType, AUTOMATIC) Rte_Read_PDC_Control_Value_status = RTE_E_NEVER_RECEIVED;

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_ParkDistanceControl_R_RP_DistanceUS_ReadDistance( P2VAR(pDistanceGroup_t, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    data->Distance_S0 = Rte_Read_PDC_Control_DistanceGroup_Value.Distance_S0;
    data->Distance_S1 = Rte_Read_PDC_Control_DistanceGroup_Value.Distance_S1;
    data->Distance_S2 = Rte_Read_PDC_Control_DistanceGroup_Value.Distance_S2;
    data->Distance_S3 = Rte_Read_PDC_Control_DistanceGroup_Value.Distance_S3;
    ret_val = Rte_Read_PDC_Control_Value_status;
    RTE_Q_UNLOCK();

    

    return ret_val;
} 

/******************************************************************************/

/******************************************************************************/
VAR(AlarmLevel_uint8_t, AUTOMATIC) Rte_Read_AlarmSystem_AlarmLevel_Value;
VAR(Std_ReturnType, AUTOMATIC) Rte_Read_AlarmSystem_AlarmLevel_status = RTE_E_NEVER_RECEIVED;

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_ParkDistanceControl_P_PP_Alarm_SendAlarmLevel( VAR(AlarmLevel_uint8_t, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;

    RTE_Q_LOCK();
    Rte_Read_AlarmSystem_AlarmLevel_Value = data;
    Rte_Read_AlarmSystem_AlarmLevel_status = RTE_E_OK;
    RTE_Q_UNLOCK();

    return ret_val;
}


/**********************************  Section 2 ******************************* */
extern FUNC(void, AppControl_CODE) ProcessControl( VAR(void, AUTOMATIC) );

FUNC(void, RTE_CODE) Rte_ProcessControl( VAR(void, AUTOMATIC) ) {

    ProcessControl();

}
