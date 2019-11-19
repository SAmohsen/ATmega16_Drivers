/*
 * UART.c
 *
 *  Created on: Nov 13, 2019
 *      Author: sayed
 */


#include "UART.h"

void Uart_Init(Uart_ConfigChannel *Config_PTr){
	if (Config_PTr !=NULL_PTR)
	{

		/*Writing in USRC*/
		SET_BIT(UCSRC,URSEL);
		/*Asynchronous Mode */
		CLR_BIT(UCSRC,UMSEL);

		switch(Config_PTr->parity_mode)
		{
		case no_parity:CLR_BIT(UCSRC,UPM0);
		 	 	 	   CLR_BIT(UCSRC,UPM1);

		break;
		case even_parity:CLR_BIT(UCSRC,UPM0);
						 SET_BIT(UCSRC,UPM1);

		break;
		case Odd_pariy:SET_BIT(UCSRC,UPM0);
					   SET_BIT(UCSRC,UPM1);
		break;
		}

		switch(Config_PTr->stop_bit){
		case One_Stop_Bit :CLR_BIT(UCSRC,USBS);
		break ;
		case Two_Stop_Bits :SET_BIT(UCSRC,USBS);
		break;
		}


		switch (Config_PTr->length) {
		case data_5:
			CLR_BIT(UCSRC, UCSZ0);
			CLR_BIT(UCSRC, UCSZ1);
			CLR_BIT(UCSRB, UCSZ2);

			break;
		case data_6:
			SET_BIT(UCSRC, UCSZ0);
			CLR_BIT(UCSRC, UCSZ1);
			CLR_BIT(UCSRB, UCSZ2);
			break;
		case data_7:

			CLR_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			CLR_BIT(UCSRB, UCSZ2);
			break;
		case data_8:
			SET_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			CLR_BIT(UCSRB, UCSZ2);
			break;
		case data_9:
			SET_BIT(UCSRC, UCSZ0);
			SET_BIT(UCSRC, UCSZ1);
			SET_BIT(UCSRB, UCSZ2);
			break;
		}
/*
		switch(Config_PTr->clock){
			case Uart_Falling_Edge :SET_BIT(UCSRC,UCPOL);
			break ;
			case Uart_Rissing_Edge :CLR_BIT(UCSRC,UCPOL);
			break;
			}
			*/
		/*transmitter Enable */
		SET_BIT(UCSRB,TXEN);
		/*Receiver Enable */
		SET_BIT(UCSRB,RXEN);

		switch (Config_PTr->speed)
		{
		case normal_speed:CLR_BIT(UCSRA, U2X);
		break;
		case double_speed:SET_BIT(UCSRA, U2X);
		break;
		}

		/*Baud rate Select */
		uint16 desired_baudRate ;
		if (normal_speed==Config_PTr->speed)
		{
			desired_baudRate = (((F_CPU)/(16UL * Config_PTr->baudrate) )-1);

		}
		else if (double_speed == Config_PTr->speed)
		{
			desired_baudRate =(((F_CPU)/(8UL * Config_PTr->baudrate) )-1);
		}
		else
		{

		}
		UBRRH = desired_baudRate>>8;
		UBRRL = desired_baudRate ;
	}

	else
	{

	}
}
void Uart_SendU8Data(uint8 data){
UDR = data;
while (BIT_IS_CLEAR(UCSRA,TXC));
SET_BIT(UCSRA,TXC);
}
uint8 Uart_RecieveU8Data(){
while (BIT_IS_CLEAR(UCSRA,RXC));
return UDR ;
}

void Uart_SendString(uint8 *str){
	uint8 itr = 0 ;
	while (str[itr]!='\0'){
		Uart_SendU8Data(str[itr]);
		itr++;
	}
}
void Uart_RecieveString(uint8 *str){
	uint8 itr = 0 ;
	while (str[itr]!='#'){
		str[itr] = Uart_RecieveU8Data();
		itr++;
	}
	str[itr]='\0';
}
