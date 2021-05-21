/*
 * PWM.h
 *
 *  Created on: Feb 14, 2021
 *
 */

#ifndef PWM_H_
#define PWM_H_


#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void PWM_Duty(uint8 time);
void PWM_init (void);


#endif /* PWM_H_ */
