/*
 * Falsh.h
 *
 *  Created on: Dec 5, 2017
 *      Author: user
 */

#ifndef FLASH_H_
#define FLASH_H_

#include <stdint.h>

#define FLASH_BASE_ADDR 	0x40023C00
#define Flash      ((FlashReg *)(FLASH_BASE_ADDR))


#define FLASH_BYTE_SIZE				0
#define FLASH_HALFWORD_SIZE			1
#define FLASH_WORD_SIZE				2
#define FLASH_DOUBLE_SIZE			3

#define FLASH_SECTOR_ERASE			(1<<1)

#define FLASH_START					(1<<16)

#define FLASH_ERROR_INTERRUPT  		(1<<25)

#define FLASH_BUSY 					(1<<16)

#define FLASH_DISABLE_PROGRAM 		0

#define FLASH_ENABLE_PROGRAMMING	1

#define FLASH_PGSERR				(1<<7)

#define KEY1	0x45670123
#define KEY2	0xCDEF89AB

typedef struct FlashReg FlashReg;
struct FlashReg{
	volatile uint32_t ACR;			//0h
	volatile uint32_t KEYR;			//4h
	volatile uint32_t OPTKEYR;		//8h
	volatile uint32_t SR;			//ch
	volatile uint32_t CR;			//10h
	volatile uint32_t OPTCR;		//14h
	volatile uint32_t OPTCR1;		//18h

};

int flashEraseSector(int sectorNum);
int flashWriteMessage(char *message,char *memoryToWrite);
void flashEnableProgramming(int programSize);
void flashDisable();

#endif /* FLASH_H_ */
