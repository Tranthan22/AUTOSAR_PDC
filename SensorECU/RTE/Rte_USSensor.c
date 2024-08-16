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

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
extern FUNC(Std_ReturnType, IoHwAb_CODE) GetDistance_S0( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA));
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S0( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = GetDistance_S0( value );
    return return_value;
}

extern FUNC(Std_ReturnType, IoHwAb_CODE) GetDistance_S1( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA));
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S1( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = GetDistance_S1( value );
    return return_value;
}

extern FUNC(Std_ReturnType, IoHwAb_CODE) GetDistance_S2( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA));
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S2( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = GetDistance_S2( value );
    return return_value;
}

extern FUNC(Std_ReturnType, IoHwAb_CODE) GetDistance_S3( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA));
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_USSensor_R_IO_GetDistance_S3( P2VAR(pUSSensor_uint8_t, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = GetDistance_S3( value );
    return return_value;
}

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


/**********************************  Section 2 ******************************* */
extern FUNC(void, AppSensor_CODE) MeasureDistance( VAR(void, AUTOMATIC) );
FUNC(void, RTE_CODE) Rte_MeasureDistance( VAR(void, AUTOMATIC) ) {

    MeasureDistance();

}