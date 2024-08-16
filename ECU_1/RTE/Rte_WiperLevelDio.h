/******************************************************************************/
/* Copyright   : SCSK Corporation                                             */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_WiperLevelDio.h                                                 */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator 2019.12 (Java)                          */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_WIPERLEVEL_H
#define RTE_WIPERLEVEL_H


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "WiperLevel_SWC.h"


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define RTE_E_OK        0x00      
#define RTE_E_NOT_OK    0x01 
typedef uint8_t Std_ReturnType;

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/


extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_WiperLevelDio_R_IO__IoHwAb_Q_DioReadChannelGroup(VAR(AppIo_IoHwAb_Q_DioChannelGroupType, AUTOMATIC) Group_id, P2VAR(AppIo_IoHwAb_DioLevelGroupType, AUTOMATIC, RTE_APPL_DATA) value );
#define Rte_Call_R_IO__IoHwAb_Q_DioReadChannelGroup Rte_Call_WiperLevelDio_R_IO__IoHwAb_Q_DioReadChannelGroup

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_WiperLevelDio_P_Position_WiperLeverData(VAR(WiperLeverDataType, AUTOMATIC) data);
#define Rte_Write_P_Position_WiperLeverData Rte_Write_WiperLevelDio_P_Position_WiperLeverData

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* RTE_WIPERLEVEL_H */

/* End of Rte_WiperLevel.h */