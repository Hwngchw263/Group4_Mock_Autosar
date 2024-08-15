  // Giá trị trả về khi có lỗi
#ifndef RTE_WIPER_SPEED_H
#define RTE_WIPER_SPEED_H
#include <stdint.h>

#define RTE_E_OK        0x00       // Giá trị trả về khi thực hiện thành công
#define RTE_E_NOT_OK    0x01  
extern uint8_t value_speed;
typedef uint8_t Std_ReturnType; 

FUNC(void,RTE_CODE) Rte_COMCbk_igLOT_Signal_Speed_Rx(VAR(void,AUTOMATIC));

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_WiperSpeed_Sig_Speed( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_WiperSpeed_Sig_Speed Rte_Read_AppComTxRx_WiperSpeed_Sig_Speed

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_WiperSpeedDio_R_IO__IoHwAb_Q_PwmSetDutyCycle(P2VAR(AppIo_IoHwAb_Q_DioIdType, AUTOMATIC) id, VAR(AUTOSAR_uint16, AUTOMATIC) duty_cycle )


#endif
