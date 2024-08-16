/*CALLBACK CỦA NHẬN VÀ GỬI */
//notification = callback 
//callout thông báo lớp app , đã có dữ liệu, check các thứ pdur
//app sẽ đọc các signal từ các hàm notification này 

//lưu các signal vào các global của rte 
//message là 1 mảng ký tự 
//lấy signal ra 
//trc đó có unpacking
#include <Rte_AppComTxRx.h>


/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Write_AppComTxRx_WiperControl_Sig_SpeedId                */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_WiperControl_Sig_SpeedId( VAR(AUTOSAR_uint16, AUTOMATIC) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(AUTOSAR_uint8, AUTOMATIC) tmp_data = data;

    ret = Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_WiperControl_Sig_SpeedId, &tmp_data );
    switch( ret ) {
    case COM_SERVICE_NOT_AVAILABLE:
        ret_val = RTE_E_COM_STOPPED;
        break;
    case COM_BUSY:
        ret_val = RTE_E_COM_BUSY;
        break;
    default:
        /* nothing */
        break;
    }

    return ret_val;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"


/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Write_AppComTxRx_WiperControl_Sig_SprayId                */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_AppComTxRx_WiperControl_Sig_SprayId( VAR(AUTOSAR_uint16, AUTOMATIC) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val = RTE_E_OK;
    VAR(Std_ReturnType, AUTOMATIC) ret;
    VAR(AUTOSAR_uint8, AUTOMATIC) tmp_data = data;

    ret = Com_SendSignal( ComConf_ComSignal_ComISignal_HS_CAN1_AtmResp_WiperControl_SprayId, &tmp_data );
    switch( ret ) {
    case COM_SERVICE_NOT_AVAILABLE:
        ret_val = RTE_E_COM_STOPPED;
        break;
    case COM_BUSY:
        ret_val = RTE_E_COM_BUSY;
        break;
    default:
        /* nothing */
        break;
    }

    return ret_val;
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"


extern FUNC(void, AppComTxRx_CODE) App_ComTxRx( VAR(void, AUTOMATIC) );
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_App_ComTxRx                                              */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_App_ComTxRx( VAR(void, AUTOMATIC) ) {

    App_ComTxRx();

}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"