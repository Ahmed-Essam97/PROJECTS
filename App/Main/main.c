/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Ahmed Essam
 */ 

#include "PORT_Core.h"
#include "DC_MOTOR_Core.h"
#include "LCD_Core.h"
#include "TempSensor_Core.h"

#define F_CPU 16000000U
#include <util/delay.h>

int main(void)
{
	uint8 Temp = 0;
	PORT_Init();
	TempSensor_Init();
	DC_MOTOR_Init();
	LCD_Init();
	
	while (1)
	{
		Temp=TempSensor_Read();
		LCD_GoTo(0,0);
		LCD_WriteString("Room Temp = ");
		LCD_GoTo(0,12);
		LCD_WriteInteger(Temp);
		LCD_WriteChar('C');

		if (Temp>27)
		{
			DC_Motor2_Stop();
			DC_MOTOR1_Direction(Left);
			DC_MOTOR1_Speed(100);
			LCD_GoTo(1,0);
			LCD_WriteString("   HEATING ON");
		}
		else if (Temp<21)
		{
			DC_Motor1_Stop();
			DC_MOTOR2_Direction(Right);
			DC_MOTOR2_Speed(100);
			LCD_GoTo(1,0);
			LCD_WriteString("   COOLING ON");
		}
		else
		{
			DC_Motor1_Stop();
			DC_Motor2_Stop();
			LCD_GoTo(1,0);
			LCD_WriteString("  NORMAL TEMP   ");
		}
	}
}
