/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include "Gpio.h"
#include "Rcc.h"
#include "Rng.h"
#include "Nvic.h"
#include "sysTick.h"
#include "ExtIntr.h"
#include "Timer.h"
#include "I2c.h"
#include "Flash.h"
#include "Usart.h"
#include "Dma.h"

/* USER CODE BEGIN Includes */
#define blueButtonPin 0
#define greenLedPin 13
#define redLedPin 	14

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
 int count =0 ;
/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
extern void initialise_monitor_handles(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

int main(void)
{
	  volatile int i = 0;
	  char *Data = (char*)malloc(sizeof(char) * 256);
  /* USER CODE BEGIN 1 */
	initialise_monitor_handles();
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();

  /* USER CODE BEGIN 2 */

  //dmaTransmitData("okas");
 // i = dmaStreamTransferComplete(dma2 ,3);
  //i = dmaStreamTransferComplete(dma2 ,4);
  //i = dmaStreamTransferComplete(dma2 ,5);
  //i = dmaStreamTransferComplete(dma2 ,7);

/*
  //enable i2c1 event interrupt
  nvicEnableIrq(31);
  nvicSetPriority(31,8);
  //disable
  nvicDisableIrq(31);
*/

 // printf("helloWorld\n");
  enableGpioA();
  enableGpioG();


  // gpioConfig(GpioA,blueButtonPin, GPIO_MODE_IN ,0,GPIO_NO_PULL,0);
   gpioConfig(GpioG,redLedPin, GPIO_MODE_OUT , GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_LOW_SPEED);
 //  gpioConfig(GpioG,greenLedPin, GPIO_MODE_OUT , GPIO_PUSH_PULL,GPIO_PULL_DOWN,GPIO_VHIGH_SPEED);
 //  gpioConfig(GpioA,8, GPIO_MODE_AF , GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_VHIGH_SPEED);

 //  gpioConfigAltFuncNum(GpioA,8,ALT_FUNC0);
  // rccSelectMco1Src(MCO_HSE_SRC);
  // rccSetMco1Prescaler(MCO_DIV_5);

  // gpioConfig(GpioB,6, GPIO_MODE_AF , GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_LOW_SPEED);

 // nvicEnableIrq(80);
 // nvicSetPriority(80,4);

 // getRandomNumberByInterrupt();

//  sysTickSetReload(11250000);
//  sysTickSetReload(10);
 // sysTickPrescaledSpeed();
  //sysTickClrCounter();
 // sysTickEnable();
 // sysTickIntrEnable();


 //  nvicEnableIrq(6);
 //  nvicSetPriority(6,4);

 // sysTickDisable();
 // enableRng();
 // initTimer8();

 // InitI2c();

  //enable GPIO 0
 // risingDisable(0);
 // fallingDisable(0);
 // interMaskEnable(0);
 // risingEnable(0);

 // eventMaskEnable(0);

   //flashEraseSector(13);
  //flashEnableProgramming(FLASH_WORD_SIZE);
  //flashWriteMessage("hello world",(char *)0x08084000);
   enableDma(DMA2_DEV);
    dmaIntiForUsart1();

   gpioConfig(GpioA,9, GPIO_MODE_AF , GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_VHIGH_SPEED);
   gpioConfigAltFuncNum(GpioA,9,ALT_FUNC7);
   gpioConfig(GpioA,10, GPIO_MODE_AF , GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_VHIGH_SPEED);
   gpioConfigAltFuncNum(GpioA,10,ALT_FUNC7);




   enableUsart();
   initUsart();
   configBaudRate();
       EnableTrans();
       DisableReceiv();


 // Flash->SR |= FLASH_PGSERR;
 /*  flashEnableProgramming(FLASH_BYTE_SIZE);
   flashWriteMessage("hello world",(char *)0x08100000);
   flashEraseSector(12);
  if(flashEraseSector(13)==1){
//  flashEnableProgramming(FLASH_BYTE_SIZE);
  flashWriteMessage("hello world",(char *)0x08084000);
  flashDisable();
  while(1);
  }
  else{
	  while(1);
  }

*/


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

/*	  ReceiveTillEnter(&Data);
	  if(strcmp("turn on", &Data) == 0){
		  SET_PIN(GpioG,redLedPin);
	  	  	  }

	  else if(strcmp("turn off", &Data) == 0){
		  RESET_PIN(GpioG,redLedPin);
	  	  	  }
	  else{
	  }
*/
	// writeData("h");
	 // writeData("8");

	 /* writeData("h");
	  writeData("e");
	  writeData("l");
	  writeData("l");
	  writeData("o");
	  writeData(" ");
	  writeData("w");
	  writeData("o");
	  writeData("r");
	  writeData("l");
	  writeData("d");
	  writeData("\n");*/
	 // HAL_Delay(1000);


//	  int num = getRandomNumber();
//  printf("(%d) 0x%x\n",i++,num);
	//  volatile uint32_t flag =1;
/*
	  SET_PIN(GpioG,redLedPin);
	  while(!sysTickHasExpired());
	  RESET_PIN(GpioG,redLedPin);
	  while(!sysTickHasExpired());
*/
/*
	  RESET_PIN(GpioG,redLedPin);
	  SET_PIN(GpioG,greenLedPin);
	  wait500ms();
	  RESET_PIN(GpioG,greenLedPin);
	  SET_PIN(GpioG,redLedPin);
	  wait500ms();
*/
/*
	  volatile int blueButtonState;
	  SET_PIN(GpioG,redLedPin);
	  HAL_Delay(200);
	  RESET_PIN(GpioG,redLedPin);
	  HAL_Delay(200);

	  gpioLock(GpioG,redLedPin);
	  gpioConfig(GpioG,redLedPin, GPIO_MODE_IN , GPIO_PUSH_PULL,GPIO_NO_PULL,GPIO_LOW_SPEED);

	  blueButtonState = gpioRead(GpioA,blueButtonPin);
*/
  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 360;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Activate the Over-Drive mode 
    */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

void EXTI0_IRQHandler(void){

	clearPending(0);
	SET_PIN(GpioG,redLedPin);
	count++;
	RESET_PIN(GpioG,redLedPin);


}

void My_SysTick_Handler(void){
	static int ledState = 0;
	//jus ntg,but read the ctrl reg to clear countflag
	volatile int flags = Tick->CTRL;
	gpioWrite(GpioG,redLedPin,(ledState = !ledState));



}
void HASH_RNG_IRQHandler(void){
	volatile int rand = Rng->DR;
}

void wait500ms(){
	while(!(timer8->SR & 1)){

	}
	timer8->SR &=  0;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
