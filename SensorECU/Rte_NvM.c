/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_NvM.c                                                    */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern NvM_Writeblock_NVM_Sensor ( VAR(NvM_BlockIdType, AUTOMATIC), P2CONST(void, AUTOMATIC, RTE_APPL_DATA) );

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_Service_Writeblock_NVM_Sensor( P2CONST(void, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = NvM_Writeblock_NVM_Sensor( NVM_Sensor_ID, data );
    return return_value;
}

extern NvM_Readblock_NVM_Sensor ( VAR(NvM_BlockIdType, AUTOMATIC), P2VAR(void, AUTOMATIC, RTE_APPL_DATA) );

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_Service_Readblock_NVM_Sensor( P2VAR(void, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) return_value;

    return_value = NvM_Writeblock_NVM_Sensor( NVM_Sensor_ID, data );
    return return_value;
}
