#ifndef WIPERCONTROL_SWC_H
#define WIPERCONTROL_SWC_H

#include "Rte_WiperLevel_Type.h" 

#define OFF_SPEED 0
#define MEDIUM_SPEED 50
#define MAX_SPEED 75

// Function prototypes
FUNC(void, WiperControl_CODE) Runnable_ProcessWiperMode(VAR(void, AUTOMATIC));
FUNC(void, WiperControl_CODE) Runnable_ProcessWiperSpeed(VAR(void, AUTOMATIC));

#endif /* WIPERCONTROL_SWC_H */