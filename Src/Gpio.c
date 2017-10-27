/*
 * Gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: tanjetsheng
 */


#include "Gpio.h"


uint32_t *gpioGMode = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_MODE_OFF);
uint32_t *gpioGOSPEED = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_OSPEED_OFF);
uint32_t *gpioGPupd = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_PUPD_OFF);
uint32_t *gpioGOType = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_OTYPE_OFF);
uint32_t *gpioGOD = (uint32_t *)(GPIOG_BASE_ADDR + GPIO_OD_OFF);



void gpioConfig(int pin,int mode, int outdriveType,int pullType,int speed){
	*gpioGMode &= ~(3 <<(pin * 2));					//clear pin mode to 0
	*gpioGMode |= mode <<(pin * 2);					//set pin mode

	*gpioGOSPEED &= ~(3 <<(pin * 2));					//clear pin speed to 0
	*gpioGOSPEED |= speed <<(pin * 2);					//set pin speed

	*gpioGPupd &= ~(3 <<(pin * 2));					//clear pin pull type to 0
	*gpioGPupd |= pullType <<(pin * 2);					//set pin pull type

	*gpioGOType &= ~(1 <<pin);					//clear pin drive type to 0
	*gpioGOType |= outdriveType <<pin ;					//set pin drive type
}

void gpioGWrite(int pin,int state){
	if(state ==1){
	*gpioGOD |= 1 << pin;
	}else{
	*gpioGOD &= ~(1<< pin);
	}
}
