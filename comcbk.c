/*CALLBACK CỦA NHẬN VÀ GỬI */
//notification = callback 
//callout thông báo lớp app , đã có dữ liệu, check các thứ pdur
//app sẽ đọc các signal từ các hàm notification này 

//lưu các signal vào các global của rte 
//message là 1 mảng ký tự 
//lấy signal ra 
//trc đó có unpacking

//nhận cái message, signalgroup
FUNC(void,RTE_CODE) Rte_COMCbk(void){

    if(Rte_InitState == RTE_STATE_INIT)
    {   
        //multicore
        (void)GetSpinlock(Rte_Spinlock_igLOT_Message_Rx);
        //khác message
        (void)Com_ReceiveSignalGroup(ComConf_ComGroupSignal_igLOT_Message_Rx);
        (void)Com_ReceiveSignal(ComConf_ComGroupSignal_isLOT_Message_Speed_Rx,&(*(&RTE_igLOT_Message_Rx)).LOT_Message_Speed);
        (void)Com_ReceiveSignal(ComConf_ComGroupSignal_isLOT_Message_Spray_Rx,&(*(&RTE_igLOT_Message_Rx)).LOT_Message_Spray);
        
        (void)ReleaseSpinlock(Rte_Spinlock_igLOT_Message_Rx);
        //only set os event
        (void)SetEvent(Os_CE_Receive_Signal);
    }
}

//2 callback cho 2 signal 
//1 callback 