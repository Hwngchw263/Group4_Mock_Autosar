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
extern VAR(uint8, AUTOMATIC) Rte_status;
extern VAR(uint8, AUTOMATIC) SchM_status;
extern VAR(boolean, AUTOMATIC) RTE_CE_WiperSpeed;
extern VAR(boolean, AUTOMATIC) RTE_CE_SprayFluidRun;
extern VAR(uint8, AUTOMATIC) Rte_partition_status_EcucPartition_0;

/*----------------------------------------------------------------------------*/
/* functions and function style macros                                        */
/*----------------------------------------------------------------------------*/
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_SprayFluid(VAR(void, AUTOMATIC));
extern FUNC(void, RTE_CODE_EcucPartition_0) Rte_WiperSpeed(VAR(void, AUTOMATIC));

/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : ActuatorTask                                                 */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Group 4                                                      */
/* Note        :                                                              */
/******************************************************************************/
#define RTE_START_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"

TASK (ActuatorTask) {
    VAR(EventMaskType, AUTOMATIC) Event;

    for(;;)
    {
        (VAR(void, AUTOMATIC))WaitEvent( Os_CE_Receive_Signal );
        Event = 0U;
        (VAR(void, AUTOMATIC))GetEvent( Os_CE_Receive_Signal, &Event );

        if( (Rte_status == RTE_STATUS_RUN) && (Rte_partition_status_EcucPartition_0 == RTE_PARTITION_STATUS_RUNNING) && (SchM_status == SCHM_STATUS_RUN) ) {
            if( (Event & Os_CE_Receive_Signal) > 0U ) {
                (VAR(void, AUTOMATIC))ClearEvent( Os_CE_Receive_Signal );

                if ( RTE_CE_WiperSpeed == TRUE ) {
                        Rte_WiperSpeed();
                        RTE_CE_WiperSpeed = FALSE;
                    }
                if ( RTE_CE_SprayFluidRun == TRUE ) {
                        Rte_SprayFluid();
                        RTE_CE_SprayFluidRun = FALSE:
                    }
            } else {
              /* No treatment */
            }
        } else {
            (VAR(void, AUTOMATIC))ClearEvent( Event );
        }
    }
}


#define RTE_STOP_SEC_CODE_EcucPartition_0
#include "Rte_MemMap.h"



/* End of Rte_Partition_EcucPartition_0.c */