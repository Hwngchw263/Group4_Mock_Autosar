#include "WiperLevel_SWC.h"
#include "Rte_WiperLevel.h"

// Main function to read binary data and control the wiper and spray
void HandleUserInput(void) {
    int rawData;              // Raw binary data from the input port
    WiperLeverDataType leverData; // Structure to hold the processed data

    /* Start read data from Ecu Abstraaction through RTE */
    // Read the raw binary data from the input port
    Rte_Call_R_IO_Dio_ReadData(1, 4, &rawData);
    // Decode the raw binary data
    leverData.wiperMode = rawData & 0x03;            // Extract bits 0-1 for wiper mode
    leverData.sprayActive = (rawData & 0x04) >> 2;   // Extract bit 2 for spray status
    
    Rte_Write_P_Position_WiperLeverData(leverData);
}
