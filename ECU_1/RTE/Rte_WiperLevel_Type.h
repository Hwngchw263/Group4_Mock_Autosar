#ifndef WIPERLEVEL_TYPE_H
#define WIPERLEVEL_TYPE_H

// Define possible wiper modes
typedef enum {
    WIPER_MODE_OFF,
    WIPER_MODE_LOW,
    WIPER_MODE_HIGH
} WiperModeType;

// Combined data structure for wiper mode and spray status
typedef struct {
    WiperModeType wiperMode;  // Wiper mode
    boolean sprayActive;       // Spray activation status
} WiperLeverDataType;

#endif // WIPERLEVEL_TYPE_H