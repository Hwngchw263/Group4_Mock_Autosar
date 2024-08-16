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
extern VAR(uint8, AUTOMATIC) Rte_partition_status_EcucPartition_0;
extern VAR(boolean, AUTOMATIC) RTE_CE_WiperMode;
extern VAR(boolean, AUTOMATIC) RTE_CE_SprayFluidMode;
extern VAR(boolean, AUTOMATIC) RTE_TE_Read_100ms;

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_ReadUserInput_100ms(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_ProcessWiperMode(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_ProcessSprayFluid(VAR(void, AUTOMATIC));
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : ProcessTask                                                  */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

TASK(ProcessTask)
{
    VAR(EventMaskType, AUTOMATIC) Event;
	
	for(;;)
	{
		(VAR(void, AUTOMATIC))WaitEvent(Os_TE_Wiper_Level_100ms);
		Event = 0U;
		(VAR(void, AUTOMATIC))GetEvent(ProcessTask, &Event);

		if((Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_EcucPartition_0 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN)) {
			if((Event & Os_TE_Wiper_Level_100ms) > 0U) {
				ClearEvent(Os_TE_Wiper_Level_100ms);
				if( Event & Os_TE_Wiper_Level_100ms)
				{
					Rte_ReadUserInput_100ms();		
				}
				if(RTE_CE_WiperMode == TRUE)
				{
					Rte_ProcessWiperMode();
					RTE_CE_WiperMode = FALSE;
				}
				if(RTE_CE_SprayFluidMode == TRUE)
				{
					Rte_ProcessSprayFluid();
					RTE_CE_SprayFluidMode = FALSE; 
				}
			} else {
              /* No treatment */
            }
		}  else {
            (VAR(void, AUTOMATIC))ClearEvent( Event );
        }
   }
}