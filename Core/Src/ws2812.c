/**
  ******************************************************************************
  * @file           : ws2812.c
  * @brief          : ws2812����
  ******************************************************************************
  * @attention
  *		������������STM32F103C8T6 72MHZ ��Ƶ�£�GPIO��ת�ٶȸ���
  ******************************************************************************
  */
	
#include "ws2812.h"


void ws2812_init(void)
{
	HAL_GPIO_WritePin(WS2812_GPIO_PORT, WS2812_GPIO_PIN, GPIO_PIN_SET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(WS2812_GPIO_PORT, WS2812_GPIO_PIN, GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(WS2812_GPIO_PORT, WS2812_GPIO_PIN, GPIO_PIN_SET);
	HAL_Delay(10);
}




void ws2812_set_color(WS2812_Color color)
{
	uint16_t i;
	
	for(i = 0; i < 24; i++)
	{
		if(color & 0x00000001)
			WS2812_WRITE_BIT_1();
		else
			WS2812_WRITE_BIT_0();
		color = color >> 1;
	}
}


void ws2812_reset(void)
{
	uint8_t i = 200;
	
	WS2812_WRITE_LOW();
	while(i--)
	{
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
		
	}
	WS2812_WRITE_HIGH();
}
