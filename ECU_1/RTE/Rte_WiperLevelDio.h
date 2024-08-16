#ifndef RTE_WIPERLEVEL_H
#define RTE_WIPERLEVEL_H

#include <stdint.h>
#include "WiperLevel_SWC.h"

FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Call_WiperLevelDio_R_IO__IoHwAb_Q_DioReadChannelGroup(P2VAR(AppIo_IoHwAb_Q_DioIdType, AUTOMATIC) id, P2VAR(AppIo_IoHwAb_DioLevelGroupType, AUTOMATIC, RTE_APPL_DATA) value );
FUNC(Std_ReturnType, RTE_CODE_EcucPartition_0) Rte_Write_WiperLevelDio_P_Position_WiperLeverData(VAR(WiperLeverDataType, AUTOMATIC) data);
#endif