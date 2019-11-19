/*
 * ICU.c
 *
 *  Created on: Nov 12, 2019
 *      Author: sayed
 */

#include "ICU.h"

static volatile  void (*g_callbackptr) (void) =NULL_PTR ;
ISR(TIMER1_CAPT_vect)
{

	//PORTA = 0xFF;
	if (NULL_PTR != g_callbackptr)
	{
		//PORTB = 0xFF;
		(*g_callbackptr)();
	}
}

void Icu_Init(Icu_ConfigChannel *Icu_ConfigPtr) {
	boolean error = FALSE;
	if (NULL_PTR==Icu_ConfigPtr)
	{
		error = TRUE;
	}
	else
	{

	}
	if (FALSE ==error)

	{
	/***********non PWM mode**********/
		TCCR1A = (1<<FOC1A) | (1<<FOC1B);

	/*********Icu edge *************/
	if (Icu_RISING_EDGE ==Icu_ConfigPtr->edge )
	{
		SET_BIT(TCCR1B, ICES1);
	}
	else if (ICu_FALLING_EDGE == Icu_ConfigPtr->edge)
	{
		CLR_BIT(TCCR1B, ICES1);
	}
	else
	{

	}
	/*******Icu prescale************/

	switch(Icu_ConfigPtr->prescale)
	{
	case Icu_no_prescale: SET_BIT(TCCR1B,CS10);
					      CLR_BIT(TCCR1B,CS11);
					      CLR_BIT(TCCR1B,CS12);

	break;
	case Icu_Prescale_8:  CLR_BIT(TCCR1B,CS10);
					  	  SET_BIT(TCCR1B,CS11);
					  	  CLR_BIT(TCCR1B,CS12);
	break;

	case Icu_Prescale_64: SET_BIT(TCCR1B,CS10);
					      SET_BIT(TCCR1B,CS11);
					      CLR_BIT(TCCR1B,CS12);
	break;

	case Icu_Prescale_256: CLR_BIT(TCCR1B,CS10);
					       CLR_BIT(TCCR1B,CS11);
					       SET_BIT(TCCR1B,CS12);
	break;
	case Icu_Prescale_1024: SET_BIT(TCCR1B,CS10);
						    CLR_BIT(TCCR1B,CS11);
						    SET_BIT(TCCR1B,CS12);
	break;
	}
	}
	else
	{

	}
	/* Initial Value for Timer1 */
	TCNT1 = 0;

	/* Initial Value for the input capture register */
	ICR1 = 0;
	//TIMSK |= (1<<TICIE1);


}

void Icu_SetEdgeDetection(Icu_EdgeNotificationType edge) {
	if (Icu_RISING_EDGE == edge)
	{
		SET_BIT(TCCR1B, ICES1);
	}
	else if (ICu_FALLING_EDGE == edge)
	{
		CLR_BIT(TCCR1B, ICES1);
	}
	else
	{

	}


}
void Icu_SetCallback(void (*a_ptr)(void)) {
	if (a_ptr != NULL_PTR)
	{
		g_callbackptr = a_ptr;
	}
}

void Icu_EnableInterrupts(void) {
		SET_BIT(TIMSK, TICIE1);
}
uint16 Icu_getInputCaptureValue(void)
{
	return ICR1;
}
void Icu_clearTimeValue(void)
{
	ICR1 = 0 ;
}

void Icu_Deinit(void) {

	TCNT1 = 0;
	TCCR1A =0 ;
	TCCR1B=0;
	CLR_BIT(TIMSK, TICIE1);
	g_callbackptr = NULL_PTR;

}
