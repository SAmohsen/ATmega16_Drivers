/*
 * ICU.h
 *
 *  Created on: Nov 12, 2019
 *      Author: sayed
 */

#ifndef MCAL_ICU_ICU_H_
#define MCAL_ICU_ICU_H_

#include "../../std_types.h"
#include "../../micro_config.h"
#include "../../common_marcos.h"

typedef enum {Icu_RISING_EDGE, ICu_FALLING_EDGE} Icu_EdgeNotificationType;
typedef enum {Icu_no_prescale,Icu_Prescale_8,Icu_Prescale_64,Icu_Prescale_256,Icu_Prescale_1024} Icu_PrescaleType;
typedef struct {
	Icu_EdgeNotificationType edge ;
	Icu_PrescaleType prescale ;
}Icu_ConfigChannel;
/********************************************************************
 * 						Function ProtoTypes
 * ******************************************************************/

void Icu_Init(Icu_ConfigChannel *Icu_ConfigPtr) ;
void Icu_SetEdgeDetection(Icu_EdgeNotificationType edge) ;
void Icu_SetCallback(void (*a_ptr)(void)) ;
void Icu_EnableInterrupts(void) ;
uint16 Icu_getInputCaptureValue(void);
void Icu_clearTimeValue(void);
void Icu_Deinit(void);
#endif /* MCAL_ICU_ICU_H_ */
