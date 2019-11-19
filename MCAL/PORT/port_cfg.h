/*
 * port_cfg.h
 *
 *  Created on: Nov 9, 2019
 *      Author: sayed
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

#include "../../std_types.h"
#include "port.h"

#define PORT_CONFIGURED_CHANNELS (3U)



#define portConf_INT0_CHANNEL1_ID_INDX 0X00
#define portConf_INT0_CHANNEL1_CHANNEL_NUMBER PIN_26
#define portConf_INT0_CHANNEL1_PORT_NUMBER  PORTD_ID
#define portConf_INT0_CHANNEL1_CHANNEL_DIRECTION PORT_PIN_IN
#define portConf_INT0_CHANNEL1_INPUT_PIN_MODE	Enable_Pull_up

#define portConf_INT1_CHANNEL1_ID_INDX 0X01
#define portConf_INT1_CHANNEL1_CHANNEL_NUMBER PIN_27
#define portConf_INT1_CHANNEL1_PORT_NUMBER  PORTD_ID
#define portConf_INT1_CHANNEL1_CHANNEL_DIRECTION PORT_PIN_IN
#define portConf_INT1_CHANNEL1_INPUT_PIN_MODE	Enable_Pull_up

#define portConf_INT2_CHANNEL1_ID_INDX 0X02
#define portConf_INT2_CHANNEL1_CHANNEL_NUMBER PIN_10
#define portConf_INT2_CHANNEL1_PORT_NUMBER  PORTB_ID
#define portConf_INT2_CHANNEL1_CHANNEL_DIRECTION PORT_PIN_IN
#define portConf_INT2_CHANNEL1_INPUT_PIN_MODE	Enable_Pull_up

/*
Spi_configChannel cons = {Msb_first,Spi_Rissing_Edge,SCK_Prescale_4,Spi_normal_speed,Spi_master};
	******* Configure SPI Master Pins *********
	DDRB = DDRB | (1<<PB4);
	DDRB = DDRB | (1<<PB5);
	DDRB = DDRB & ~(1<<PB6);
	DDRB = DDRB | (1<<PB7);

	******* Configure SPI Slave Pins *********

	DDRB = DDRB & (~(1<<PB4));
	DDRB = DDRB & (~(1<<PB5));
	DDRB = DDRB | (1<<PB6);
	DDRB = DDRB & (~(1<<PB7));
*/

#endif /* PORT_CFG_H_ */
