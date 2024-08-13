/**
 *
 * \file SWC_HeightMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 4/27/2022 02:48 AM
 *
 */

#include "Rte_SWC_WiperMotor.h"


/**
 *
 * Runnable RE_WiperMotor_Active
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHighthMotor_Opr_WiperMotor_Active
 *
 */

void RE_WiperMotor_Active (Impl_StepMotorStepType Arg_Step)
{
	if(Arg_Step==PLUS)
	{
	  (void)Rte_Call_rpIOSetHeight_Opr_IOSetForward();
	}
	else if(Arg_Step == MINUS)
	{
	  (void)Rte_Call_rpIOSetHeight_Opr_IOSetReverse();
	}
}