/*
 * LED.h
 *
 *  Created on: Sep 24, 2019
 *      Author: sayed
 */

#ifndef LED_LED_H_
#define LED_LED_H_

#include "../../std_types.h"
#include "../../common_marcos.h"
#include  "../../micro_config.h"
#include "LED_cfg.h"

void LED_init(void);

void LED_On(void);

void LED_Off(void);

uint8 LED_State(void) ;

#endif /* LED_LED_H_ */
