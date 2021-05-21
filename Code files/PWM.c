/*
 * PWM.c
 *
 *  Created on: Feb 14, 2021
 *
 */
#include "PWM.h"
void PWM_init (void)
{
	SET_BIT (DDRB,PB3); /* OC0 output PIN */
	SET_BIT (TCCR0,WGM00);
	SET_BIT (TCCR0,WGM01); /* fast PWM mode */
	CLEAR_BIT (TCCR0,CS00);
	SET_BIT (TCCR0,CS01);
	CLEAR_BIT (TCCR0,CS02); /* pre-scaler Fcpu/8 */
	CLEAR_BIT (TCCR0,COM00);
	SET_BIT (TCCR0,COM01); /* non-inverting mode */
	TCNT0 = 0; /* clearing the counter register  */
	OCR0 = 255 ; /* setting the compare value */
}


void PWM_Duty(uint8 time)
{
	OCR0 = time;  /* setting the compare value */
}



