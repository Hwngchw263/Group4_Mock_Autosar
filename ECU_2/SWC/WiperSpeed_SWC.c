#include<WiperSpeed_SWC.h>
/*****************************************************************************************/
/* ModuleID    :                                                                         */
/* ServiceID   :                                                                         */
/* Name        :  Runnable_WiperSpeed                                                    */
/* Param       :                                                                         */
/* Return      :                                                                         */
/* Contents    : Ecu Configuration(Ecuc)                                                 */
/* Author      : Group 4                                                                 */
/* Note        :                                                                         */
/*****************************************************************************************/
FUNC(void,SprayFluid_CODE) Runnable_WiperSpeed(VAR(void,AUTOMATIC)){
	uint8_t speed;
	//Checkpoint start
	Rte_Call_WdgM_CheckpointReached(SE_TP_WiperSpeed,CP_ID_1);
	//rp port
	Rte_Read_WiperSpeed_R_SpeedMotor(&speed);
	VAR(AUTOSAR_uint16,AUTOMATIC) Duty_Cycle;
		switch (speed)
		{
			case LOW_SPEED:
				Duty_Cycle = LOW_DUTY_CYCLE;
				break;
			case HIGH_SPEED:
				Duty_Cycle= HIGH_DUTY_CYCLE;
				break;
			default:
				Duty_Cycle = 0; // Stop motor
				break;
		}

	Rte_Call_WiperSpeedDio_R_IO__IoHwAb_Q_PwmSetDutyCycle(Duty_Cycle);
	//Checkpoint End
	Rte_Call_WdgM_CheckpointReached(SE_TP_WiperSpeed,CP_ID_2);
}