/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <DIO_Core.h>
 *       Module:  1.0
 *		Created: 8/19/2023 5:45:00 PM
 *		Author: /*
 * SMART_DOOR_Core.h
 *
 * Created: 10/11/2023 10:22:59 PM
 *  Author: ahmed
 */ 


#ifndef SMART_DOOR_CORE_H_
#define SMART_DOOR_CORE_H_


#define  F_CPU  16000000U
#include <util/delay.h>
#include "SERVO_MOTOR_Core.h"
#include "EEPROM_Core.h"
#include "LCD_Core.h"
#include "LED.h"
#include "BUZZER.h"
#include "UART_Core.h"

uint8* Smart_Door_Get_Pass(void);
void Smart_Door_Enter(uint8*);
void Smart_Door_Set(uint8*);
uint8 Chk_Pass(uint8* );
void Smart_Door_Close(void);

#endif /* SMART_DOOR_CORE_H_ */
 *	  Description:  <Read/Write on ports and pins>     
 *********************************************************************************************************************/
#ifndef DIO_CORE_H_
#define DIO_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "MCU.h"
#include "STD.h"
#include "BIT_Math.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define  NUMBER_OF_EACH_PORT_PINS     8


#define PORTA_PIN0  0
#define PORTA_PIN1  1
#define PORTA_PIN2  2
#define PORTA_PIN3  3
#define PORTA_PIN4  4
#define PORTA_PIN5  5
#define PORTA_PIN6  6
#define PORTA_PIN7  7


#define PORTB_PIN0  8
#define PORTB_PIN1  9
#define PORTB_PIN2  10
#define PORTB_PIN3  11
#define PORTB_PIN4  12
#define PORTB_PIN5  13
#define PORTB_PIN6  14
#define PORTB_PIN7  15

#define PORTC_PIN0  16
#define PORTC_PIN1  17
#define PORTC_PIN2  18
#define PORTC_PIN3  19
#define PORTC_PIN4  20
#define PORTC_PIN5  21
#define PORTC_PIN6  22
#define PORTC_PIN7  23

#define PORTD_PIN0  24
#define PORTD_PIN1  25
#define PORTD_PIN2  26
#define PORTD_PIN3  27
#define PORTD_PIN4  28
#define PORTD_PIN5  29
#define PORTD_PIN6  30
#define PORTD_PIN7  31

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	PIN_LOW = 0,
	PIN_HIGH
}PIN_VALUE_t;



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void DIO_WriteChennel(uint8 Pin_Num , PIN_VALUE_t Pin_value );
void DIO_ReadChennel(uint8 Pin_Num , PIN_VALUE_t * Pin_value );
void DIO_FlipChennel(uint8 Pin_Num);
void DIO_WritePort(uint8 Pin_Num , uint8 Port_value );
void DIO_ReadPort(uint8 Pin_Num , uint8 * Port_value );
void DIO_ReadOutPutPort(uint8 Pin_Num , uint8 * Port_value );
 
#endif /* DIO_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: DIO_Core.h
 *********************************************************************************************************************/


