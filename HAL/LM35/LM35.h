/*
 * LM35.h
 *
 *  Created on: Nov 20, 2019
 *      Author: sayed
 */

#ifndef HAL_LM35_LM35_H_
#define HAL_LM35_LM35_H_

#include "../../std_types.h"
#include "../../common_marcos.h"
#include  "../../micro_config.h"

#include "../../MCAL/ADC/ADC.h"
#include "Lm35_cfg.h"
void LM35_Init(void);
uint16 LM35_ReadTemp();
#endif /* HAL_LM35_LM35_H_ */
