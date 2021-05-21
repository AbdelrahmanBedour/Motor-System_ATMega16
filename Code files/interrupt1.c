/*
 * interrupt1.c
 *
 *  Created on: Feb 14, 2021
 *
 */
#include "interrupt1.h"
#include "motor.h"

ISR(INT1_vect)
{
	Motor_reverse();
}

void INT1_init (void)
{
	CLEAR_BIT (DDRD,PD3); /* INT1 inout PIN*/
	SET_BIT (GICR,INT1); /* activating interrupt 1 */
	SET_BIT (MCUCR,ISC10);
	SET_BIT (MCUCR,ISC11); /* confing interrupt 1 to operate at rising edge */
}

