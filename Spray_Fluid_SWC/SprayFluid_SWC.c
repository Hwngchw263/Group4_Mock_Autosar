#include<SprayFluid_SWC.h>

void Runnable_SprayFluid(){
	bool spray;
	Rte_Read_RP_Fluid_Motor(& spray);
	Rte_Call_R_IO_ActivateSpray(spray);	
}