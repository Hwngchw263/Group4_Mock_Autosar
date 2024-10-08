#include "WiperLevel_SWC.h"
#include "Rte_WiperLevelDio.h"

// Main function to read binary data and control the wiper and spray
FUNC(void, WiperLevelDio_CODE) Runnable_ReadUserInput_100ms(VAR(void, AUTOMATIC)) {
    int rawData;              // Raw binary data from the input port
    WiperLeverDataType leverData; // Structure to hold the processed data

    /* Start read data from Ecu Abstraaction through RTE */
    // Read the raw binary data from the input port
    Rte_Call_R_IO__IoHwAb_Q_DioReadChannelGroup(1, &rawData);
    // Decode the raw binary data
    leverData.wiperMode = WIPERMODE(rawData);            // Extract bits 0-1 for wiper mode
    leverData.sprayActive = SPRAYACTIVE(rawData);   // Extract bit 2 for spray status
    
    Rte_Write_P_Position_WiperLeverData(leverData);
}
