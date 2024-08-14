#include<Rte_SprayFluid.h>
#include <stdint.h>
extern bool value_spray;
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_Fluid_Motor(P2VAR(bool* spray){
    *spray = value_spray;
    return RTE_E_OK;
}
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_R_IO_SprayToIoHwAb_IoHwAb_Q_ActivateSpray(VAR(AUTOSAR_uint8, AUTOMATIC) id,P2VAR(AUTOSAR_bool, AUTOMATIC, RTE_APPL_DATA) spray){
    VAR(Std_ReturnType, AUTOMATIC) return_value;
    return_value = ActivateSpray(id,spray);
    return return_value;
}
// FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_R_IO_ActivateSpray(bool spray) {
//     ActivateSpray(spray);
//     return RTE_E_OK;
// }	

#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void,SprayFluid_CODE) Runnable_SprayFluid(VAR(void,AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_ReadUserInput_100ms                                      */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_SprayFluid(VAR(void, AUTOMATIC)) {
    Runnable_SprayFluid();
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"



/* End of Rte_WiperLevelDio.c */