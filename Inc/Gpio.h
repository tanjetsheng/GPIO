/*
 * Gpio.h
 *
 *  Created on: Oct 27, 2017
 *      Author: tanjetsheng
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

#define GPIOA_BASE_ADDR 	0x40020000
#define GPIOB_BASE_ADDR 	0x40020400
#define GPIOC_BASE_ADDR 	0x40020800
#define GPIOD_BASE_ADDR 	0x40020C00
#define GPIOE_BASE_ADDR 	0x40021000
#define GPIOF_BASE_ADDR 	0x40021400
#define GPIOG_BASE_ADDR 	0x40021800
#define GPIOH_BASE_ADDR 	0x40021C00
#define GPIOI_BASE_ADDR 	0x40022000
#define GpioA		((GpioReg *)(GPIOA_BASE_ADDR))
#define GpioB		((GpioReg *)(GPIOB_BASE_ADDR))
#define GpioC		((GpioReg *)(GPIOC_BASE_ADDR))
#define GpioD		((GpioReg *)(GPIOD_BASE_ADDR))
#define GpioE		((GpioReg *)(GPIOE_BASE_ADDR))
#define GpioF		((GpioReg *)(GPIOF_BASE_ADDR))
#define GpioG		((GpioReg *)(GPIOG_BASE_ADDR))
#define GpioH		((GpioReg *)(GPIOH_BASE_ADDR))
#define GpioI		((GpioReg *)(GPIOI_BASE_ADDR))

#define ALT_FUNC0	0
#define ALT_FUNC1	1
#define ALT_FUNC2	2
#define ALT_FUNC3	3
#define ALT_FUNC4	4
#define ALT_FUNC5	5
#define ALT_FUNC6	6
#define ALT_FUNC7	7
#define ALT_FUNC8	8
#define ALT_FUNC9	9
#define ALT_FUNCA	a
#define ALT_FUNCB	b
#define ALT_FUNCC	c
#define ALT_FUNCD	d
#define ALT_FUNCE	e
#define ALT_FUNCF	f

typedef struct GpioReg GpioReg;
struct GpioReg{
	volatile uint32_t mode;			//0h
	volatile uint32_t outType;		//4h
	volatile uint32_t outSpeed;		//8h
	volatile uint32_t pullType;  	//ch
	volatile uint32_t inData;		//10h
	volatile uint32_t outData;		//14h
	volatile uint32_t BSRR;		//18h
	volatile uint32_t lock;			//1ch
	volatile uint32_t altFuncLow; 	//20h
	volatile uint32_t altFuncHigh; 	//24h


};


#define SET_PIN(gpio,pinNum)		gpio->BSRR = (1<<pinNum)
#define RESET_PIN(gpio,pinNum)		gpio->BSRR = (1<<(pinNum+16))

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

void gpioConfigAltFuncNum(GpioReg *Gpio,int pin,int func);


void gpioConfig(GpioReg *Gpio,int pin,int mode, int outdriveType,int pullType,int speed);
void gpioWrite(GpioReg *Gpio,int pin,int state);

void gpiogConfig(int pin,int mode, int outdriveType,int pullType,int speed);
void gpioGWrite(int pin,int state);

int gpioRead(GpioReg *Gpio,int pin);
void gpioLock(GpioReg *Gpio,int pin);



#endif /* GPIO_H_ */
