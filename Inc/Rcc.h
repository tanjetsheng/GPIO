/*
 * Rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>

#define RCC_BASE_ADDR    0x40023800
#define RCC_AHB1RST_OFF   0x10
#define RCC_AHB1EN_OFF    0x30

#define Rcc		((RccReg *)(RCC_BASE_ADDR))

typedef struct RccReg RccReg;
struct RccReg{
	volatile uint32_t CR;			//0h
	volatile uint32_t PLLCFGR;		//4h
	volatile uint32_t CFGR;	    	//8h
	volatile uint32_t CIR;  	    //ch
	volatile uint32_t AHB1RSTR;		//10h
	volatile uint32_t AHB2RSTR;		//14h
	volatile uint32_t AHB3RSTR;		//18h
	volatile uint32_t Reserved1;	//1ch
	volatile uint32_t APB1RSTR; 	//20h
	volatile uint32_t APB2RSTR; 	//24h
	volatile uint32_t Reserve2[2]; 	//28h
	volatile uint32_t AHB1ENR; 		//30h
	volatile uint32_t AHB2ENR; 		//34h
	volatile uint32_t AHB3ENR; 		//38h
	volatile uint32_t Reserve3; 	//3ch
	volatile uint32_t APB1ENR; 		//40h
	volatile uint32_t APB2ENR; 		//44h
	volatile uint32_t Reserved4[2];	//48h
	volatile uint32_t AHB1LPENR; 	//50h
	volatile uint32_t AHB2LPENR; 	//54h
	volatile uint32_t AHB3LPENR; 	//58h
	volatile uint32_t Reserved5; 	//5ch
	volatile uint32_t APB1LPENR; 	//60h
	volatile uint32_t APB2LPENR; 	//64h
	volatile uint32_t Reserved6[2];	//68h
	volatile uint32_t BDCR; 		//70h
	volatile uint32_t CSR; 			//74h
	volatile uint32_t Reserved7[2]; //78h
	volatile uint32_t SSCGR; 		//80h
	volatile uint32_t PLLI2SCFGR; 	//84h

};


#define enableTimer8()  \
		Rcc->APB2RSTR &= ~(1<<1);		\
		Rcc->APB2ENR |= 1<<1;
//export variable to other module
extern uint32_t *rccAhb1Rst ;
extern uint32_t *rccAhb1REn ;

#define MCO_DIV_2		4
#define MCO_DIV_3		5
#define MCO_DIV_4		6
#define MCO_DIV_5		7

#define MCO_HSI_SRC		0
#define MCO_LSE_SRC		1
#define MCO_HSE_SRC		2
#define MCO_PLL_SRC		3

#define I2c1_dev   		21
#define I2c2_dev 		22
#define I2c3_dev 		23

void enableGpioG(void);
void enableGpioB(void);
void enableGpioA(void);
void enableI2c1(void);
void enableI2c2(void);

#define rccSelectMco1Src(x)									\
									Rcc->CFGR &= ~(3 << 21);	\
									Rcc->CFGR |= (x << 21);


#define rccSetMco1Prescaler(x)		Rcc->CFGR &= ~(7 << 24);	\
									Rcc->CFGR |= (x << 24);


void enableRng(void);

#endif /* RCC_H_ */
