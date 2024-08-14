#include<Rte_WiperSpeed.h>
extern uint8_t value_speed;
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_RP_Speed_Motor_Speed(uint8_t* speed){
        *speed = value_speed;
        return RTE_E_OK;
       
}
	//transfer
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_R_IO_ActivateSpeed(VAR(AUTOSAR_uint8, AUTOMATIC) id,P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) speed){
        VAR(Std_ReturnType, AUTOMATIC) return_value;
        return_value = ActivateSpeed(id,speed);
        return return_value;
     
}

// FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_R_IO_ActivateSpeed( VAR(uint8_t speed) {
//     ActivateSpeed(speed);
//     return RTE_E_OK;
// }
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

FUNC(void,SprayFluid_CODE) Runnable_WiperSpeed(VAR(void,AUTOMATIC))
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
FUNC(void, RTE_CODE_EcucPartition_0) Rte_WiperSpeed(VAR(void, AUTOMATIC)) {
   Runnable_WiperSpeed();
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"



/* End of Rte_WiperLevelDio.c */