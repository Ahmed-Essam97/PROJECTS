/*
 * SMART_DOOR_Core.c
 *
 * Created: 10/11/2023 10:22:52 PM
 *  Author: ahmed
 */ 
#include "SMART_DOOR_Core.h"
uint8 Chk_Pass(uint8* PASS)
{
	uint8 i = 0 ,flag = 0;
	uint8 Rec_Status_main_l = 0,Input_Key = 0,Pass_enetred[4]={0};
	while (1)
	{
		Rec_Status_main_l = UART_ReceiveStatus();
		if (Rec_Status_main_l == 1)
		{
			LCD_WriteChar(42);
			Pass_enetred[Input_Key]=REC_DATA;
			Input_Key++;
			Rec_Status_main_l = 0;
		}
		if (Input_Key==4) break;
	}
	_delay_ms(100);
	LCD_WriteClear();
	for ( i = 0;i<4;i++)
	{
		if (Pass_enetred[i] != PASS[i])
		{
			flag = 0;
			break;
		}
		else flag = 1;
	}
	return flag;
}
uint8* Smart_Door_Get_Pass(void)
{
	static uint8 Current_Pass[4]={0};
	uint8 i = 0;
	while (i<4)
	{
		Current_Pass[i]=EEPROM_ReadByte(EEPROM_ADDRESS,i);
		i++;
		_delay_ms(2);
	}
	return Current_Pass;		
}
void Smart_Door_Close(void)
{
	Servo_Generate(0);
	LED_Toggle(LED_BLUE);
	LCD_WriteClear();
	LCD_WriteString("  CLOSING DOOR");
	_delay_ms(1000);
	
}
void Smart_Door_Enter(uint8* PASS)
{
	uint8  flag = 0,attemps=3;
	LCD_WriteClear();
	LCD_WriteString(" Enter Password");
	LCD_GoTo(1,5);
	while (1)
	{
		flag = Chk_Pass(PASS);
		if (flag == 1)
		{
			LCD_GoTo(0,2);
			LCD_WriteString("WELCOME HOME");
			LCD_GoTo(1,4);
			LCD_WriteString("Mr.ESSAM");
			Servo_Generate(90);
			LED_Toggle(LED_BLUE);
			_delay_ms(2000);
			attemps = 3;
			flag = 0;
			break;
		}
		else
		{
			attemps--;
			if (attemps == 0)
			{
				LCD_WriteString("WRONG PASSWORD!!");
				LCD_GoTo(1,0);
				LCD_WriteString("SYSTEM IS LOCKED");
				BUZZER_SET_VALUE(BUZZER_HIGH);
				while (1)
				{
					LED_Toggle(LED_BLUE);
					BUZZER_toggle();
					_delay_ms(500);
				}
			}
			else
			{
				LCD_WriteString("WRONG PASSWORD!!");
				LCD_GoTo(1,0);
				LCD_WriteInteger(attemps);
				LCD_WriteString(" Attempts left!");
				LED_Toggle(LED_BLUE);
				BUZZER_toggle();
				_delay_ms(2000);
				BUZZER_toggle();
				LED_Toggle(LED_BLUE);
				LCD_WriteClear();
				LCD_WriteString("Enter Password");
				LCD_GoTo(1,5);
			}
		}
	}
}
void Smart_Door_Set(uint8* PASS)
{
	uint8 flag = 0, New_Pass[4]={0},key=0, Rec_Status_main_l =0;
	LCD_WriteClear();
	LCD_WriteString("Enter OLD Pass");
	LCD_GoTo(1,5);
	flag = Chk_Pass(PASS);
	if (flag == 1)
	{
		LCD_WriteClear();
		LCD_WriteString("Enter NEW Pass");
		LCD_GoTo(1,5);
		while (1)
		{
			Rec_Status_main_l = UART_ReceiveStatus();
			if (Rec_Status_main_l == 1)
			{
				LCD_WriteChar(42);
				New_Pass[key]=REC_DATA;
				key++;
				Rec_Status_main_l = 0;
			}
			if (key==4)
			{
				_delay_ms(100);
				LCD_WriteClear();
				LCD_WriteString("PASSWORD UPDATED");
				EEPROM_WriteMultipleBytes(New_Pass,4,EEPROM_ADDRESS,0X00);
				_delay_ms(1000);
				break;
			}
		}
	}
	else if(flag ==0)
	{
		LCD_WriteClear();
		LCD_WriteString(" WRONG PASSWORD");
		_delay_ms(1000);
	}
}