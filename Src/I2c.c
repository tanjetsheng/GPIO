/*
 * I2c.c
 *
 *  Created on: Nov 28, 2017
 *      Author: user
 */

#include "Rcc.h"
#include "I2c.h"
#include "Gpio.h"

void InitI2c(void){
	enableI2c(I2c1_dev);
	enableI2c(I2c2_dev);

	gpioConfig(GpioB,6, GPIO_MODE_AF , GPIO_OPEN_DRAIN,GPIO_PULL_UP,GPIO_HIGH_SPEED);
	gpioConfigAltFuncNum(GpioB,6,ALT_FUNC4);
	gpioConfig(GpioB,7, GPIO_MODE_AF , GPIO_OPEN_DRAIN,GPIO_PULL_UP,GPIO_HIGH_SPEED);
	gpioConfigAltFuncNum(GpioB,7,ALT_FUNC4);
	void configMaster();

	gpioConfig(GpioF,0, GPIO_MODE_AF , GPIO_OPEN_DRAIN,GPIO_PULL_UP,GPIO_HIGH_SPEED);
	gpioConfigAltFuncNum(GpioF,0,ALT_FUNC4);
	gpioConfig(GpioF,1, GPIO_MODE_AF , GPIO_OPEN_DRAIN,GPIO_PULL_UP,GPIO_HIGH_SPEED);
	gpioConfigAltFuncNum(GpioF,1,ALT_FUNC4);

}

void configMaster(void){
	I2c1->CR2 |= 8;
	I2c1->CCR |= 600;
	I2c1->CCR &= ~(1<<15);
	I2c1->TRISE |= 9;
	I2c1->CR1 |= 1;
	I2c1->CR1 |= 1<<8;
	I2c1->CR1 &= ~(1<<1);
	I2c1->CR1 |= 1<<10;
}


