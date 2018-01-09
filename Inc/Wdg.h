/*
 * Iwdg.h
 *
 *  Created on: Jan 9, 2018
 *      Author: user
 */

#ifndef WDG_H_
#define WDG_H_

#include "stdint.h"

#define IWDG_BASE_ADDR 	0x40003000
#define WWDG_BASE_ADDR	0x40002C00
#define Iwdg      ((IwdgReg *)(IWDG_BASE_ADDR))
#define Wwdg      ((WwdgReg *)(WWDG_BASE_ADDR))

typedef struct WwdgReg WwdgReg;
struct WwdgReg{
	volatile uint32_t CR;			//0h
	volatile uint32_t CFR;			//4h
	volatile uint32_t SR;			//8h

};


typedef struct IwdgReg IwdgReg;
struct IwdgReg{
	volatile uint32_t KR;			//0h
	volatile uint32_t PR;			//4h
	volatile uint32_t RLR;			//8h
	volatile uint32_t SR;			//ch

};

//KEY REG
#define ENABLE_ACCESS 			0x5555
#define START_KEY				0xCCCC
#define RESET_KEY				0xAAAA

//PRESCALER
#define PRESCALE_4				0
#define PRESCALE_8				1
#define PRESCALE_16				2
#define PRESCALE_32				3
#define PRESCALE_64				4
#define PRESCALE_128			5
#define PRESCALE_256			6

//STATUS
#define RVU		(1<<1)		//reload value
#define PVU		1			//prescale value

/*-----------------------------------------*/
//WWDG
#define ACTIVATE		(1<<7)

#define DIVIDE_1				0
#define DIVIDE_2				1
#define DIVIDE_3				2
#define DIVIDE_4				3

#define WND_MASK	~(0x7f)
#define WAKEUPINTR	 (1<<9)
#define EWIF			1

#define CR_T6		(1<<6)

#define checkInterrupt()	(Wwdg->SR & EWIF)



#define waitReload()	\
		while((Iwdg->SR)&RVU)

#define waitPrescale()		\
		while((Iwdg->SR)&PVU)

#define Idwg_reset()		(Iwdg->KR = RESET_KEY)
void initWwdg(int value);
void set(int value);
void setDivider(int value);
void enableWwdgIntrerrupt();

#endif /* WDG_H_ */
