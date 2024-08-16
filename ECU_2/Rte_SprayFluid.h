#ifndef RTE_SPRAY_FLUID_H
#define RTE_SPRAY_FLUID_H
#include <stdint.h>
#include<stdbool.h>
#define RTE_E_OK        0x00       // Giá trị trả về khi thực hiện thành công
#define RTE_E_NOT_OK    0x01  

bool value_spray;

typedef uint8_t Std_ReturnType; 

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_Fluid_Motor(bool* spray);

//id type : VAR(IOIo_IoHwAb_Q_ActivateSprayIdType, AUTOMATIC) id
//parameter : P2VAR(AUTOSAR_bool, AUTOMATIC, RTE_APPL_DATA) spray
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_R_IO_SprayToIoHwAb_IoHwAb_Q_ActivateSpray(VAR(AUTOSAR_uint8, AUTOMATIC) id,P2VAR(AUTOSAR_bool, AUTOMATIC, RTE_APPL_DATA) spray);

#endif