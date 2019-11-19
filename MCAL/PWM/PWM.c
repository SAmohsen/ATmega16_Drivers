/*
 * PWM.c
 *
 *  Created on: Nov 12, 2019
 *      Author: sayed
 */


#include "PWM.h"

static Pwm_ConfigType *Pwm_configurations = NULL_PTR;

void Pwm_Init(const Pwm_ConfigType* ConfigPtr ){
	boolean error = FALSE ;
	if (NULL_PTR==ConfigPtr)
	{
		error = TRUE;
	}
	else
	{

	}
	if (FALSE == error)
	{
		Pwm_configurations=ConfigPtr;
		switch(Pwm_configurations->mode)
		{
		case non_inverting_mode:SET_BIT(TCCR1A,COM1A1);
								CLR_BIT(TCCR1A,COM1A0);
								SET_BIT(TCCR1A,COM1B1);
								CLR_BIT(TCCR1A,COM1B0);

		break;

		case inverting_mode:SET_BIT(TCCR1A,COM1A1);
							SET_BIT(TCCR1A,COM1A0);
							SET_BIT(TCCR1A,COM1B1);
							SET_BIT(TCCR1A,COM1B0);
		break;
		}

		/*OCR1A TOP*/
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);

		switch(Pwm_configurations->prescale)
		{
		case Pwm_no_prescale: SET_BIT(TCCR1B,CS10);
						      CLR_BIT(TCCR1B,CS11);
						      CLR_BIT(TCCR1B,CS12);
		break;
		case Pwm_Prescale_8:  CLR_BIT(TCCR1B,CS10);
						  	  SET_BIT(TCCR1B,CS11);
						  	  CLR_BIT(TCCR1B,CS12);
		break;

		case Pwm_Prescale_64: SET_BIT(TCCR1B,CS10);
						      SET_BIT(TCCR1B,CS11);
						      CLR_BIT(TCCR1B,CS12);
		break;

		case Pwm_Prescale_256: CLR_BIT(TCCR1B,CS10);
						       CLR_BIT(TCCR1B,CS11);
						       SET_BIT(TCCR1B,CS12);
		break;
		case Pwm_Prescale_1024: SET_BIT(TCCR1B,CS10);
							    CLR_BIT(TCCR1B,CS11);
							    SET_BIT(TCCR1B,CS12);


		break;
		}
		TCNT1 = 0 ;

	}
	else
	{

	}
}


void Pwm_SetOCR1A( Pwm_DutyCycleType DutyCycle ){
OCR1B = DutyCycle;
}

