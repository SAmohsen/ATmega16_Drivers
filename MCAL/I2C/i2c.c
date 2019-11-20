/*
 * i2c.c
 *
 *  Created on: Nov 14, 2019
 *      Author: sayed
 */

#include "i2c.h"
void Twi_Init(){

	 /* Bit Rate: 50 kbps using zero pre-scaler TWPS=00 and F_CPU=1Mhz
	  * SCL frequency CPU = Clock frequency /16 + 2(TWBR) * ⋅ 4^TWPS
	  * 50 = 1000000 / 16 +2X
	  * x = 2
	  */
	TWBR = 0x02 ;
	TWSR = 0x00 ;

	/* Device Address */
	TWAR = 0x01 ;

	/*Enable TWI*/
	TWCR = (1<<TWEN);
}

void Twi_start(){
	/*to start talking to bus you must send start bit and wait to start send*/
	TWCR =  (1<<TWINT) | (1<<TWSTA)|(1<<TWEN);
	while (BIT_IS_CLEAR(TWCR,TWINT));
}
void Twi_Stop(){
	TWCR =  (1<<TWINT) | (1<<TWSTO)|(1<<TWEN);
}
uint8 TWi_readWithAck(){
	TWCR =  (1<<TWINT) |(1<<TWEN) | (1<<TWEA);
	while (BIT_IS_CLEAR(TWCR,TWINT));
	return TWDR ;
}
void Twi_WriteWithAck(uint8 data){
TWDR = data ;
TWCR =  (1<<TWINT) |(1<<TWEN);
while (BIT_IS_CLEAR(TWCR,TWINT));
}

uint8 Twi_getStatus(void)
{
    uint8 status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & 0xF8;
    return status;
}
