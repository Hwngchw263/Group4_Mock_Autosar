#include<WiperSpeed_SWC.h>
FUNC(void,SprayFluid_CODE) Runnable_WiperSpeed(VAR(void,AUTOMATIC)){
	uint8_t speed;
	//rp port
	Rte_Read_RP_Speed_Motor_Speed(&speed);
	//transfer
	Rte_Call_R_IO_ActivateSpeed(speed);
}