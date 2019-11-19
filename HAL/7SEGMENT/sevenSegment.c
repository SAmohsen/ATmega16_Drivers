/*
 * sevenSegment.c
 *
 *  Created on: Nov 14, 2019
 *      Author: sayed
 */

#include "sevenSegment.h"
/*need more enhancement */
void sevensegment_Init(){
#ifdef HIGH_NIBBLE
	SEVENSEGMENT_DDR |=0xF0;
#else
	SEVENSEGMENT_DDR |=0x0F;
#endif
}
void sevensegment_Display(uint8 value){
	if (value <=SEVEN_SEGMENT_MAX_VALUE)
	{
#ifdef HIGH_NIBBLE
		SEVENSEGMENT_PORT = (SEVENSEGMENT_PORT & 0x0F ) |((value & 0x0F)<<4);
#else
		SEVENSEGMENT_PORT = (SEVENSEGMENT_PORT & 0xF0 ) |(value & 0x0F);
#endif
	}
	else
	{

	}
}
