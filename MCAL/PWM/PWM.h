/*
 * PWM.h
 *
 *  Created on: Nov 12, 2019
 *      Author: sayed
 */

#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

#include "../../std_types.h"
#include "../../micro_config.h"
#include "../../common_marcos.h"

typedef uint16 Pwm_ChannelType;
//typedef uint16 Pwm_PeriodType ;
typedef uint16 Pwm_DutyCycleType;
typedef enum {
	non_inverting_mode,
	inverting_mode,
}PWM_GenrationMode;

typedef enum {
	Pwm_no_prescale,
	Pwm_Prescale_8,
	Pwm_Prescale_64,
	Pwm_Prescale_256,
	Pwm_Prescale_1024,
}Pwm_PrescaleType;
/*typedef enum{
	Pwm_25,
	Pwm_50,
	Pwm_75,
	Pwm_100,
}Pwm_DutyCycleType;*/
typedef struct {
	PWM_GenrationMode mode;
	Pwm_PrescaleType prescale;
}Pwm_ConfigType;

void Pwm_Init(const Pwm_ConfigType* ConfigPtr );
void Pwm_SetOCR1A( Pwm_DutyCycleType DutyCycle );

#endif /* MCAL_PWM_PWM_H_ */
