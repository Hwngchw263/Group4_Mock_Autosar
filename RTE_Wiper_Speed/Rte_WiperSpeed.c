#include<Rte_WiperSpeed.h>
extern uint8_t value_speed;
Std_ReturnType Rte_Read_RP_Speed_Motor_Speed(uint8_t* speed){
        *speed = value_speed;
        return RTE_E_OK;
       
}
	//transfer
Std_ReturnType	Rte_Call_R_IO_ActivateSpeed(uint8_t speed){
        ActivateSpeed(speed);
        return RTE_E_OK;
     
}

// FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_R_IO_ActivateSpeed( VAR(uint8_t speed) {
//     ActivateSpeed(speed);
//     return RTE_E_OK;
// }