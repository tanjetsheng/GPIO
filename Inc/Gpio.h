/*
 * Gpio.h
 *
 *  Created on: Oct 27, 2017
 *      Author: tanjetsheng
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>


#define GPIOG_BASE_ADDR 	0x40021800
#define GpioG		((GpioReg *)(GPIOG_BASE_ADDR))

typedef struct GpioReg GpioReg;
struct GpioReg{
	volatile uint32_t mode;			//0h
	volatile uint32_t outType;		//4h
	volatile uint32_t outSpeed;		//8h
	volatile uint32_t pullType;  	//ch
	volatile uint32_t inData;		//10h
	volatile uint32_t outData;		//14h
	volatile uint32_t bitData;		//18h
	volatile uint32_t lock;			//1ch
	volatile uint32_t altFuncLow; 	//20h
	volatile uint32_t altFuncHigh; 	//24h


};




//PIN MODE
#define GPIO_MODE_IN    0
#define GPIO_MODE_OUT   1
#define GPIO_MODE_AF    2
#define GPIO_MODE_ANA   3

//pin drive type
#define GPIO_PUSH_PULL   0
#define GPIO_OPEN_DRAIN  1

//pin speed
#define GPIO_LOW_SPEED    0
#define GPIO_MED_SPEED    1
#define GPIO_HIGH_SPEED   2
#define GPIO_VHIGH_SPEED  3

//pin pull type
#define GPIO_NO_PULL    0
#define GPIO_PULL_UP    1
#define GPIO_PULL_DOWN  2







//export variable to other module
extern uint32_t *gpioGMode;
extern uint32_t *gpioGOSPEED;
extern uint32_t *gpioGPupd;
extern uint32_t *gpioGOType;
extern uint32_t *gpioGOD;

void gpioConfig(int pin,int mode, int outdriveType,int pullType,int speed);
void gpioGWrite(int pin,int state);


#endif /* GPIO_H_ */
