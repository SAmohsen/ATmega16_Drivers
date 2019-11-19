/*
 * LCD_cfg.h
 *
 *  Created on: Nov 11, 2019
 *      Author: sayed
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

#include "../../micro_config.h"

//#define LCD_4BIT_MODE
//#define LCD_8BIT_MODE

/*low nibble is not working */
//#define HIGH_NIBBLE

#define LCD_DATA_PORT PORTC
#define LCD_DATA_DDR  DDRC

#define LCD_CONTROL_PORT PORTD
#define LCD_CONTROL_DDR DDRD

#define LCD_RS PD4
#define LCD_RW PD5
#define LCD_E PD7

#endif /* HAL_LCD_LCD_CFG_H_ */
