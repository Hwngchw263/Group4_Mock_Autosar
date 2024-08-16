#include "Rte_WiperControl.h"

bool active;
VAR(WiperLeverDataType, AUTOMATIC) Rte_Read_WiperControl_LevelData;


/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Write_AppComTxRx_P_ActuatorFluidControl_SprayFluid       */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_P_ActuatorFluidControl_SprayFluid(VAR(bool, AUTOMATIC) in) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(bool, AUTOMATIC) tmp_data = in;
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
/* Name        : Rte_Write_AppComTxRx_P_ActuatorWiperControl_WiperSpeed       */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_P_ActuatorWiperControl_WiperSpeed(VAR(AUTOSAR_uint8, AUTOMATIC) in) {
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


FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_R_Setting_WiperLeverData( P2VAR(WiperLeverDataType, AUTOMATIC, RTE_APPL_DATA) out) {
    *out = Rte_Read_WiperControl_LevelData;
    return RTE_E_OK;
}