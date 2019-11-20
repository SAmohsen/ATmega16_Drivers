/*
 * eeprom.h
 *
 *  Created on: Nov 20, 2019
 *      Author: sayed
 */

#ifndef HAL_EEPROM_EEPROM_H_
#define HAL_EEPROM_EEPROM_H_

#include "../../std_types.h"
#include "../../common_marcos.h"
#include  "../../micro_config.h"



void eeprom_Write(uint16 addr , uint8 data);
uint8 eeprom_read(uint16 addr);
#endif /* HAL_EEPROM_EEPROM_H_ */
