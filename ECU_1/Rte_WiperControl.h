#ifndef RTE_WIPER_CONTROL_H
#define RTE_WIPER_CONTROL_H

#include "WiperLevel_SWC.h"

#define RTE_E_OK        0x00      
#define RTE_E_NOT_OK    0x01 
typedef uint8_t Std_ReturnType;



extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_P_ActuatorFluidControl_SprayFluid( VAR(MessageSignal, AUTOMATIC) in);
#define Rte_Write_P_ActuatorFluidControl_SprayFluid Rte_Write_AppComTxRx_P_ActuatorFluidControl_SprayFluid

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_P_ActuatorWiperControl_WiperSpeed( VAR(MessageSignal, AUTOMATIC) in);
#define Rte_Write_P_ActuatorWiperControl_WiperSpeed Rte_Write_AppComTxRx_P_ActuatorWiperControl_WiperFluid

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_R_Setting_WiperLeverData( P2VAR(WiperLeverDataType, AUTOMATIC, RTE_APPL_DATA) out);
#define Rte_Read_R_Setting_WiperLeverData Rte_Read_AppComTxRx_R_Setting_WiperLeverData


#endif