/*
 * sysTick.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user
 */


#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

#define SYSTICK_BASE_ADDR 	0xE000E010
#define Tick      ((SysTickReg *)(SYSTICK_BASE_ADDR))

#define SYSTICK_EN						1
#define SYSTICK_INTR_EN					(1 << 1 )
#define SYSTICK_CLK_SRC					(1 << 2 )
#define SYSTICK_CNTR_OVERFLOW			(1 << 16 )

typedef struct SysTickReg SysTickReg;
struct SysTickReg{
	volatile uint32_t CTRL;			//  control and status register
	volatile uint32_t LOAD;			//reload value register
	volatile uint32_t VAL;
	volatile uint32_t CALIB;

};

#define sysTickEnable()				(Tick->CTRL |= SYSTICK_EN)
#define sysTickDisable()			(Tick->CTRL &= ~SYSTICK_EN)
#define sysTickIntrEnable()			(Tick->CTRL |= SYSTICK_INTR_EN)
#define sysTickIntrDisable()		(Tick->CTRL &= ~SYSTICK_INTR_EN)
#define sysTickSetReload(x)			(Tick->LOAD = (x))
#define sysTickReadCounter(x)		(Tick->VAL)
#define sysTickClrCounter()			(Tick->VAL = 0xfafadfa)
// set systick to run at processor speed
#define sysTickFullSpeed()			(Tick->CTRL |= SYSTICK_CLK_SRC)
//set systick to run at 1/8 of AHB speed
#define sysTickPrescaledSpeed()		(Tick->CTRL &= ~SYSTICK_CLK_SRC)

#define sysTickHasExpired()			(Tick->CTRL & SYSTICK_CNTR_OVERFLOW)
#endif /* SYSTICK_H_ */
