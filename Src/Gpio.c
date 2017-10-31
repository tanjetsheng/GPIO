/*
 * Gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: tanjetsheng
 */


#include "Gpio.h"





void gpioConfig(GpioReg *Gpio,int pin,int mode, int outdriveType,int pullType,int speed){
	Gpio->mode &= ~(3 <<(pin * 2));					//clear pin mode to 0
	Gpio->mode |= mode <<(pin * 2);					//set pin mode

	Gpio->outSpeed &= ~(3 <<(pin * 2));					//clear pin speed to 0
	Gpio->outSpeed |= speed <<(pin * 2);					//set pin speed

	Gpio->pullType &= ~(3 <<(pin * 2));					//clear pin pull type to 0
	Gpio->pullType |= pullType <<(pin * 2);					//set pin pull type

	Gpio->outType &= ~(1 <<pin);					//clear pin drive type to 0
	Gpio->outType |= outdriveType <<pin ;					//set pin drive type
}

void gpioWrite(GpioReg *Gpio,int pin,int state){
	if(state ==1){
	Gpio->outData |= 1 << pin;
	}else{
	Gpio->outData &= ~(1<< pin);
	}
}

int gpioRead(GpioReg *Gpio,int pin){
	return Gpio->inData & (1 <<pin);
}







void gpioGConfig(int pin,int mode, int outdriveType,int pullType,int speed){
	GpioG->mode &= ~(3 <<(pin * 2));					//clear pin mode to 0
	GpioG->mode |= mode <<(pin * 2);					//set pin mode

	GpioG->outSpeed &= ~(3 <<(pin * 2));					//clear pin speed to 0
	GpioG->outSpeed |= speed <<(pin * 2);					//set pin speed

	GpioG->pullType &= ~(3 <<(pin * 2));					//clear pin pull type to 0
	GpioG->pullType |= pullType <<(pin * 2);					//set pin pull type

	GpioG->outType &= ~(1 <<pin);					//clear pin drive type to 0
	GpioG->outType |= outdriveType <<pin ;					//set pin drive type
}

void gpioGWrite(int pin,int state){
	if(state ==1){
	GpioG->outData |= 1 << pin;
	}else{
	GpioG->outData &= ~(1<< pin);
	}
}

void gpioLock(GpioReg *Gpio,int pin){

	int pattern;

	Gpio->lock = (1<<16)|(1<<pin);
	Gpio->lock = (0<<16)|(1<<pin);
	Gpio->lock = (1<<16)|(1<<pin);

	pattern = Gpio->lock;
	pattern = Gpio->lock;
}
