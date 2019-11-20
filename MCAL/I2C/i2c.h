/*
 * i2c.h
 *
 *  Created on: Nov 14, 2019
 *      Author: sayed
 */

#ifndef MCAL_I2C_I2C_H_
#define MCAL_I2C_I2C_H_

#include "../../std_types.h"
#include "../../micro_config.h"
#include "../../common_marcos.h"

void Twi_Init();
void Twi_start();
void Twi_Stop();
uint8 TWi_readWithAck();
void Twi_WriteWithAck(uint8 data);
uint8 Twi_getStatus(void);
#endif /* MCAL_I2C_I2C_H_ */
