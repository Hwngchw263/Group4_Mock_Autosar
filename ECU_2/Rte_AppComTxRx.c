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

