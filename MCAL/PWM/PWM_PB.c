 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM_PBcfg.c
 *
 * Description: Post Build Configuration Source file for PWM Module.
 *
 * Author: sayed mohsen
 ******************************************************************************/

#include "PWM.h"

const Pwm_ConfigType PwmConfigrations={FastPwm,non_inverting_mode,Pwm_Prescale_8,ChannelB,512,pwm_top_1023};
