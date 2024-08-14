#include<SprayFluid_SWC.h>

FUNC(void,SprayFluid_CODE) Runnable_SprayFluid(VAR(void,AUTOMATIC)){
	bool spray;
	Rte_Read_RP_Fluid_Motor(& spray);
	Rte_Call_R_IO_ActivateSpray(spray);	
}