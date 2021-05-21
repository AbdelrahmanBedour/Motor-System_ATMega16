/*
 * Main.c
 *
 *  Created on: Feb 14, 2021
 *
 */
#include "motor.h"
#include "interrupt1.h"
#include "PWM.h"
#include "LCD.h"
#include "ADC.h"


int main (void)
{
	uint16  ADC_Value ;
	Motor_init();
	INT1_init();
	PWM_init();
	LCD_init();
	LCD_displayString("ADC Value = ");
	ADC_init();
	SET_BIT(SREG,7); /* enable interrupts */
	for(;;)
	{
		 ADC_Value = ADC_readChannel(0);
		 LCD_goToRowColumn(0,12);
		 LCD_intgerToString(ADC_Value);
		 LCD_displayCharacter(' ');
		 PWM_Duty(ADC_Value/4); /* As the compare register varies from 0 to 255 */


	}
}

