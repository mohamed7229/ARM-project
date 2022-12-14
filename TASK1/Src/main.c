/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "DATA_TYPE.h"
#include "STM32f103XX.h"
#include <stdint.h>
#include "CLK_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_TIMER_interface.h"


int main(void)
{
	 u8 x=0;
	 u32 res=2000000;
	PIN_CINFIG str  ={GPIOB_U8_PORT,GPIO_U8_PIN4,GPIO_U8_INPUT_PULLDOWN};


	PIN_CINFIG str3  ={GPIOA_U8_PORT,GPIO_U8_PIN1,GPIO_U8_OUTPUT_PUSH_PULL_10MHZ };
	PIN_CINFIG str4 ={GPIOA_U8_PORT,GPIO_U8_PIN4,GPIO_U8_OUTPUT_PUSH_PULL_10MHZ };
	PIN_CINFIG str5 ={GPIOA_U8_PORT,GPIO_U8_PIN7,GPIO_U8_OUTPUT_PUSH_PULL_10MHZ };

	RCC_u8EnPripheral(GPIO_U8_PORTB_CLK);
	RCC_u8EnPripheral(GPIO_U8_PORTA_CLK);


	GPIO_voidInit(&str);


    GPIO_voidInit(&str3);
	GPIO_voidInit(&str4);
	GPIO_voidInit(&str5);

	GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN1,GPIO_U8_LOW);
	GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN4,GPIO_U8_LOW);
	GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN7,GPIO_U8_LOW);
	GPIO_u8SetPinValue(GPIOB_U8_PORT,GPIO_U8_PIN4,GPIO_U8_LOW);

	for(;;)
	{
	while(x!=1)
	{
		GPIO_u8GetPinValue(GPIOB_U8_PORT,GPIO_U8_PIN4,&x);
	}
			sys_tictime(7000000);
			while(1)
			{
				GPIO_u8GetPinValue(GPIOB_U8_PORT,GPIO_U8_PIN4,&x);
				if(x!=1)
				{
				res =	ReturnSystickval();
				disableSys_tmr();
				break;
				}
			}

	  if(res>4000000)
	  {
         GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN1,GPIO_U8_HIGH);
         GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN4,GPIO_U8_LOW);
         GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN7,GPIO_U8_LOW);

	  }

		else if((res<4000000) && (res>2000000))
        {
        	 GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN4,GPIO_U8_HIGH);
        	 GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN1,GPIO_U8_LOW);
        	 GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN7,GPIO_U8_LOW);
        }
		else if(res<2000000)
        {
        	 GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN7,GPIO_U8_HIGH);
        	 GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN1,GPIO_U8_LOW);
        	 GPIO_u8SetPinValue(GPIOA_U8_PORT,GPIO_U8_PIN4,GPIO_U8_LOW);
       }

	}
}
