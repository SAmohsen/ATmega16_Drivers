/*
 * KeyPad.h
 *
 *  Created on: Nov 11, 2019
 *      Author: sayed
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "KeyPad_cfg.h"
#ifdef KEYPAD3X3MODE
#define NUMBER_OF_COLS 3
#define NUMBER_OF_ROWS 4
#else
#define NUMBER_OF_COLS 4
#define NUMBER_OF_ROWS 4
#endif
#define KEY_PRESSED 1
#define KEY_NOT_PRESSED 0

#endif /* HAL_KEYPAD_KEYPAD_H_ */
