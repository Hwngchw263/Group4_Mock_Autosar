/******************************************************************************/
/* Copyright   :                                                              */
/* System Name :                                                              */
/* File Name   : Rte_WiperLevel.c                                             */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_WiperLevelDio.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/
VAR(boolean, AUTOMATIC) RTE_CE_WiperMode;
VAR(boolean, AUTOMATIC) RTE_CE_SprayFluidMode;

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
extern FUNC(AppIo_IoHwAb_DioLevelGroupType, IoHwAb_CODE) IoHwAb_Q_DioReadChannelGroup(P2VAR(AppIo_IoHwAb_Q_DioIdType, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Call_WiperLevelDio_R_IO__IoHwAb_Q_DioReadChannelGroup    */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_WiperLevelDio_R_IO__IoHwAb_Q_DioReadChannelGroup(VAR(AppIo_IoHwAb_Q_DioChannelGroupType, AUTOMATIC) Group_id, P2VAR(AppIo_IoHwAb_DioLevelGroupType, AUTOMATIC, RTE_APPL_DATA) value )
{
    *value = IoHwAb_Q_DioReadChannelGroup(Group_id);
    return RTE_E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Write_WiperLevelDio_P_Position_WiperLeverData            */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_WiperLevelDio_P_Position_WiperLeverData(VAR(WiperLeverDataType, AUTOMATIC) data)
{
    VAR(WiperLeverDataType, AUTOMATIC) tmp_data = data;
    //Set event
    RTE_CE_WiperMode = TRUE;
    RTE_CE_SprayFluidMode = TRUE;
    return RTE_E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, WiperLevelDio_CODE) Runnable_ReadUserInput_100ms(VAR(void, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_ReadUserInput_100ms                                      */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_ReadUserInput_100ms(VAR(void, AUTOMATIC)) {

    Runnable_ReadUserInput_100ms();

}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"



/* End of Rte_WiperLevelDio.c */