/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_Cbk.c                                                   */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_Type.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/

/*******************************************************************************/
/* Name        : Rte_COMCbk_ComISignal_RP_DistanceUS                           */
/* Trigger     :                                                               */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      : FUNC(void, RTE_CODE)                                          */
/* Contents    : This function handles the reception of the signal group       */
/*               related to the distance measurement from the CAN bus. It      */
/*               performs the following steps:                                 */
/*               1. Receives the signal group from the I-PDU and stores it     */
/*                  into a shadow buffer.                                      */
/*               2. Copies individual signals from the shadow buffer to the    */
/*                  appropriate positions in the `DistanceGroup` structure.    */
/*               3. Updates the status to indicate successful reception of     */
/*                  the distance control data.                                 */
/*               4. Triggers an event to notify that distance data has been    */
/*                  received.                                                  */
/* Note        : The function uses external variables to store the distance    */
/*               group data and update the status. It also triggers a specific */
/*               event to handle the received data further.                    */
/*******************************************************************************/
extern VAR(DistanceGroup_t, AUTOMATIC) Rte_Read_PDC_Control_DistanceGroup_Value;
extern VAR(Std_ReturnType, AUTOMATIC) Rte_Read_PDC_Control_Value_status;

FUNC(void, RTE_CODE) Rte_COMCbk_ComISignal_RP_DistanceUS( VAR(void, AUTOMATIC) ) {
    //Copy the received signal group from the I-PDU to the shadow buffer.
    VAR(void, AUTOMATIC)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_ComISignal_HS_CAN1_Distance);

    //Copy the data of the signal from the shadow buffer to the referenced position
    VAR(void, AUTOMATIC)Com_ReceiveSignal(ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S0, &DistanceGroup.Distance_S1);
    VAR(void, AUTOMATIC)Com_ReceiveSignal(ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S1, &DistanceGroup.Distance_S1);
    VAR(void, AUTOMATIC)Com_ReceiveSignal(ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S2, &DistanceGroup.Distance_S3);
    VAR(void, AUTOMATIC)Com_ReceiveSignal(ComConf_ComSignal_ComISignal_HS_CAN1_Distance_S3, &DistanceGroup.Distance_S4);

    Rte_Read_PDC_Control_Value_status = RTE_E_OK;

    //Set event CE_DistanceDataReceived
    VAR(void, AUTOMATIC)SetEvent(DistanceAlarmTask, OS_CE_DistanceDataReceived);
}
/*******************************************************************************/
/* Name        : Rte_COMCbk_ComISignal_RP_PDCService                           */
/* Trigger     :                                                               */
/* Param       : VAR(void, AUTOMATIC)                                          */
/* Return      : FUNC(void, RTE_CODE)                                          */
/* Contents    : This function handles the reception of the PDC (Park Distance */
/*               Control) service status signal from the CAN bus. The function */
/*               performs the following steps:                                 */
/*               1. Receives the PDC service status signal from the CAN bus    */
/*                  and stores it in a local variable.                         */
/*               2. If the reception is successful (indicated by `E_OK`), the  */
/*                  function locks the RTE queue, updates the service status   */
/*                  and value, and then unlocks the RTE queue.                 */
/*               3. Triggers an event (`OS_CE_PDCService`) to notify the       */
/*                  system that the PDC service status has been received and   */
/*                  updated.                                                   */
/* Note        : The function uses external variables to store the PDC service */
/*               status and value, and it ensures thread-safe access by        */
/*               locking and unlocking the RTE queue during the update.        */
/*******************************************************************************/

extern VAR(PDC_Status_uint8_t, AUTOMATIC) Rte_Read_PDC_Service_active_Value;
extern VAR(Std_ReturnType, AUTOMATIC) Rte_Read_PDC_Service_active_status;

FUNC(void, RTE_CODE) Rte_COMCbk_ComISignal_RP_PDCService( VAR(void, AUTOMATIC) ) {
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(PDC_Status_uint8_t, AUTOMATIC) data = 0;

    ret = VAR(void, AUTOMATIC)Com_ReceiveSignal(ComConf_ComSignal_ComISignal_HS_CAN1_Service, &data);
    if( ret == E_OK ) {
        RTE_Q_LOCK();
        
        Rte_Read_PDC_Service_Service_Value = data;
        Rte_Read_PDC_Service_Service_status = RTE_E_OK;

        RTE_Q_UNLOCK();
    }
    VAR(void, AUTOMATIC)SetEvent(DistanceAlarmTask, OS_CE_PDCService);
}