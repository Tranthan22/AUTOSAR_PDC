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
// #include "Os.h"
// #include "Rte_Internal.h"
// #include "Com.h"
#include "Rte_AppSensor.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

extern FUNC(Std_ReturnType, IoHwAb_CODE) IoHwAb_Q_SensorGet( VAR(AppIo_IoHwAb_Q_SensorIdType, AUTOMATIC), P2VAR(AppIo_IoHwAb_SensorValueGroupType, AUTOMATIC, RTE_APPL_DATA));
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
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_AppSensor_R_AppSensorToIoHwAb_IoHwAb_Q_SensorGet( VAR(AppIo_IoHwAb_Q_AdcIdType, AUTOMATIC) id, P2VAR(AppIo_IoHwAb_AdcValueGroupType, AUTOMATIC, RTE_APPL_DATA) value) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = IoHwAb_Q_SensorGet( id, value );
    return return_value;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0


/**********************************  Section 2 ******************************* */
extern FUNC(void, AppAdc_CODE) AppAdc_10ms( VAR(void, AUTOMATIC) );
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