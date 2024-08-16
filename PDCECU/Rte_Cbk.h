/******************************************************************************/
/* System Name : Park Distance Control                                        */
/* File Name   : Rte_Cbk.h                                                   */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : HN24_FR_AUTOSAR_02_Group_3                                   */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_CBK_H
#define RTE_CBK_H

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
FUNC(void, RTE_CODE) Rte_COMCbk_ComISignal_RP_DistanceUS( VAR(void, AUTOMATIC) );

FUNC(void, RTE_CODE) Rte_COMCbk_ComISignal_RP_PDCService( VAR(void, AUTOMATIC) );


#endif /* RTE_CBK_H */

/* End of Rte_Cbk.h */
