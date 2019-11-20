/*
 * eeprom.c
 *
 *  Created on: Nov 20, 2019
 *      Author: sayed
 */

#include "eeprom.h"
void eeprom_Write(uint16 addr , uint8 data){
	while (BIT_IS_SET(EECR,EEWE));
	EEAR = addr & 0x03FF;
	EEDR = data ;
	SET_BIT(EECR,EEMWE);
	_delay_us(4);
	SET_BIT(EECR,EEWE);
}

uint8 eeprom_read(uint16 addr){
	while (BIT_IS_SET(EECR,EEWE));
	EEAR = addr & 0x03FF;
	SET_BIT(EECR,EERE);
	return EEDR ;

}
