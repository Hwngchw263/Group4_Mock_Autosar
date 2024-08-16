/******************************************************************************/
/* Copyright   : SCSK Corporation                                             */
/* System Name : AUTOSAR BSW                                                  */
/* File Name   : Rte_WiperControl.h                                          */
/* Version     : v2.2.2                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : QINeS Ecuc Generator 2019.12 (Java)                          */
/* Note        :                                                              */
/******************************************************************************/

#ifndef RTE_WIPERCONTROL_H
#define RTE_WIPERCONTROL_H


/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/

#include "Rte_WiperLevel_Type.h"
#include "Rte_DataHandleType.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*----------------------------------------------------------------------------*/
/* function prototype declarations                                            */
/*----------------------------------------------------------------------------*/
extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_WiperControl_P_ActuatorFluidControl_SprayFluid( VAR(AUTOSAR_uint8, AUTOMATIC) in);
#define Rte_Write_P_ActuatorFluidControl_SprayFluid Rte_Write_WiperControl_P_ActuatorFluidControl_SprayFluid

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_WiperControl_P_ActuatorWiperControl_WiperSpeed( VAR(AUTOSAR_uint8, AUTOMATIC) in);
#define Rte_Write_P_ActuatorWiperControl_WiperSpeed Rte_Write_WiperControl_P_ActuatorWiperControl_WiperFluid

extern FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Read_WiperControl_R_Setting_WiperLeverData( P2VAR(WiperLeverDataType, AUTOMATIC, RTE_APPL_DATA) out);
#define Rte_Read_R_Setting_WiperLeverData Rte_Read_WiperControl_R_Setting_WiperLeverData


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */


#endif /* RTE_WIPERCONTROL_H */

/* End of Rte_WiperControl.h */