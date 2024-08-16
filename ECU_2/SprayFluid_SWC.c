#include<SprayFluid_SWC.h>

FUNC(void,SprayFluid_CODE) Runnable_SprayFluid(VAR(void,AUTOMATIC)){
	
	VAR(boolean,AUTOMATIC) spray;
	Rte_Call_WdgM_CheckpointReached(SE_TP_SprayFluid,CP_ID_3);
	Rte_Read_AppComTxRx_R_FluidMotor(& spray);
	static uint8 level = 0;
	if(spray == TRUE){
		level = 1;	
	}
	Rte_Call_R_IO_ActivateSpray(1, level); 
	Rte_Call_WdgM_CheckpointReached(SE_TP_SprayFluid,CP_ID_4); 	
}