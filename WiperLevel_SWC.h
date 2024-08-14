#ifndef WIPERLEVEL_SWC_H
#define WIPERLEVEL_SWC_H

#include <stdbool.h>

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

#endif // WIPERLEVEL_SWC_H
