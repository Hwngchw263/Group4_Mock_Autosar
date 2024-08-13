#ifndef USERCONTROL_H
#define USERCONTROL_H

#include "Rte_Type.h"

// Define possible wiper modes
typedef enum {
    WIPER_MODE_OFF,
    WIPER_MODE_INTERMITTENT,
    WIPER_MODE_LOW,
    WIPER_MODE_HIGH
} WiperModeType;

// Combined data structure for wiper mode and spray status
typedef struct {
    WiperModeType wiperMode;  // Wiper mode
    bool sprayActive;       // Spray activation status
} WiperLeverDataType;

void HandleUserInput(void);

#endif // USERCONTROL_H
