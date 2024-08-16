#ifndef RTE_SPRAY_FLUID_H
#define RTE_SPRAY_FLUID_H
#include <stdint.h>
#include<stdbool.h>
#include<Rte_DataHandleType.h>


FUNC(void,RTE_CODE) Rte_COMCbk_Signal_Spray_Rx(VAR(void,AUTOMATIC));

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_SprayFluid_R_FluidMotor_WiperControlSprayData( P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_R_FluidMotor_WiperControlSprayData Rte_Read_SprayFluid_R_FluidMotor_WiperControlSprayData

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_SprayFluidDio_R_IO__IoHwAb_Q_DioWriteChannel(P2VAR(AppIo_IoHwAb_Q_DioIdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_DioLevelType, AUTOMATIC) level )
#define Rte_Call_R_IO__IoHwAb_Q_DioWriteChannel Rte_Call_SprayFluidDio_R_IO__IoHwAb_Q_DioWriteChannel


#endif