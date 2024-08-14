#ifndef RTE_WIPERLEVEL_H
#define RTE_WIPERLEVEL_H

#include <stdint.h>
#include "WiperLevel_SWC.h"

#define RTE_E_OK        0x00      
#define RTE_E_NOT_OK    0x01 
typedef uint8_t Std_ReturnType;

Std_ReturnType Rte_Call_R_IO_ReadData(int start_id, int end_id, int *out);
void Rte_Write_P_Position_WiperLeverData(WiperLeverDataType in);

#endif