/*
 * LED.c
 *
 *  Created on: Sep 24, 2019
 *      Author: sayed
 */

#include "LED.h"


void LED_init(void){
SET_BIT(LED_PORT_DIR,LED_PIN);
CLR_BIT(LED_PORT,LED_PIN);
}

void LED_On(void){
	SET_BIT(LED_PORT,LED_PIN);
}
void LED_Off(void){
	CLR_BIT(LED_PORT,LED_PIN);
}

uint8 LED_State(void){
	uint8 state = READ_BIT(LED_PORT,LED_PIN);
	return state ;

}


