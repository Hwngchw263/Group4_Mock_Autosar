#ifndef WIPER_LEVER_CONTROL_H
#define WIPER_LEVER_CONTROL_H

#include "Rte_WiperLevel_Type.h" 

// Function prototypes
FUNC(void, WiperControl_CODE) Runnable_ProcessWiperMode(VAR(void, AUTOMATIC));
FUNC(void, WiperControl_CODE) Runnable_ProcessWiperSpeed(VAR(void, AUTOMATIC));

#endif /* WIPER_LEVER_CONTROL_H */