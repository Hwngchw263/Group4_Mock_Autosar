/*CALLBACK CỦA NHẬN VÀ GỬI */
//notification = callback 
//callout thông báo lớp app , đã có dữ liệu, check các thứ pdur
//app sẽ đọc các signal từ các hàm notification này 

//lưu các signal vào các global của rte 
//message là 1 mảng ký tự 
//lấy signal ra 
//trc đó có unpacking
#include <Rte_AppComTxRx.h>
//nhận cái message, signalgroup
FUNC(void,RTE_CODE) Rte_COMCbk_igLOT_Signal_Speed_Rx(VAR(void,AUTOMATIC)){

    if(Rte_InitState == RTE_STATE_INIT)
    {   
        //multicore
        (void)GetSpinlock(Rte_Spinlock_igLOT_Message_Rx);

        //struct save speed message signal
        //PARAMETER 1 : ID signal speed
        (void)Com_ReceiveSignal(ComConf_ComSignal_isLOT_Message_Speed_Rx,value_speed);
        //struct save spray message signal

        
        (void)ReleaseSpinlock(Rte_Spinlock_igLOT_Message_Rx);
        //only set os event
        (void)SetEvent(Acuator Task,Os_CE_Receive_Signal);
    }
}
FUNC(void,RTE_CODE) Rte_COMCbk_Signal_Spray_Rx(VAR(void,AUTOMATIC)){

    if(Rte_InitState == RTE_STATE_INIT)
    {   
        //multicore
        (void)GetSpinlock(Rte_Spinlock_igLOT_Message_Rx);
        
        //struct save spray message signal
        (void)Com_ReceiveSignal(ComConf_ComSignal_isLOT_Message_Spray_Rx,value_spray);
        
        (void)ReleaseSpinlock(Rte_Spinlock_igLOT_Message_Rx);
        //only set os event
        (void)SetEvent(Acuator Task,Os_CE_Receive_Signal);
    }
}

#define RTE_START_SEC_VAR_INIT
#include "Rte_MemMap.h"
VAR(AUTOSAR_uint8, AUTOMATIC) Rte_Read_AppComTxRx_WiperSpeed_Sig_Speed_value;
#define RTE_STOP_SEC_VAR_INIT

#define RTE_START_SEC_VAR_EcucPartition_0_INIT
#include "Rte_MemMap.h"
VAR(Std_ReturnType, AUTOMATIC) Rte_Read_AppComTxRx_WiperSpeed_Sig_Speed_status = RTE_E_NEVER_RECEIVED;
#define RTE_STOP_SEC_VAR_EcucPartition_0_INIT
#include "Rte_MemMap.h"


/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Cmd                    */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_WiperSpeed_Sig_Speed( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    *data = Rte_Read_AppComTxRx_WiperSpeed_Sig_Speed_value;
    ret_val = Rte_Read_AppComTxRx_WiperSpeed_Sig_Speed_status;
    RTE_Q_UNLOCK();

    return ret_val;
}



#define RTE_START_SEC_VAR_INIT
#include "Rte_MemMap.h"
VAR(AUTOSAR_uint8, AUTOMATIC) Rte_Read_AppComTxRx_SprayFluid_Sig_Spray_value;
#define RTE_STOP_SEC_VAR_INIT

#define RTE_START_SEC_VAR_EcucPartition_0_INIT
#include "Rte_MemMap.h"
VAR(Std_ReturnType, AUTOMATIC) Rte_Read_AppComTxRx_SprayFluid_Sig_Spray_status = RTE_E_NEVER_RECEIVED;
#define RTE_STOP_SEC_VAR_EcucPartition_0_INIT
#include "Rte_MemMap.h"


/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Read_AppComTxRx_AtmReq_AtmReq_Sig_Cmd                    */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator(Java)                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_AppComTxRx_SprayFluid_Sig_Spray( P2VAR(AUTOSAR_uint8, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    *data = Rte_Read_AppComTxRx_SprayFluid_Sig_Spray_value;
    ret_val = Rte_Read_AppComTxRx_SprayFluid_Sig_Spray_status;
    RTE_Q_UNLOCK();

    return ret_val;
}