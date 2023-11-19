/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Ahmed Essam
 */ 

#include "BTN.h"
#include "PORT_Core.h"
#include "SPI_Core.h"
#include "IRQH_CORE.h"
#include "BTN.h"
#include "TIMER_CORE.h"
#include "LCD_Core.h"
#include "LED.h"

#define  F_CPU  16000000U
#include <util/delay.h>
uint8 Data = 0;
void Task(void)
{
	
	Data=SPI_TranSiver(11);
	if (Data<100)
	{
		LCD_GoTo(1,10);
		LCD_WriteInteger(Data);
		LCD_GoTo(1,12);
		LCD_WriteString("CM  ");
	}	
}

/*project to take from user minutes and seconds to set timer*/
int main(void)
{	
	PORT_Init();
	LCD_Init();
	LCD_GoTo(1,0);
	LCD_WriteString("DISTANCE:     ");

	IRQH_SetGloabINT(INT_ENABLE);
	SPI_Init();
	GPT_Init();
	GPT_SetTime();
	IRQH_SetCallBack(Timer_Counter1_Compare_Match_A_VECTOR_INDEX,Task);
	uint8 BTN1 = 0,BTN2 = 0,BTN3 = 0,BTN4 = 0;
	
	while (1)
	{
		BTN1 = BTN_GetValue(Button_0);
		BTN2 = BTN_GetValue(Button_1);
		BTN3 = BTN_GetValue(Button_2);
		BTN4 = BTN_GetValue(Button_3);
		
		if ( BTN1 == pressed)
		{	
			DIO_WriteChennel(PORTB_PIN0,PIN_LOW);
			SPI_TranSiver(10);
			DIO_WriteChennel(PORTB_PIN0,PIN_HIGH);
			LCD_GoTo(0,0);
			LCD_WriteString("DUTY CYCLE:     ");		
			LCD_GoTo(0,12);
 			LCD_WriteString("50%  ");
		}
		if ( BTN2 == pressed)
		{
			DIO_WriteChennel(PORTB_PIN0,PIN_LOW);
			SPI_TranSiver(20);
			DIO_WriteChennel(PORTB_PIN0,PIN_HIGH);
			LCD_GoTo(0,0);
			LCD_WriteString("DUTY CYCLE:     ");
			LCD_GoTo(0,12);
			LCD_WriteString("100%");
		}
		if ( BTN3 == pressed)
		{
			DIO_WriteChennel(PORTB_PIN0,PIN_LOW);
			SPI_TranSiver(30);
			DIO_WriteChennel(PORTB_PIN0,PIN_HIGH);
			LCD_GoTo(0,0);
			LCD_WriteString(" REVERSED MOTOR ");
		}
		if ( BTN4 == pressed)
		{
			DIO_WriteChennel(PORTB_PIN0,PIN_LOW);
			SPI_TranSiver(40);
			DIO_WriteChennel(PORTB_PIN0,PIN_HIGH);
			LCD_GoTo(0,0);
			LCD_WriteString("     BRAKES     ");
		}
		if (Data < 20)
		
		{
			DIO_WriteChennel(PORTB_PIN0,PIN_LOW);
			SPI_TranSiver(40);
			DIO_WriteChennel(PORTB_PIN0,PIN_HIGH);
			LCD_GoTo(0,0);
			LCD_WriteString("EMERGENCY BRAKES");
		}

	}
}

