#include<Rte_SprayFluid.h>

/*****************************************************************************************/
/* ModuleID    :                                                                         */
/* ServiceID   :                                                                         */
/* Name        :  Rte_Call_SprayFluidDio_R_IO__IoHwAb_Q_DioWriteChannel                  */
/* Param       :                                                                         */
/* Return      :                                                                         */
/* Contents    : Ecu Configuration(Ecuc)                                                 */
/* Author      : Group 4                                                                 */
/* Note        :                                                                         */
/*****************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_SprayFluidDio_R_IO__IoHwAb_Q_DioWriteChannel(P2VAR(AppIo_IoHwAb_Q_DioIdType, AUTOMATIC) id, VAR(AppIo_IoHwAb_DioLevelType, AUTOMATIC) level )
{
    IoHwAb_Q_DioWriteChannelGroup(id,level);
    return RTE_E_OK;
}

//callback and read to receive data 
#define RTE_START_SEC_VAR_INIT
#include "Rte_MemMap.h"
VAR(boolean, AUTOMATIC) Rte_Read_SprayFluid_R_FluidMotor_value;
#define RTE_STOP_SEC_VAR_INIT

#define RTE_START_SEC_VAR_EcucPartition_0_INIT
#include "Rte_MemMap.h"
VAR(Std_ReturnType, AUTOMATIC) Rte_Read_SprayFluid_R_FluidMotor_status = RTE_E_NEVER_RECEIVED;
#define RTE_STOP_SEC_VAR_EcucPartition_0_INIT
#include "Rte_MemMap.h"

/*****************************************************************************************/
/* ModuleID    :                                                                         */
/* ServiceID   :                                                                         */
/* Name        :  Rte_COMCbk_Signal_Spray_Rx                                             */
/* Param       :                                                                         */
/* Return      :                                                                         */
/* Contents    : Ecu Configuration(Ecuc)                                                 */
/* Author      : Group 4                                                                 */
/* Note        :                                                                         */
/*****************************************************************************************/
FUNC(void,RTE_CODE) Rte_COMCbk_Signal_Spray_Rx(VAR(void,AUTOMATIC)){

    if(Rte_InitState == RTE_STATE_INIT)
    {   
        //receiver signal
        (void)Com_ReceiveSignal(ComConf_ComSignal_Signal_Spray_Rx,&Rte_Read_SprayFluid_R_FluidMotor_value);
        //only set os event
        (void)SetEvent(Acuator Task,Os_CE_Receive_Signal);
    }
}

/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Read_SprayFluid_R_FluidMotor                             */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_SprayFluid_R_FluidMotor( P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) data ) {
    VAR(Std_ReturnType, AUTOMATIC) ret_val;

    RTE_Q_LOCK();
    *data = Rte_Read_SprayFluid_R_FluidMotor_value;
    ret_val = Rte_Read_SprayFluid_R_FluidMotor_status;
    RTE_Q_UNLOCK();

    return ret_val;
}




#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void,SprayFluid_CODE) Runnable_SprayFluid(VAR(void,AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_SprayFluid                                               */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"
FUNC(void, RTE_CODE_EcucPartition_0) Rte_SprayFluid(VAR(void, AUTOMATIC)) {
    Runnable_SprayFluid();
}
#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"



