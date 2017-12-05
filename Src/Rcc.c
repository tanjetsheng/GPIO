/*
 * Rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#include "Rcc.h"
uint32_t *rccAhb1Rst = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1RST_OFF);
uint32_t *rccAhb1REn = (uint32_t *)(RCC_BASE_ADDR + RCC_AHB1EN_OFF);

void enableGpioA(){
	//unreset GPIOA
	*rccAhb1Rst &= ~1;
	//start clock of GPIOA
	*rccAhb1REn |= 1;
}

void enableGpioB(){
	//unreset GPIOB
	*rccAhb1Rst &=~(1<<1);
	//start clock of GPIOB
	*rccAhb1REn |= 1<<1;

}


void enableGpioG(){
	//unreset GPIOG
	*rccAhb1Rst &=~(1<<6);
	//start clock of GPIOG
	*rccAhb1REn |= 1<<6;

}

void enableRng(void){
	//unreset
	Rcc->AHB2RSTR &= ~(1<<6);
	//start clock
	Rcc->AHB2ENR |= 1<<6;
}

void enableI2c(int num){
	Rcc->APB1RSTR &= ~(1<<num);
	Rcc->APB1ENR |= 1<<num;
}


