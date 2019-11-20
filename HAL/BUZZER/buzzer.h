/*
 * buzzer.h
 *
 *  Created on: Sep 24, 2019
 *      Author: sayed
 */

#ifndef BUZZER_BUZZER_H_
#define BUZZER_BUZZER_H_


#include "../../std_types.h"
#include "../../common_marcos.h"
#include  "../../micro_config.h"
#include "buzzer_cfg.h"

void BUZZER_init(void);

void BUZZER_On(void);

void BUZZER_Off(void);

uint8 BUZZER_State(void) ;


#endif /* BUZZER_BUZZER_H_ */
