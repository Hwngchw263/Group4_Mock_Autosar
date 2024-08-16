#ifndef WIPER_SPEED_H
#define WIPER_SPEED_H
#include<Rte_WiperSpeed.h>
#include <stdint.h>
#include <Rte_DataHandleType.h>
//value for speed mode
#define LOW_SPEED = 50
#define HIGH_SPEED = 75
#define LOW_DUTY_CYCLE = 500
#define HIGH_DUTY_CYCLE = 750


FUNC(void,SprayFluid_CODE) Runnable_WiperSpeed(VAR(void,AUTOMATIC));
#endif