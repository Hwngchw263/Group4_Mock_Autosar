#include<SprayFluid_SWC.h>

FUNC(void,SprayFluid_CODE) Runnable_SprayFluid(VAR(void,AUTOMATIC)){
	VAR(boolean,AUTOMATIC) spray;
	Rte_Read_AppComTxRx_SprayFluid_Sig_Spray(& spray);
	static uint8 level = 0;
	if(spray == TRUE){
		level = 1;	
	}
	Rte_Call_R_IO_ActivateSpray(1, level);
    	
}