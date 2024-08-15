#ifndef RTE_SPRAY_FLUID_H
#define RTE_SPRAY_FLUID_H
#include <stdint.h>
#include<stdbool.h>
#define RTE_E_OK        0x00       // Giá trị trả về khi thực hiện thành công
#define RTE_E_NOT_OK    0x01  

bool value_spray;

typedef uint8_t Std_ReturnType; 

FUNC(void,RTE_CODE) Rte_COMCbk_Signal_Spray_Rx(VAR(void,AUTOMATIC));

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_R_FluidMotor( P2VAR(bool, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_R_FluidMotor Rte_Read_AppComTxRx_R_FluidMotor


FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_SprayFluidDio_R_IO__IoHwAb_Q_DioWriteChannel(P2VAR(AppIo_IoHwAb_Q_DioIdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_DioLevelType, AUTOMATIC) level )



#endif