/*
 * Flash.c
 *
 *  Created on: Dec 5, 2017
 *      Author: user
 */

#include "Flash.h"

//stm32f429zit6
//section erase flash memory
//sectionNum is section to erase
//return 0 = fail to erase
//return 1 = success

int flashEraseSector(int sectorNum){
	/*if(sectorNum >11){
		sectorNum =sectorNum +4;
	}*/
	//unlock KEYREG
	//Flash->KEYR = KEY1;
	//Flash->KEYR = KEY2;
	//set sector number to erase,set to sector erase,start erase
	Flash->CR = (sectorNum << 3) | FLASH_SECTOR_ERASE  | FLASH_START ;


		return 1;
	}
	//check failure

	//return status






// sector13 start address = 0x08084000
int flashWriteMessage(char *message,char *memoryToWrite){
	strcpy(memoryToWrite,message);
	return 1;
	}


//enable flash programming
//program Size is the size when writing into flash
//FLASH_BYTE_SIZE
//FLASH_HALFWORD_SIZE
//FLASH_WORD_SIZE
//FLASH_DOUBLE_SIZE
void flashEnableProgramming(int programSize){
	Flash->KEYR = KEY1;
	Flash->KEYR = KEY2;
	Flash->CR = FLASH_ENABLE_PROGRAMMING | (programSize <<8) ;
}

void flashDisable(){
	Flash->CR |= FLASH_DISABLE_PROGRAM;
}
