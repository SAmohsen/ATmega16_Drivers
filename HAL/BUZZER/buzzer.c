/*
 * buzzer.c
 *
 *  Created on: Sep 24, 2019
 *      Author: sayed
 */

#include "buzzer.h"


void BUZZER_init(void){
SET_BIT(BUZZER_PORT_DIR,BUZZER_PIN);
CLR_BIT(BUZZER_PORT,BUZZER_PIN);
}

void BUZZER_On(void){
	SET_BIT(BUZZER_PORT,BUZZER_PIN);
}
void BUZZER_Off(void){
	CLR_BIT(BUZZER_PORT,BUZZER_PIN);
}

uint8 BUZZER_State(void){
	uint8 state = READ_BIT(BUZZER_PORT,BUZZER_PIN);
	return state ;

}

