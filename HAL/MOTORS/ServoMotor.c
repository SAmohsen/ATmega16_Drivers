/*
 * ServoMotor.c
 *
 *  Created on: Nov 12, 2019
 *      Author: sayed
 */
#include "ServoMotor.h"
/*Not working */
void ServoMotor_Init() {
	/*
	 * Motors operate on 50 HZ
	 *timer 1 fast PWM equation
	 *F_PWM = F_CPU / (N *(TOP+1))
	 *
	 *choose N = 64
	 *50 HZ = 1000000/(64 *(TOP+1))
	 *
	 *top = ((1000000)/50*8 )-1 = 311
	 *
	 * */DDRD = 0xFF;
	SET_BIT(TCCR1A, COM1A1);
	CLR_BIT(TCCR1A, COM1A0);

	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);

	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

	SET_BIT(TCCR1B, CS10);
	CLR_BIT(TCCR1B, CS11);
	//SET_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);
	TCNT1 = 0;
	ICR1 = 19999;
	//ICR1 = 2499;
}
void Servo_motorRotate(uint8 value ){

OCR1A = value;
}
