/*
 * COTS.c
 *
 * Created: 8/12/2023 3:34:43 PM
 * Author : Ahmed Essam
 */ 


#include "PORT_Core.h"
#include "IRQH_Core.h"
#include "ULTRA_SONIC.h"
#include "PWM_Core.h"
#include "ICU_Core.h"




#define  F_CPU  16000000U
#include <util/delay.h>

int main(void)
{
	
	PORT_Init();
	IRQH_SetGloabINT(INT_ENABLE);
	PWM_Init();
	ICU_Init();
	LCD_Init();
	
	PWM0_Generate(74);
	while (1)
	{
		ICU_Pulse();
		
		LCD_GoTo(0,0);
		LCD_WriteString("Duty Cycle:");
		LCD_WriteInteger( Duty_CY);
		LCD_WriteString("%");
		
		LCD_GoTo(1,0);
		LCD_WriteString("Freq:");
		LCD_WriteInteger(Freq);
		LCD_WriteString("Hz");
		_delay_ms(1000);
	}
}

