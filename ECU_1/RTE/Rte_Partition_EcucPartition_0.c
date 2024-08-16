/******************************************************************************/
/* Copyright   : SCSK Corporation                                             */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_Partition_EcucPartition_0.c                              */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                   								      */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_Type.h"

#include "Os.h"
#include "Com.h"
#include "Rte_Internal.h"

/*----------------------------------------------------------------------------*/
/* variables                                                                  */
/*----------------------------------------------------------------------------*/
extern VAR(uint8, AUTOMATIC) Rte_status;
extern VAR(uint8, AUTOMATIC) SchM_status;
extern VAR(boolean, AUTOMATIC) Rte_periodically_event_activation;
extern VAR(boolean, AUTOMATIC) SchM_periodically_event_activation;
extern VAR(uint8, AUTOMATIC) Rte_partition_status_EcucPartition_0;
extern VAR(uint32, AUTOMATIC) Rte_DisableEventList[83];

extern VAR(boolean, AUTOMATIC) RTE_CE_WiperMode;
extern VAR(boolean, AUTOMATIC) RTE_CE_SprayFluidMode;
extern VAR(boolean, AUTOMATIC) RTE_TE_Read_100ms;
/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern void Runnable_ReadUserInput_100ms(void);
extern void Runnable_ProcessWiperMode(void);
extern void Runnable_ProcessSprayFluid(void);
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : ProcessTask                                                */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                   */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

TASK(ProcessTask)
{
    VAR(EventMaskType, AUTOMATIC) ev;
	
	for(;;)
	{
		(VAR(void, AUTOMATIC))WaitEvent(Os_TE_Wiper_Level_100ms);
		Event = 0U;
		(VAR(void, AUTOMATIC))GetEvent(ProcessTask, &ev);

		if((Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_EcucPartition_0 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN)) {
			if((ev & Os_TE_Wiper_Level_100ms) > 0U) {
				ClearEvent(Os_TE_Wiper_Level_100ms);
				if( RTE_TE_Read_100ms == TRUE)
				{
					Runnable_ReadUserInput_100ms();		
				}
				if(RTE_CE_WiperMode == TRUE)
				{
					Runnable_ProcessWiperMode();
				}
				if(RTE_CE_SprayFluidMode == TRUE)
				{
					Runnable_ProcessSprayFluid();
				}
			}
		}
		
   }
}