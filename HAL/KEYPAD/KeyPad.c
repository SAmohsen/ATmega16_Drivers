/*
 * KeyPad.c
 *
 *  Created on: Nov 11, 2019
 *      Author: sayed
 */

#include "KeyPad.h"
static char keypad_GetKey(uint8 row , uint8 col){
#ifdef KEYPAD4X3MODE
char key_arr[][3]={{'1','2','3'},
				  {'4','5','6'},
                  {'7','8','9'},
                  {'*','0','#'}
                 };

#else
char key_arr[][4]={{' ','0','#','+'},
				  {'1','2','3','-'},
                  {'4','5','6','*'},
                  {'7','8','9','/'}
                 };


#endif
	return key_arr[row][col];
}


uint8 Keypad_GetKeyPressed(){
	uint8 stat = KEY_NOT_PRESSED;
	while(1){
	for (uint8 col=0 ;col<NUMBER_OF_COLS;col++){
		/*cols in high nibble */
		KEYPAD_DDR = 0b00010000<<col;
		KEYPAD_PORT = (~(0b00010000<<col));

		for (uint8 row =0;row<NUMBER_OF_ROWS;row++){
			if(BIT_IS_CLEAR(KEYPAD_PIN,row)){
				_delay_ms(100);
				if(BIT_IS_CLEAR(KEYPAD_PIN,row)){
				return keypad_GetKey(row,col);
			}}

		}
	}
	}
}
