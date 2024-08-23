#ifndef WIPERLEVEL_SWC_H
#define WIPERLEVEL_SWC_H

// Macro for bit field
#define WIPER_MODEBIT 0x03
#define SPRAY_FLUIDBIT 0x04

// Macro for bit shift
#define SPRAY_FLUIDBIT_SHIFT 0x02
#define WIPER_MODEBIT_SHIFT 0x00

//Macro like function for get mode
#define WIPERMODE(data) ((data & WIPER_MODEBIT) >> WIPER_MODEBIT_SHIFT)
#define SPRAYACTIVE(data) ((data & SPRAY_FLUIDBIT) >> SPRAY_FLUIDBIT_SHIFT)

// Function prototypes
FUNC(void, WiperLevelDio_CODE) Runnable_ReadUserInput_100ms(FUNC(void, AUTOMATIC));

#endif // WIPERLEVEL_SWC_H
