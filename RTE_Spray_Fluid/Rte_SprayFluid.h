#ifndef RTE_SPRAY_FLUID_H
#define RTE_SPRAY_FLUID_H
#include <stdint.h>
#include<stdbool.h>
#define RTE_E_OK        0x00       // Giá trị trả về khi thực hiện thành công
#define RTE_E_NOT_OK    0x01  

bool value_spray;

typedef uint8_t Std_ReturnType; 

Std_ReturnType Rte_Read_RP_Fluid_Motor(bool* spray);

Std_ReturnType Rte_Call_R_IO_ActivateSpray(bool spray);	

#endif