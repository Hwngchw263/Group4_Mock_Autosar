#include<Rte_SprayFluid.h>
#include <stdint.h>

extern bool value_spray;


Std_ReturnType Rte_Read_RP_Fluid_Motor(bool* spray){
    *spray = value_spray;
    return RTE_E_OK;
}
Std_ReturnType Rte_Call_R_IO_ActivateSpray(bool spray){
    ActivateSpray(spray);
    return RTE_E_OK;
}
// FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_R_IO_ActivateSpray(bool spray) {
//     ActivateSpray(spray);
//     return RTE_E_OK;
// }	
