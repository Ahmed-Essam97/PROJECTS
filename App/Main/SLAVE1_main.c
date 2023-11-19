/*
 * COTS.c
 * Created: 8/12/2023 3:34:43 PM
 * Author : Ahmed Essam
 */ 

#include "PORT_Core.h"
#include "SPI_Core.h"
#include "IRQH_CORE.h"
#include "LCD_Core.h"
#include "MCU.h"
#include "ICU_Core.h"
#include "ULTRA_SONIC.h"
#include "TIMER_CORE.h"


int main(void)
{
	//REC
	PORT_Init();
	SPI_Init();
	LCD_Init();
	IRQH_SetGloabINT(INT_ENABLE);
	ICU_Init();
	uint8 dist=0;
	
	while (1)
	{
		Ultra_Sonic_Trigger();
		dist=Ultra_Sonic_GetDist();
		
		SPI_TranSiver(dist);
		LCD_WriteClear();
		LCD_WriteInteger(dist);
		_delay_ms(10);
	}	
}

