/*
 * LM35.c
 *
 *  Created on: Nov 20, 2019
 *      Author: sayed
 */
#include"Lm35.h"

void LM35_Init(void)
{
	CLR_BIT(LM35_PORT_DIR, LM35_PIN);
}
uint16 LM35_ReadTemp()
{
	uint16 temp;
	float dig;
	float volt;
	dig = Adc_StartConversion(LM35_ADC_CHANNEL);
	volt = (dig * 5) / 1023;
	volt = (volt) / 10;
	temp = volt * 1000;
	return temp;
}
