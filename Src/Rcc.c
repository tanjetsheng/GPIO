/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#include "Rcc.h"
uint32_t *rccAhb1Rst = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1REn = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1EN_OFF);

void enableGpioG(){
	//unreset GPIOG
	*rccAhb1Rst &=~(1<<6);
	//start
	*rccAhb1REn |= 1<<6;

}
