#ifndef __LED_H__
#define __LED_H__

#include "stm32f1xx_hal.h"

//LED对象结构体
typedef struct 
{
	uint8_t sta;
	void (*setsta)(uint8_t sta);
}LedObj;

extern LedObj led0;
extern LedObj led1;
extern LedObj led2;

void drv_led0_setsta(uint8_t sta);
void drv_led1_setsta(uint8_t sta);
void drv_led2_setsta(uint8_t sta);
void led_set(LedObj *led,uint8_t sta);


#endif

