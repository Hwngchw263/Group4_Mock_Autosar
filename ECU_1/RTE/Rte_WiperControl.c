/******************************************************************************/
/* Copyright   :                                                              */
/* System Name :                                                              */
/* File Name   : Rte_WiperControl.c                                             */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_WiperControl.h"

VAR(WiperLeverDataType, AUTOMATIC) Rte_Read_WiperControl_LevelData;

/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Write_WiperControl_P_ActuatorFluidControl_SprayFluid     */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_WiperControl_P_ActuatorFluidControl_SprayFluid(VAR(boolean, AUTOMATIC) in) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(boolean, AUTOMATIC) tmp_data = in;
    ret = Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_P_ActuatorFluidControl_SprayFluid, &tmp_data);
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
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Write_WiperControl_P_ActuatorWiperControl_WiperSpeed     */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_WiperControl_P_ActuatorWiperControl_WiperSpeed(VAR(AUTOSAR_uint8, AUTOMATIC) in) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(AUTOSAR_uint8, AUTOMATIC) tmp_data = in;

    ret = Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_P_ActuatorWiperControl_WiperSpeed, &tmp_data );
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
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Read_WiperControl_R_Setting_WiperLeverData               */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_WiperControl_R_Setting_WiperLeverData( P2VAR(WiperLeverDataType, AUTOMATIC, RTE_APPL_DATA) out) {
    *out = Rte_Read_WiperControl_LevelData;
    return RTE_E_OK;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, WiperControl_CODE) Runnable_ProcessWiperMode(VAR(void, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_ProcessWiperMode                                         */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_ProcessWiperMode(VAR(void, AUTOMATIC)) {

    Runnable_ProcessWiperMode();

}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, WiperControl_CODE) Runnable_ProcessSprayFluid(VAR(void, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_ProcessWiperMode                                         */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_ProcessSprayFluid(VAR(void, AUTOMATIC)) {

    Runnable_ProcessSprayFluid();

}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"