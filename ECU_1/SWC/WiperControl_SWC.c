#include "WiperControl_SWC.h"
#include "Rte_WiperControl.h"


// Main function for the wiper control logic
FUNC(void, WiperControl_CODE) Runnable_ProcessWiperMode(VAR(void, AUTOMATIC)) {
     WiperLeverDataType leverData;  // Structure to hold the combined data

    // CheckPoint Start 
    Rte_Call_WdgM_CheckpointReached(SE_TP_ProcessWiperMode, CP_ID_3);

    // Read the combined wiper mode and spray status from the input port
    Rte_Read_R_Setting_WiperLeverData(&leverData);

    // Process the inputs and control the wiper system
    switch (leverData.wiperMode) {
        case WIPER_MODE_OFF:
            // Stop the wiper motor
            Rte_Write_P_ActuatorWiperControl_WiperSpeed(OFF_SPEED);
            break;
            
        case WIPER_MODE_LOW:
            // Set wiper motor to low speed
           Rte_Write_P_ActuatorWiperControl_WiperSpeed(MEDIUM_SPEED);
            break;

        case WIPER_MODE_HIGH:
            // Set wiper motor to high speed
           Rte_Write_P_ActuatorWiperControl_WiperSpeed(MAX_SPEED);
            break;

        default:
            // Handle unexpected mode
           Rte_Write_P_ActuatorWiperControl_WiperSpeed(OFF_SPEED);
            break;
    }
    //CheckPoint end
    Rte_Call_WdgM_CheckpointReached(SE_TP_ProcessWiperMode, CP_ID_4);
}

FUNC(void, WiperControl_CODE) Runnable_ProcessSprayFluid(VAR(void, AUTOMATIC)) {
    WiperLeverDataType leverData;  // Structure to hold the combined data

    //CheckPoint start
    Rte_Call_WdgM_CheckpointReached(SE_TP_ProcessSprayFluid, CP_ID_5);

    // Read the combined wiper mode and spray status from the input port
    Rte_Read_R_Setting_WiperLeverData(&leverData);

    // Control the spray fluid pump if spray is active
    if (leverData.sprayActive) {
        Rte_Write_P_ActuatorFluidControl_SprayFluid(TRUE);
    } else {
        Rte_Write_P_ActuatorFluidControl_SprayFluid(FALSE);
    }
    //CheckPoint end
    Rte_Call_WdgM_CheckpointReached(SE_TP_ProcessSprayFluid, CP_ID_6);
}