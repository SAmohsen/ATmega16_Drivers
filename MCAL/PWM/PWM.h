 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.c
 *
 * Description: Source file for  PWM driver
 *
 * Author: sayed mohsen
 *
 *******************************************************************************/


#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

#include "../../std_types.h"
#include "../../micro_config.h"
#include "../../common_marcos.h"


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

typedef uint16 Pwm_compareValueType ;/*type for PWM Compare Value*/

typedef enum {
	non_inverting_mode,
	inverting_mode,
}PWM_GenrationMode;/*type For Output Channel Signal Generation Mode*/

typedef enum{
	pwm_top_255,
	pwm_top_511,
	pwm_top_1023,
	pwm_top_OCR1A,
	pwm_top_ICR1
}Pwm_topValueType;/*type for Timer1 Top Value */

typedef enum {
	Pwm_no_prescale=1,
	Pwm_Prescale_8,
	Pwm_Prescale_64,
	Pwm_Prescale_256,
	Pwm_Prescale_1024,
}Pwm_PrescaleType;/*type For Timer1 Clock Source*/
typedef enum{
	phasecorrect,
	FastPwm
}Pwm_PwmModeType;/*type For PWM Mode*/
typedef enum {
	channelA,
	ChannelB,
}Pwm_ChannelType;/*type For PWM Output Channel*/

typedef struct {
	Pwm_PwmModeType pwmMode;
	PWM_GenrationMode genrationmode;
	Pwm_PrescaleType prescale;
	Pwm_ChannelType pwmchannel;
	Pwm_compareValueType compareValue;
	Pwm_topValueType top;
}Pwm_ConfigType;/*type For PWM configurations*/


/**************************************************************************************
 * 							Function ProtoTypes
 * ************************************************************************************/

void Pwm_Init(const Pwm_ConfigType* ConfigPtr );
void Pwm_setCompareValue(Pwm_compareValueType DutyCycle);
void Pwm_deInit();

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern const Pwm_ConfigType PwmConfigrations;

#endif /* MCAL_PWM_PWM_H_ */
