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
#include "DC_MOTOR_Core.h"


int main(void)
{
	//REC
	PORT_Init();
	LCD_Init();
	IRQH_SetGloabINT(INT_ENABLE);
	uint8 DATA = 0;
	SPI_Init();
	DC_MOTOR_Init();
	while (1)
	{
		DATA = SPI_TranSiver(1);
		if (DATA == 10)
		{
			DC_MOTOR_Direction(Right);
			DC_MOTOR_Speed(50);
			
		}
		if (DATA == 20)
		{
			DC_MOTOR_Direction(Right);
			DC_MOTOR_Speed(100);
			
		}
		if (DATA == 30)
		{
			DC_MOTOR_Direction(Left);
			DC_MOTOR_Speed(20);
			
		}
		if (DATA == 40)
		{
			DC_Motor_Stop();
			
		}
		
	}	
}

