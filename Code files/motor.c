/*
 * motor.c
 *
 *  Created on: Feb 14, 2021
 *      Author: admin
 */
#include "motor.h"

void Motor_init (void)
{
	SET_BIT (DDRB,PB0);
	SET_BIT (DDRB,PB1); /* PB0 & PB1 output Pins */
	CLEAR_BIT (PORTB,PB0);
	SET_BIT (PORTB,PB1); /* Clockwise */
}

void Motor_reverse (void)
{
	TOGGLE_BIT(PORTB,PB0);
	TOGGLE_BIT(PORTB,PB1);  /* Reverse the motor */
}

