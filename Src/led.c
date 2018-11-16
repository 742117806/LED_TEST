
#include "led.h"
#include "main.h"
#include "stm32f1xx_hal.h"

//对象实体定义
LedObj led0={
	.sta = 1,
	.setsta = drv_led0_setsta,
};

LedObj led1={
	.sta = 1,
	.setsta = drv_led1_setsta,
};

LedObj led2={
	.sta = 0,
	.setsta = drv_led2_setsta,
};


//硬件相关驱动接口
void drv_led0_setsta(uint8_t sta)
{
	HAL_GPIO_WritePin(LED0_GPIO_Port,LED0_Pin,(GPIO_PinState)sta);
}


void drv_led1_setsta(uint8_t sta)
{
	HAL_GPIO_WritePin(LED1_GPIO_Port,LED1_Pin,(GPIO_PinState)sta);
}

void drv_led2_setsta(uint8_t sta)
{
	HAL_GPIO_WritePin(LED2_GPIO_Port,LED2_Pin,(GPIO_PinState)sta);
}


//LED对象操作接口(API)
void led_set(LedObj *led,uint8_t sta)
{
	led->setsta(sta); 
	led->sta = sta;
}





