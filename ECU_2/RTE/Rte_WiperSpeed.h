 #ifndef RTE_WIPER_SPEED_H
#define RTE_WIPER_SPEED_H 

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "Rte_DataHandleType.h"

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/

FUNC(void,RTE_CODE) Rte_COMCbk_Signal_Speed_Rx(VAR(void,AUTOMATIC));


extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_WiperSpeed_R_SpeedMotor_WiperControlSpeedData( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data );
#define Rte_Read_R_SpeedMotor_WiperControlSpeedData Rte_Read_WiperSpeed_R_SpeedMotor_WiperControlSpeedData

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_WiperSpeedDio_R_IO__IoHwAb_Q_PwmSetDutyCycle(P2VAR(AppIo_IoHwAb_Q_DioIdType, AUTOMATIC) id, VAR(AUTOSAR_uint16, AUTOMATIC) duty_cycle )
#define Rte_Call_R_IO__IoHwAb_Q_PwmSetDutyCycle Rte_Call_WiperSpeedDio_R_IO__IoHwAb_Q_PwmSetDutyCycle

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* RTE_WIPERSPEED_H */

/* End of Rte_WiperSpeed.h */