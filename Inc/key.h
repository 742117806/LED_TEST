#ifndef __KEY_H__
#define __KEY_H__
#include "stm32f1xx_hal.h"

//按键对象结构体
typedef struct 
{
	uint8_t sta;
	uint8_t (*getsta)(void);
}KeyObj;

extern KeyObj key0;
extern KeyObj key1;
extern KeyObj key2;

typedef enum
{
	KEY_NOT,
	KEY0_PRES,
	KEY1_PRES,
	KEY2_PRES,
	
}KEY_VALUE;

uint8_t drv_key0_getsta(void);
uint8_t drv_key1_getsta(void);
uint8_t drv_key2_getsta(void);

uint8_t key_getsta(KeyObj *key);
KEY_VALUE key_scan(uint8_t mode);

#endif
