/*
 * PWM.c
 *
 *  Created on: Nov 12, 2019
 *      Author: sayed
 */

#include "PWM.h"

static Pwm_ConfigType *Pwm_configurChannel = NULL_PTR;

void Pwm_Init(const Pwm_ConfigType *config_Ptr) {
	if (NULL_PTR != config_Ptr)
	{
		Pwm_configurChannel=config_Ptr;
		if (channelA == Pwm_configurChannel->pwmchannel)
		{
			OCR1A = Pwm_configurChannel->compareValue;/*set compare Value*/
			/*Set Channel Wave Generation Mode*/
			switch (Pwm_configurChannel->genrationmode)
			{
			case non_inverting_mode:SET_BIT(TCCR1A, COM1A1);
									CLR_BIT(TCCR1A, COM1A0);
			break;

			case inverting_mode:SET_BIT(TCCR1A, COM1A1);
				                SET_BIT(TCCR1A, COM1A0);
			break;
			}


		}
		else if(ChannelB==Pwm_configurChannel->pwmchannel)
		{
			OCR1B = Pwm_configurChannel->compareValue;/*set compare Value*/
			/*Set Channel Wave Generation Mode*/
			switch (Pwm_configurChannel->genrationmode)
			{
			case non_inverting_mode:SET_BIT(TCCR1A,COM1B1);
									CLR_BIT(TCCR1A,COM1B0);
			break;

			case inverting_mode:SET_BIT(TCCR1A,COM1B1);
								SET_BIT(TCCR1A,COM1B0);
			break;
			}

		}
		else
		{
			/*no Action Required*/
		}
		/*set PWM Top Value*/
		if (FastPwm == Pwm_configurChannel->pwmMode) {
			switch (Pwm_configurChannel->top) {
			case pwm_top_255:
				SET_BIT(TCCR1A, WGM10);
				CLR_BIT(TCCR1A, WGM11);
				SET_BIT(TCCR1B, WGM12);
				CLR_BIT(TCCR1B, WGM13);
				break;
			case pwm_top_511:
				CLR_BIT(TCCR1A, WGM10);
				SET_BIT(TCCR1A, WGM11);
				SET_BIT(TCCR1B, WGM12);
				CLR_BIT(TCCR1B, WGM13);
				break;
			case pwm_top_1023:
				SET_BIT(TCCR1A, WGM10);
				SET_BIT(TCCR1A, WGM11);
				SET_BIT(TCCR1B, WGM12);
				CLR_BIT(TCCR1B, WGM13);
				break;
			case pwm_top_ICR1:
				CLR_BIT(TCCR1A, WGM10);
				SET_BIT(TCCR1A, WGM11);
				SET_BIT(TCCR1B, WGM12);
				SET_BIT(TCCR1B, WGM13);

				break;
			case pwm_top_OCR1A:
				SET_BIT(TCCR1A, WGM10);
				SET_BIT(TCCR1A, WGM11);
				SET_BIT(TCCR1B, WGM12);
				SET_BIT(TCCR1B, WGM13);
				break;
			}
		}
		else if (phasecorrect==Pwm_configurChannel->top)
		{
			switch (Pwm_configurChannel->top) {
			case pwm_top_255:
				SET_BIT(TCCR1A, WGM10);
				CLR_BIT(TCCR1A, WGM11);
				CLR_BIT(TCCR1B, WGM12);
				CLR_BIT(TCCR1B, WGM13);
				break;
			case pwm_top_511:
				CLR_BIT(TCCR1A, WGM10);
				SET_BIT(TCCR1A, WGM11);
				CLR_BIT(TCCR1B, WGM12);
				CLR_BIT(TCCR1B, WGM13);
				break;
			case pwm_top_1023:
				SET_BIT(TCCR1A, WGM10);
				SET_BIT(TCCR1A, WGM11);
				CLR_BIT(TCCR1B, WGM12);
				CLR_BIT(TCCR1B, WGM13);
				break;
			case pwm_top_ICR1:
				CLR_BIT(TCCR1A, WGM10);
				SET_BIT(TCCR1A, WGM11);
				CLR_BIT(TCCR1B, WGM12);
				SET_BIT(TCCR1B, WGM13);

				break;
			case pwm_top_OCR1A:
				SET_BIT(TCCR1A, WGM10);
				SET_BIT(TCCR1A, WGM11);
				CLR_BIT(TCCR1B, WGM12);
				SET_BIT(TCCR1B, WGM13);
				break;
			}
		}
		else
		{
			/*no action required*/
		}
		TCCR1B = (TCCR1B & 0xF8) | (Pwm_configurChannel->prescale);/*set timer1 PRESCALE value */
		TCNT1 = 0; /*timer1 Initial Value*/

	}
}


void Pwm_setCompareValue(Pwm_compareValueType DutyCycle) {
	if (channelA == Pwm_configurChannel->pwmchannel) {
		OCR1A = DutyCycle;

	} else if (channelA == Pwm_configurChannel->pwmchannel) {
		OCR1B = DutyCycle;

	} else {

	}
}

void Pwm_deInit(){
	TCNT1= 0 ;
	OCR1A = 0 ;
	OCR1B = 0 ;
	TCCR1A =0 ;
	TCCR1B = 0 ;
}
