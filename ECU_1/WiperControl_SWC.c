#include "SWC_WiperControl.h"

// Initialize the wiper control system
void WiperControl_Init(void) {
    // Initialization code, if any
    // For example, set initial state or mode
}

// Main function for the wiper control logic
void Runnable_ProcessWiperMode(void) {
    WiperLeverDataType leverData;  // Structure to hold the combined data

    // Read the combined wiper mode and spray status from the input port
    Rte_Read_WiperLeverControlInputPort_WiperLeverData(&leverData);

    // Process the inputs and control the wiper system
    switch (leverData.wiperMode) {
        case WIPER_MODE_OFF:
            // Stop the wiper motor
            Rte_Write_WiperControlOutputPort_WiperMotor(0);
            break;

        case WIPER_MODE_INTERMITTENT:
            // Control wiper motor for intermittent mode
            // This could involve timing logic, here simplified
            if (/* timing condition for intermittent wipe */) {
                Rte_Write_WiperControlOutputPort_WiperMotor(50);
            } else {
                Rte_Write_WiperControlOutputPort_WiperMotor(0);
            }
            break;

        case WIPER_MODE_LOW:
            // Set wiper motor to low speed
            Rte_Write_WiperControlOutputPort_WiperMotor(50);
            break;

        case WIPER_MODE_HIGH:
            // Set wiper motor to high speed
            Rte_Write_WiperControlOutputPort_WiperMotor(75);
            break;

        default:
            // Handle unexpected mode
            Rte_Write_WiperControlOutputPort_WiperMotor(0);
            break;
    }
}

void Runnable_ProcessWiperSpeed(void) {
    WiperLeverDataType leverData;  // Structure to hold the combined data

    // Read the combined wiper mode and spray status from the input port
    Rte_Read_WiperLeverControlInputPort_WiperLeverData(&leverData);

    // Control the spray fluid pump if spray is active
    if (leverData.sprayActive) {
        Rte_Write_WiperControlOutputPort_SprayPump(TRUE);
    } else {
        Rte_Write_WiperControlOutputPort_SprayPump(FALSE);
    }
}
