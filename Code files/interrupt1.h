/*
 * interrupt1.h
 *
 *  Created on: Feb 14, 2021
 *
 */

#ifndef INTERRUPT1_H_
#define INTERRUPT1_H_

#include "std_types.h"
#include "micro_config.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
ISR(INT1_vect);
void INT1_init(void);


#endif /* INTERRUPT1_H_ */
