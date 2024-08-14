#ifndef RTE_COM_RXTX_H
#define RTE_COM_RXTX_H

FUNC(void,RTE_CODE) Rte_COMCbk_igLOT_Signal_Speed_Rx(VAR(void,AUTOMATIC));
FUNC(void,RTE_CODE) Rte_COMCbk_Signal_Spray_Rx(VAR(void,AUTOMATIC));

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_WiperSpeed_Sig_Speed( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_WiperSpeed_Sig_Speed Rte_Read_AppComTxRx_WiperSpeed_Sig_Speed

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_SprayFluid_Sig_Spray( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_SprayFluid_Sig_Spray Rte_Read_AppComTxRx_SprayFluid_Sig_Spray

#endif