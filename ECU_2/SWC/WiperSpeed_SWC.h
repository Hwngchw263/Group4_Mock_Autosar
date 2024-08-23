#ifndef WIPER_SPEED_H
#define WIPER_SPEED_H

//value for speed mode
#define ZERO_SPEED 0
#define LOW_SPEED  50
#define HIGH_SPEED  75
#define ZERO_DUTY_CYCLE 0
#define LOW_DUTY_CYCLE  50
#define HIGH_DUTY_CYCLE  100


FUNC(void,SprayFluid_CODE) Runnable_WiperSpeed(VAR(void,AUTOMATIC));
#endif