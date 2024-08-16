#include<WiperSpeed_SWC.h>
#includeinclude "Rte_WiperSpeed.h"

FUNC(void,SprayFluid_CODE) Runnable_WiperSpeed(VAR(void,AUTOMATIC)){
	uint8_t speed;
	//rp port
	Rte_Read_WiperSpeed_R_WiperMotor_Speed(&speed);
	VAR(AUTOSAR_uint16,AUTOMATIC) Duty_Cycle;
		switch (speed)
		{
			case LOW_SPEED:
				Duty_Cycle = LOW_DUTY_CYCLE;
				break;
			case MEDIUM_SPEED:
				Duty_Cycle = MEDIUM_DUTY_CYCLE;
				break;
			case HIGH_SPEED:
				Duty_Cycle=HIGH_DUTY_CYCLE;
				break;
			default:
				Duty_Cycle = 0; // Stop motor
				break;
		}

	Rte_Call_WiperSpeed_R_IO__IoHwAb_Q_PwmSetDutyCycle(Duty_Cycle);
}