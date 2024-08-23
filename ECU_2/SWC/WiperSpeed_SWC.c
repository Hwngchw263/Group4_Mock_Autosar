#include"WiperSpeed_SWC.h"
#include"Rte_WiperSpeed.h"

FUNC(void,SprayFluid_CODE) Runnable_WiperSpeed(VAR(void,AUTOMATIC)){
	uint8_t speed;
	//Checkpoint start
	Rte_Call_WdgM_CheckpointReached(SE_TP_WiperSpeed,CP_ID_1);
	Rte_Read_R_SpeedMotor_WiperControlSpeedData(&speed);
	VAR(AUTOSAR_uint16,AUTOMATIC) Duty_Cycle;
		switch (speed)
		{
			case ZERO_SPEED:
				Duty_Cycle = ZERO_DUTY_CYCLE;
			case LOW_SPEED:
				Duty_Cycle = LOW_DUTY_CYCLE;
				break;
			case HIGH_SPEED:
				Duty_Cycle = HIGH_DUTY_CYCLE;
				break;
			default:
				Duty_Cycle = ZERO_DUTY_CYCLE; // Stop motor
				break;
		}

	Rte_Call_R_IO__IoHwAb_Q_PwmSetDutyCycle(Duty_Cycle);
	//Checkpoint End
	Rte_Call_WdgM_CheckpointReached(SE_TP_WiperSpeed,CP_ID_2);
}