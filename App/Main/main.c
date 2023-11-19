
#include "PORT_Core.h"
#include "LCD_Core.h"
#include "LCD_Core.h"
#include "UART_Core.h"
#include "IRQH_CORE.h"
#include "SERVO_MOTOR_Core.h"
#include "SMART_DOOR_Core.h"
#define  F_CPU  16000000U
#include <util/delay.h>


#define LCD_RST	LCD_WriteClear();LCD_WriteString("1-Close Door");\
				LCD_GoTo(1,0);	LCD_WriteString("2-Set Password");
int main(void)
{
	PORT_Init();
	LCD_Init();
	UART_Init();
	Servo_Init();
	I2C_MasterInit();
	
	IRQH_SetGloabINT(INT_ENABLE);
	IRQH_SetCallBack(USART_Rx_Complete_VECTOR_INDEX,UART_ReceiveData);
	
	uint8* PASS = Null;
	uint8 Rec_Status_main_l = 0;
	uint8 BTN = 0;
	uint8 choice = 0;
	
		LCD_GoTo(0,0);		LCD_WriteString("SMART DOOR LOCK");		_delay_ms(1500);		LCD_GoTo(0,0);		LCD_WriteString("    MADE BY:    ");		LCD_GoTo(1,0);		LCD_WriteString("ENG.AHMED ESSAM");		_delay_ms(1500);		LCD_WriteClear();	PASS=Smart_Door_Get_Pass();	Smart_Door_Enter(PASS);	LCD_RST		while (1)
		{
			Rec_Status_main_l = UART_ReceiveStatus();
			if (Rec_Status_main_l == 1)
			{
				choice = REC_DATA;
			}


			
			if (choice == '1')
			{
				Smart_Door_Close();
				choice = 0;
				Smart_Door_Enter(PASS);
				LCD_RST
			}
			else if (choice == '2')
			{
				Smart_Door_Set(PASS);
				PASS=Smart_Door_Get_Pass();
				choice = 0;
				LCD_RST
			}			else if (choice == '2')
			{
				LCD_WriteString("WRONG INPUT");
				_delay_ms(1000);
				choice = 0;
				LCD_RST
			}		}
}

