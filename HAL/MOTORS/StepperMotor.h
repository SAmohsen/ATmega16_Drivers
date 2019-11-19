/*
 * StepperMotor.h
 *
 *  Created on: Nov 11, 2019
 *      Author: sayed
 */

#ifndef HAL_MOTORS_STEPPERMOTOR_H_
#define HAL_MOTORS_STEPPERMOTOR_H_

#include "../../std_types.h"
#include "../../common_marcos.h"
#include "../../micro_config.h"

#include "StepperMotor_cfg.h"

void StepperMotor_Init();
void StepperMotor_Step (uint8 step);
#endif /* HAL_MOTORS_STEPPERMOTOR_H_ */
