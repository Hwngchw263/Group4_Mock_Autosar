#include<SprayFluid_SWC.h>
/*****************************************************************************************/
/* ModuleID    :                                                                         */
/* ServiceID   :                                                                         */
/* Name        :  Runnable_SprayFluid                                                    */
/* Param       :                                                                         */
/* Return      :                                                                         */
/* Contents    : Ecu Configuration(Ecuc)                                                 */
/* Author      : Group 4                                                                 */
/* Note        :                                                                         */
/*****************************************************************************************/
FUNC(void,SprayFluid_CODE) Runnable_SprayFluid(VAR(void,AUTOMATIC)){
	
	VAR(boolean,AUTOMATIC) spray;
	//Checkpoint start
	Rte_Call_WdgM_CheckpointReached(SE_TP_SprayFluid,CP_ID_3);
	Rte_Read_SprayFluid_R_FluidMotor_WiperControlSprayData(&spray);
	static uint8 level = 0;
	if(spray == TRUE){
		level = 1;	
	}
	Rte_Call_R_IO_ActivateSpray(1, level); 
	//Checkpoint end
	Rte_Call_WdgM_CheckpointReached(SE_TP_SprayFluid,CP_ID_4); 	
}