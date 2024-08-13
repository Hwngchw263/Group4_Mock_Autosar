  // Giá trị trả về khi có lỗi
#ifndef RTE_WIPER_SPEED_H
#define RTE_WIPER_SPEED_H
#include <stdint.h>

#define RTE_E_OK        0x00       // Giá trị trả về khi thực hiện thành công
#define RTE_E_NOT_OK    0x01  
extern uint8_t value_speed;
typedef uint8_t Std_ReturnType; 

Std_ReturnType Rte_Read_RP_Speed_Motor_Speed(uint8_t* speed);
	//transfer
Std_ReturnType Rte_Call_R_IO_ActivateSpeed(uint8_t speed);

#endif
