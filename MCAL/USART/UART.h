/*
 * UART.h
 *
 *  Created on: Nov 13, 2019
 *      Author: sayed
 */

#ifndef MCAL_USART_UART_H_
#define MCAL_USART_UART_H_
#include "../../std_types.h"
#include "../../micro_config.h"
#include "../../common_marcos.h"
typedef uint16 Uart_BaudRateType;
typedef enum {
	no_parity,
	even_parity,
	Odd_pariy
}Uart_ParityBitModeType;

typedef enum {
	One_Stop_Bit,
	Two_Stop_Bits
} Uart_StopBitsType;
/*
typedef enum {
	Uart_Falling_Edge,
	Uart_Rissing_Edge,
} Uart_ClockPloarityType;
*/
typedef enum {
	data_5,
	data_6,
	data_7,
	data_8,
	data_9,
}Uart_FrameLengthType;

typedef enum {
	normal_speed,
	double_speed
}Uart_TransmissionSpeedModeType;

typedef struct {
	Uart_ParityBitModeType parity_mode;
	Uart_StopBitsType stop_bit ;
	//Uart_ClockPloarityType clock;
	Uart_FrameLengthType length;
	Uart_TransmissionSpeedModeType speed;
	Uart_BaudRateType baudrate ;
}Uart_ConfigChannel;
void Uart_Init(Uart_ConfigChannel *Config_PTr) ;
void Uart_SendU8Data(uint8 data);
uint8 Uart_RecieveU8Data();
void Uart_SendString(uint8 *str);
void Uart_RecieveString(uint8 *str);
#endif /* MCAL_USART_UART_H_ */
