#include "SWC_WiperControl.h"
#include "Rte_WiperControl.h"


// Main function for the wiper control logic
FUNC(void, WiperControl_CODE) Runnable_ProcessWiperMode(VAR(void, AUTOMATIC)) {
     WiperLeverDataType leverData;  // Structure to hold the combined data

    // Read the combined wiper mode and spray status from the input port
    Rte_Read_R_Setting_WiperLeverData(&leverData);

    // Process the inputs and control the wiper system
    switch (leverData.wiperMode) {
        case WIPER_MODE_OFF:
            // Stop the wiper motor
            Rte_Write_P_ActuatorWiperControl_WiperSpeed(0);
            break;
            
        case WIPER_MODE_LOW:
            // Set wiper motor to low speed
           Rte_Write_P_ActuatorWiperControl_WiperSpeed(50);
            break;

        case WIPER_MODE_HIGH:
            // Set wiper motor to high speed
           Rte_Write_P_ActuatorWiperControl_WiperSpeed(75);
            break;

        default:
            // Handle unexpected mode
           Rte_Write_P_ActuatorWiperControl_WiperSpeed(0);
            break;
    }
}

FUNC(void, WiperControl_CODE) Runnable_ProcessSprayFluid(VAR(void, AUTOMATIC)) {
     WiperLeverDataType leverData;  // Structure to hold the combined data

    // Read the combined wiper mode and spray status from the input port
    Rte_Read_R_Setting_WiperLeverData(&leverData);

    // Control the spray fluid pump if spray is active
    if (leverData.sprayActive) {
        Rte_Write_P_ActuatorFluidControl_SprayFluid(TRUE);
    } else {
        Rte_Write_P_ActuatorFluidControl_SprayFluid(FALSE);
    }
}