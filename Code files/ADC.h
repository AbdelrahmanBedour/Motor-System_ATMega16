/*
 * ADC.h
 *
 *  Created on: Feb 14, 2021
 *      Author: admin
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void ADC_init(void );
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
