/******************************************************************************/
/* Copyright   : Group 3 Corporation                                          */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_AppSensor.c                                              */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Tran Than                                                    */
/* Note        :                                                              */
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_USSensor.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/
VAR(AUTOSAR_uint8, AUTOMATIC) ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S1;
VAR(AUTOSAR_uint8, AUTOMATIC) ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S2;
VAR(AUTOSAR_uint8, AUTOMATIC) ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S3;
VAR(AUTOSAR_uint8, AUTOMATIC) ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S4;

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetDistance( VAR(AppIo_IoHwAb_SensorIdType, AUTOMATIC), P2VAR(AppIo_IoHwAb_SensorValueGroupType, AUTOMATIC, RTE_APPL_DATA));
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_USSensor_R_IO_GetDistance( VAR(USSensor_IoHwAb_SensorIdType, AUTOMATIC) id, P2VAR(USSensor_uint8p, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_GetDistance( id , value );
    return return_value;
}


FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_USSensor_P_PP_DistanceUS_SendDistance_S1( VAR(USSensor_uint8, AUTOMATIC) value ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(AUTOSAR_uint8, AUTOMATIC) tmp_data = data;

    ret = Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S1, &tmp_data );
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
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_USSensor_P_PP_DistanceUS_SendDistance_S2( VAR(USSensor_uint8, AUTOMATIC) value ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(AUTOSAR_uint8, AUTOMATIC) tmp_data = data;

    ret = Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S2, &tmp_data );
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
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_USSensor_P_PP_DistanceUS_SendDistance_S3( VAR(USSensor_uint8, AUTOMATIC) value ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(AUTOSAR_uint8, AUTOMATIC) tmp_data = data;

    ret = Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S3, &tmp_data );
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
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_USSensor_P_PP_DistanceUS_SendDistance_S4( VAR(USSensor_uint8, AUTOMATIC) value ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(AUTOSAR_uint8, AUTOMATIC) tmp_data = data;

    ret = Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S4, &tmp_data );
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



/**********************************  Section 2 ******************************* */
extern FUNC(void, USSensor_CODE) MeasureDistance( VAR(void, AUTOMATIC) );
FUNC(void, RTE_CODE_EcucPartition_0) Rte_MeasureDistance( VAR(void, AUTOMATIC) ) {

    MeasureDistance();

}