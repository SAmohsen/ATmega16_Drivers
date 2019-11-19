/*
 * i2c.c
 *
 *  Created on: Nov 14, 2019
 *      Author: sayed
 */

#include "i2c.h"
void TWI_Init(){
    TWBR = 0x02;
TWSR = 0x00;
TWCR = (1<<TWEN);
TWAR= 0x01;
}

void TWI_start(){

}
