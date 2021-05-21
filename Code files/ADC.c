/*
 * ADC.c
 *
 *  Created on: Feb 14, 2021
 *
 */
#include "ADC.h"

void ADC_init(void )
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = 0;
	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADPS2:0 = 011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
	 */
		ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
}


uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX = (ADMUX &0xE0) | (channel_num & 0x07); /* choose the correct channel by setting the channel number in MUX4:0 bits */
	CLEAR_BIT (DDRA,channel_num); /* set the channel as input PIN */
	SET_BIT(ADCSRA,ADSC); /* start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* wait for conversion to complete ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* clear ADIF by write '1' to it :) */
	return ADC; /* return the data register */
}
