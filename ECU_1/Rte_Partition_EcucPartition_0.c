/******************************************************************************/
/* Copyright   : SCSK Corporation                                             */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_Partition_EcucPartition_0.c                              */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator 2019.12 (Java)                          */
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

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/

#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_ReadUserInput_100ms(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_ProcessWiperMode(FUNC(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_ProcessSprayFluid(FUNC(void, AUTOMATIC));
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
    EventMaskType ev;
	for(;;)
	{
		WaitEvent(RTE_TE_Read_100ms|RTE_CE_WiperMode|RTE_CE_SprayFluidMode);
		GetEvent(ProcessTask, &ev);
		ClearEvent(Event& (RTE_TE_Read_100ms|RTE_CE_WiperMode|RTE_CE_SprayFluidMode));
		if((ev & RTE_TE_Read_100ms) != (EventMaskType)0)
		{
			Rte_ReadUserInput_100ms();		
		}
		if((ev & RTE_CE_WiperMode) != (EventMaskType)0)
		{
			Rte_ProcessWiperMode();
		}
		if((ev & RTE_CE_SprayFluidMode) != (EventMaskType)0)
		{
			Rte_ProcessSprayFluid();
		}
		
   }
}