/**
  ******************************************************************************
  * @file           : ws2812.c
  * @brief          : ws2812驱动
  ******************************************************************************
  * @attention
  *		此驱动运行在STM32F103C8T6 72MHZ 主频下，GPIO翻转速度高速
  ******************************************************************************
  */
	
#ifndef	__WS2812_H
#define __WS2812_H

#include "stm32f1xx_hal.h"




#define WS2812_GPIO_PORT			GPIOA
#define WS2812_GPIO_PIN				GPIO_PIN_10



#define WS2812_WRITE_HIGH()		{WS2812_GPIO_PORT->BSRR = WS2812_GPIO_PIN;}
#define WS2812_WRITE_LOW()		{WS2812_GPIO_PORT->BSRR = (uint32_t)WS2812_GPIO_PIN << 16u;}



#define WS2812_WRITE_BIT_1()	do{\
	WS2812_WRITE_HIGH();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();\
	WS2812_WRITE_LOW();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	WS2812_WRITE_HIGH();\
}while(0)

#define WS2812_WRITE_BIT_0()	do{\
	WS2812_WRITE_HIGH();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	WS2812_WRITE_LOW();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();\
	__NOP();__NOP();__NOP();__NOP();\
	WS2812_WRITE_HIGH();\
}while(0)





typedef enum
{
	WS2812_Red				= ((uint32_t)0x0000FF00),
	WS2812_Green			= ((uint32_t)0x000000FF),
	WS2812_Blue				= ((uint32_t)0x00FF0000),
} WS2812_Color;












void ws2812_init(void);

void ws2812_set_color(WS2812_Color color);

void ws2812_reset(void);

#endif

