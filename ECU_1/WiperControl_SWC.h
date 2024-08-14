#ifndef WIPER_LEVER_CONTROL_H
#define WIPER_LEVER_CONTROL_H

#include "Rte_WiperLeverControl.h"  // RTE header for the Wiper Lever Control SWC
#include "SWC_UserControl.h"

// Function prototypes
void WiperLeverControl_Init(void);
void WiperLeverControl_MainFunction(void);
void ProcessWiperMode(void);
void ProcessWiperSpeed(void);

#endif /* WIPER_LEVER_CONTROL_H */
