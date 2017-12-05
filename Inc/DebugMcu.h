/*
 * DebugMcu.h
 *
 *  Created on: Nov 28, 2017
 *      Author: user
 */

#ifndef DEBUGMCU_H_
#define DEBUGMCU_H_

#define DBGMCU_APB2_FZ		(*(uint32_t *)(0xE004200C))
#define DBGMCU_APB1_FZ		(*(uint32_t *)(0xE0042008))
#define DBG_TIM8_STOP		(1<<1)
#define DBG_I2C1_STOP		(1<<21)
#define DBG_I2C2_STOP		(1<<22)
#define DBG_I2C3_STOP		(1<<23)
#define haltTimerWhenDebugging()		(DBGMCU_APB2_FZ |= DBG_TIM8_STOP)
#define haltI2C1WhenDebugging()			(DBGMCU_APB1_FZ |= DBG_I2C1_STOP)
#endif /* DBGMCU_H_ */

