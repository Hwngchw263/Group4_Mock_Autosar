#include<WiperSpeed_SWC.h>
void Runnable_WiperSpeed(){
	uint8_t speed;
	//rp port
	Rte_Read_RP_Speed_Motor_Speed(&speed);
	//transfer
	Rte_Call_R_IO_ActivateSpeed(speed);
}