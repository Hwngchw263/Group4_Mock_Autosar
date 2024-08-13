#include "SWC_UserControl.h"

// Main function to read binary data and control the wiper and spray
void HandleUserInput(void) {
    uint8_t rawData;              // Raw binary data from the input port
    WiperLeverDataType leverData; // Structure to hold the processed data

    // Read the raw binary data from the input port
    Rte_Read_WiperLeverControlInputPort_RawData(&rawData);

    // Decode the raw binary data
    leverData.wiperMode = rawData & 0x03;            // Extract bits 0-1 for wiper mode
    leverData.sprayActive = (rawData & 0x04) != 0;   // Extract bit 2 for spray status
    
    Rte_Write_WiperLeverControlInputPort_WiperLeverData(&leverData);
}
