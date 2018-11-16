
#include "key.h"
#include "main.h"

KeyObj key0={
	.getsta = drv_key0_getsta,
};

KeyObj key1={
	.getsta = drv_key1_getsta,
};

KeyObj key2={
	.getsta = drv_key2_getsta,
};


uint8_t drv_key0_getsta(void)
{
   return (HAL_GPIO_ReadPin(KEY0_GPIO_Port,KEY0_Pin));
}


uint8_t drv_key1_getsta(void)
{
   return (HAL_GPIO_ReadPin(KEY1_GPIO_Port,KEY1_Pin));
}


uint8_t drv_key2_getsta(void)
{
   return (HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin));
}

uint8_t key_getsta(KeyObj *key)
{
   key->sta = key->getsta();
   return key->sta;
}



////按键处理函数
////返回按键值
////mode:0,不支持连续按;1,支持连续按;
////0，没有任何按键按下
////1，KEY0按下
////2，KEY1按下
////3，KEY2按下 

////注意此函数有响应优先级,KEY0>KEY1>KEY2>KEY3!!
//KEY_VALUE key_scan(uint8_t mode)
//{	 
//	static uint8_t key_up=1;//按键按松开标志
//	if(mode)key_up=1;  //支持连按		  
//	if(key_up&&(key_getsta(&key0)==0||key_getsta(&key1)==0||key_getsta(&key2)==0))
//	{
//		HAL_Delay(10);//去抖动 
//		key_up=0;
//		
//		if(key_getsta(&key0)==0)return KEY0_PRES;
//		else if(key_getsta(&key1)==0)return KEY1_PRES;
//		else if(key_getsta(&key2)==0)return KEY2_PRES;
//	
//	}else if(key_getsta(&key0)==1&&key_getsta(&key1)==1&&key_getsta(&key2)==1)key_up=1; 	    
// 	return KEY_NOT;// 无按键按下
//}
