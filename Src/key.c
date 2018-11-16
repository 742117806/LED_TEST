
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



////����������
////���ذ���ֵ
////mode:0,��֧��������;1,֧��������;
////0��û���κΰ�������
////1��KEY0����
////2��KEY1����
////3��KEY2���� 

////ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>KEY3!!
//KEY_VALUE key_scan(uint8_t mode)
//{	 
//	static uint8_t key_up=1;//�������ɿ���־
//	if(mode)key_up=1;  //֧������		  
//	if(key_up&&(key_getsta(&key0)==0||key_getsta(&key1)==0||key_getsta(&key2)==0))
//	{
//		HAL_Delay(10);//ȥ���� 
//		key_up=0;
//		
//		if(key_getsta(&key0)==0)return KEY0_PRES;
//		else if(key_getsta(&key1)==0)return KEY1_PRES;
//		else if(key_getsta(&key2)==0)return KEY2_PRES;
//	
//	}else if(key_getsta(&key0)==1&&key_getsta(&key1)==1&&key_getsta(&key2)==1)key_up=1; 	    
// 	return KEY_NOT;// �ް�������
//}
