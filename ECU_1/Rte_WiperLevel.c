/******************************************************************************/
/* Copyright   :                                                              */
/* System Name :                                                              */
/* File Name   : Rte_WiperLevel.c                                             */
/* Version     : v1.0.0                                                       */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Hung                                                         */
/* Note        :                                                              */
/******************************************************************************/

/*----------------------------------------------------------------------------*/
/* include headers                                                            */
/*----------------------------------------------------------------------------*/
#include "Rte_WiperLevel.h"
extern int ReadData(int start_id, int end_id);
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Call_R_IO_ReadData                                       */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Hung                                                         */
/* Note        :                                                              */
/******************************************************************************/
int value;
Std_ReturnType Rte_Call_R_IO_ReadData(int start_id, int end_id, int *out)
{
    *out = ReadData(start_id, end_id);
    return RTE_E_OK;
}
/******************************************************************************/
/* ModuleID    :                                                              */
/* ServiceID   :                                                              */
/* Name        : Rte_Write_P_Position_WiperLeverData                          */
/* Param       :                                                              */
/* Return      :                                                              */
/* Contents    : Ecu Configuration(Ecuc)                                      */
/* Author      : Hung                                                         */
/* Note        :                                                              */
/******************************************************************************/
Std_ReturnType Rte_Write_P_Position_WiperLeverData(int in)
{
    value = in;
    //Set event
    //DataReceivedFlag = 1;
    return RTE_E_OK;
}