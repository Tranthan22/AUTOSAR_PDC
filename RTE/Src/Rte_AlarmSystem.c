/******************************************************************************/
/* Copyright   : Group 3 Corporation                                          */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_AlarmSystem.c                                              */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Tran Than                                                    */
/* Note        :                                                              */
/******************************************************************************/


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_AlarmSystem.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_GetDistance( VAR(AppIo_IoHwAb_SensorIdType, AUTOMATIC), P2VAR(AppIo_IoHwAb_SensorValueGroupType, AUTOMATIC, RTE_APPL_DATA));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Call_USSensor_R_IO_GetDistance                           */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 3                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AlarmSystem_R_IO_WarningAlarm( VAR(AlarmSystem_IoHwAb_AlarmLevel, AUTOMATIC) alarm_level) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_SendAlarmLevel( alarm_level );
    return return_value;
}


#define RTE_STOP_SEC_CODE_EcucPartition_0


extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_SendDistance( VAR(AppIo_IoHwAb_SensorIdType, AUTOMATIC), P2VAR(AppIo_IoHwAb_SensorValueGroupType, AUTOMATIC, RTE_APPL_DATA));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Call_AppAdc_R_App_AdcToIoHwAb_IoHwAb_Q_SensorGet         */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 3                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_USSensor_R_IO_SensorGet( VAR(USSensor_IoHwAb_SensorIdType, AUTOMATIC) id, P2VAR(USSensor_uint8p, AUTOMATIC, RTE_APPL_DATA) value ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_Q_SensorGet( id , value );
    return return_value;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0

/**********************************  Section 2 ******************************* */
extern FUNC(void, AppAdc_CODE) MeasureDistance( VAR(void, AUTOMATIC) );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_MeasureDistance                                              */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 3                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_MeasureDistance( VAR(void, AUTOMATIC) ) {

    MeasureDistance();

}
#define RTE_STOP_SEC_CODE_EcucPartition_0