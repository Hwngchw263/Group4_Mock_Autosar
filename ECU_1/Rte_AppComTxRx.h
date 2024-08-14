#ifndef RTE_COM_RXTX_H
#define RTE_COM_RXTX_H



//signal speed

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_WiperControl_Sig_SpeedId( VAR(AUTOSAR_uint16, AUTOMATIC) data );
#define Rte_Write_WiperControl_Sig_SpeedId Rte_Write_AppComTxRx_WiperControl_Sig_SpeedId
//signal spray
extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_WiperControl_Sig_SprayId( VAR(AUTOSAR_uint16, AUTOMATIC) data );
#define Rte_Write_WiperControl_Sig_SprayId Rte_Write_AppComTxRx_WiperControl_Sig_SprayId

//define Rte runnable for appcomtxrx
#define AppComTxRx_START_SEC_CODE
#include "AppComTxRx_MemMap.h"
FUNC(void, AppComTxRx_CODE) App_ComTxRx( VAR(void, AUTOMATIC) );
#define AppComTxRx_STOP_SEC_CODE
#include "AppComTxRx_MemMap.h"
#define RTE_RUNNABLE_Run_AppComTxRx App_ComTxRx

#endif