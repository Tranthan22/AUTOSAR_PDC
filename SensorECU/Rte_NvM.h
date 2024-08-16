/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_NvM.h                                                    */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_NVM_H
#define RTE_NVM_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_Service_Writeblock_NVM_Sensor( P2CONST(void, AUTOMATIC, RTE_APPL_DATA) data );

FUNC(Std_ReturnType, RTE_CODE) Rte_Call_NvM_Service_Readblock_NVM_Sensor( P2VAR(void, AUTOMATIC, RTE_APPL_DATA) data );

#endif /* RTE_NVM_H */

/* End of Rte_NvM.h */
