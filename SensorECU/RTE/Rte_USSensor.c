/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_USSensor.c                                               */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_USSensor.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*******************************************************************************/
/* Name        : Rte_Call_USSensor_R_IO_GetDistance_S0                         */
/* Param       : P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value      */
/* Return      : FUNC(Std_ReturnType, RTE_CODE)                                */
/* Contents    : This function serves as a wrapper for calling the low-level   */
/*               function `GetDistance_S0`, which retrieves the distance       */
/*               measurement from the ultrasonic sensor (S0).                  */
/* Note        :                                                               */
/*******************************************************************************/
extern FUNC(Std_ReturnType, IoHwAb_CODE) GetDistance_S0( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA));
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S0( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = GetDistance_S0( value );
    return return_value;
}
/*******************************************************************************/
/* Name        : Rte_Call_USSensor_R_IO_GetDistance_S1                         */
/* Param       : P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value      */
/* Return      : FUNC(Std_ReturnType, RTE_CODE)                                */
/* Contents    : This function serves as a wrapper for calling the low-level   */
/*               function `GetDistance_S1`, which retrieves the distance       */
/*               measurement from the ultrasonic sensor (S1).                  */
/* Note        :                                                               */
/*******************************************************************************/

extern FUNC(Std_ReturnType, IoHwAb_CODE) GetDistance_S1( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA));
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S1( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = GetDistance_S1( value );
    return return_value;
}
/*******************************************************************************/
/* Name        : Rte_Call_USSensor_R_IO_GetDistance_S2                         */
/* Param       : P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value      */
/* Return      : FUNC(Std_ReturnType, RTE_CODE)                                */
/* Contents    : This function serves as a wrapper for calling the low-level   */
/*               function `GetDistance_S2`, which retrieves the distance       */
/*               measurement from the ultrasonic sensor (S2).                  */
/* Note        :                                                               */
/*******************************************************************************/
extern FUNC(Std_ReturnType, IoHwAb_CODE) GetDistance_S2( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA));
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S2( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = GetDistance_S2( value );
    return return_value;
}
/*******************************************************************************/
/* Name        : Rte_Call_USSensor_R_IO_GetDistance_S3                         */
/* Param       : P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value      */
/* Return      : FUNC(Std_ReturnType, RTE_CODE)                                */
/* Contents    : This function serves as a wrapper for calling the low-level   */
/*               function `GetDistance_S3`, which retrieves the distance       */
/*               measurement from the ultrasonic sensor (S3).                  */
/* Note        :                                                               */
/*******************************************************************************/
extern FUNC(Std_ReturnType, IoHwAb_CODE) GetDistance_S3( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA));
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S3( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = GetDistance_S3( value );
    return return_value;
}
/********************************************************************************/
/* Name        : Rte_Write_USSensor_P_PP_DistanceUS_SendDistance                */
/* Param       : VAR(DistanceGroup_t, AUTOMATIC) data                           */
/* Return      : FUNC(Std_ReturnType, RTE_CODE)                                 */
/* Contents    : This function is responsible for sending distance measurements */
/*               from the `DistanceGroup_t` structure to the communication      */
/*               module.                                                        */
/* Note        :                                                                */
/********************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_Write_USSensor_P_PP_DistanceUS_SendDistance( VAR(DistanceGroup_t, AUTOMATIC) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(DistanceGroup_t, AUTOMATIC) tmp_data = data;

    Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S0, &tmp_data.Distance_S0 );
    Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S1, &tmp_data.Distance_S1 );
    Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S2, &tmp_data.Distance_S2 );
    Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S3, &tmp_data.Distance_S3 );
    ret = Com_SendSignalGroup(ComConf_ComGroupSignal_ComISignal_HS_CAN1_Distance);

    switch( ret ) {
    case COM_SERVICE_NOT_AVAILABLE:
        ret_val = RTE_E_COM_STOPPED;
        break;
    case COM_BUSY:
        ret_val = RTE_E_COM_BUSY;
        break;
    default:
        /* nothing */
        break;
    }

    return ret_val;
}

/********************************************************************************/
/* Name        : Rte_MeasureDistance                                            */
/* Trigger     :                                                                */
/* Param       : VAR(void, AUTOMATIC)                                           */
/* Return      : FUNC(void, RTE_CODE)                                           */
/* Contents    : This function serves as a wrapper                              */
/* Note        : This function provides a way to integrate the application-level*/
/*               functionality with the RTE, facilitating seamless interaction. */
/********************************************************************************/
extern FUNC(void, AppSensor_CODE) MeasureDistance( VAR(void, AUTOMATIC) );
FUNC(void, RTE_CODE) Rte_MeasureDistance( VAR(void, AUTOMATIC) ) {

    MeasureDistance();

}

/********************************************************************************/
/* Name        : Rte_USSensorInit                                               */
/* Trigger     :                                                                */
/* Param       : VAR(void, AUTOMATIC)                                           */
/* Return      : FUNC(void, RTE_CODE)                                           */
/* Contents    : This function serves as a wrapper                              */
/* Note        : This function provides a way to integrate the application-level*/
/*               functionality with the RTE, facilitating seamless interaction. */
/********************************************************************************/
extern FUNC(void, AppSensor_CODE) USSensorInit( VAR(void, AUTOMATIC) );
FUNC(void, RTE_CODE) Rte_USSensorInit( VAR(void, AUTOMATIC) ) {

    USSensorInit();

}