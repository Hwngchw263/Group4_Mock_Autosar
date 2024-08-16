#include"Rte_WiperSpeed.h"

/*****************************************************************************************/
/* ModuleID    :                                                                         */
/* ServiceID   :                                                                         */
/* Name        :  Rte_Call_WiperSpeedDio_R_IO__IoHwAb_Q_PwmSetDutyCycle                  */
/* Param       :                                                                         */
/* Return      :                                                                         */
/* Contents    : Ecu Configuration(Ecuc)                                                 */
/* Author      : Group 4                                                                 */
/* Note        :                                                                         */
/*****************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_WiperSpeedDio_R_IO__IoHwAb_Q_PwmSetDutyCycle(P2VAR(AppIo_IoHwAb_Q_DioIdType, AUTOMATIC) id, VAR(AUTOSAR_uint16, AUTOMATIC) duty_cycle )
{
    IoHwAb_Q_PwmSetDutyCycle(id,duty_cycle);
    return RTE_E_OK;
}


#define RTE_START_SEC_VAR_INIT
#include "Rte_MemMap.h"
VAR(AUTOSAR_uint8, AUTOMATIC) Rte_Read_WiperSpeed_R_SpeedMotor_WiperControlSpeedData_value;
#define RTE_STOP_SEC_VAR_INIT

#define RTE_START_SEC_VAR_EcucPartition_0_INIT
#include "Rte_MemMap.h"
VAR(Std_ReturnType, AUTOMATIC) Rte_Read_WiperSpeed_R_SpeedMotor_WiperControlSpeedData_status = RTE_E_NEVER_RECEIVED;
#define RTE_STOP_SEC_VAR_EcucPartition_0_INIT
#include "Rte_MemMap.h"
/*****************************************************************************************/
/* ModuleID    :                                                                         */
/* ServiceID   :                                                                         */
/* Name        :  Rte_COMCbk_igLOT_Signal_Speed_Rx                                       */
/* Param       :                                                                         */
/* Return      :                                                                         */
/* Contents    : Ecu Configuration(Ecuc)                                                 */
/* Author      : Group 4                                                                 */
/* Note        :                                                                         */
/*****************************************************************************************/
FUNC(void,RTE_CODE) Rte_COMCbk_Signal_Speed_Rx(VAR(void,AUTOMATIC)){

    if(Rte_InitState == RTE_STATE_INIT)
    {   
        //receive signal
        (void)Com_ReceiveSignal(ComConf_ComSignal_Signal_Speed_Rx,&Rte_Read_WiperSpeed_R_SpeedMotor_WiperControlSpeedData_value);
        //only set os event
        (void)SetEvent(Acuator Task,Os_CE_Receive_Signal);
    }
}

/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Read_WiperSpeed_R_SpeedMotor_WiperControlSpeedData       */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_WiperSpeed_R_SpeedMotor_WiperControlSpeedData( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    *data = Rte_Read_WiperSpeed_R_SpeedMotor_WiperControlSpeedData_value;
    ret_val = Rte_Read_WiperSpeed_R_SpeedMotor_WiperControlSpeedData_status;
    RTE_Q_UNLOCK();

    return ret_val;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

FUNC(void,SprayFluid_CODE) Runnable_WiperSpeed(VAR(void,AUTOMATIC))
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_ReadUserInput_100ms                                      */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_WiperSpeed(VAR(void, AUTOMATIC)) {
   Runnable_WiperSpeed();
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"


