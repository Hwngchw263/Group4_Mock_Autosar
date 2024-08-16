#include"SprayFluid_SWC.h"
#include"Rte_SprayFluid.h"

FUNC(void,SprayFluid_CODE) Runnable_SprayFluid(VAR(void,AUTOMATIC)){
	
	VAR(boolean,AUTOMATIC) spray;
	//Checkpoint start
	Rte_Call_WdgM_CheckpointReached(SE_TP_SprayFluid,CP_ID_3);
	Rte_Read_R_FluidMotor_WiperControlSprayData(&spray);
	static uint8 level = 0;
	if(spray == TRUE){
		level = 1;	
	}
	Rte_Call_R_IO__IoHwAb_Q_DioWriteChannel(1, level); 
	//Checkpoint end
	Rte_Call_WdgM_CheckpointReached(SE_TP_SprayFluid,CP_ID_4); 	
}