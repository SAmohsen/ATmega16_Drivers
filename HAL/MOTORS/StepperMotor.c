/*
 * StepperMotor.c
 *
 *  Created on: Nov 11, 2019
 *      Author: sayed
 */

#include "StepperMotor.h"

#ifdef FULL_WAVE_MODE
unsigned char motor_steps[FULL_WAVE_STEPS] = {12,6,3,9};
#else
unsigned char motor_steps[HALF_WAVE_STEPS] = {8,12,4,6,2,3,1,9};
#endif

void StepperMotor_Init(){
#ifdef HIGH_NIBBLE
	STEPPERMOTOR_DDR |=0xF0 ;
#else
	STEPPERMOTOR_DDR |=0x0F ;
#endif

}

void StepperMotor_Step (uint8 step){
#ifdef HIGH_NIBBLE
	STEPPERMOTOR_PORT = (STEPPERMOTOR_PORT & 0x0F) |((motor_steps[step] & 0x0F)<<4);
#else
	STEPPERMOTOR_PORT = (STEPPERMOTOR_PORT & 0xF0) |(motor_steps[step] & 0x0F);
#endif


}
