/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT_LCFG.c
 *        \brief  identify the inputs and outputs in Micro controller
 *
 *      \details  lists the used pins in projects and set direction of each as i/o.
 *	 Created: 8/19/2023 3:47:25 PM
 *  Author: Ali
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PORT_LCFG.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const PIN_PARAMETERS PORT_Initialization[DEFINED_PINS] = {
//SPI
{PORTB_PIN4,PIN_OUTPUT}, //CS
{PORTB_PIN5,PIN_OUTPUT}, //MOSI
{PORTB_PIN6,PIN_INPUT},  //MISO
{PORTB_PIN7,PIN_OUTPUT}, //CLK
// 	//REDLED
// {PORTC_PIN0,PIN_OUTPUT},
// //GREENLED
// {PORTC_PIN1,PIN_OUTPUT},
// //BLUELED
// {PORTC_PIN2,PIN_OUTPUT},	
// {PORTD_PIN6,PIN_INPUT},  //echo
// {PORTD_PIN0,PIN_OUTPUT}, //trigger
/*DC MOTOR DIRECTIONS*/
// {PORTC_PIN0,PIN_OUTPUT},
// {PORTC_PIN1,PIN_OUTPUT},		
//DCmotor pwm output
// {PORTC_PIN0,PIN_OUTPUT},
// {PORTC_PIN1,PIN_OUTPUT},
// {PORTB_PIN2,PIN_INPUT},	
// {PORTB_PIN3,PIN_INPUT},
// {PORTB_PIN4,PIN_INPUT},	
//servo pwm output
// {PORTB_PIN3,PIN_OUTPUT},
// {PORTD_PIN5,PIN_OUTPUT},


// 	//LCD PINS
	{PORTA_PIN1 , PIN_OUTPUT},
	{PORTA_PIN2 , PIN_OUTPUT},
	{PORTA_PIN3 , PIN_OUTPUT},
	{PORTA_PIN4 , PIN_OUTPUT},
	{PORTA_PIN5 , PIN_OUTPUT},
	{PORTA_PIN6 , PIN_OUTPUT},
// 	
// 	//KEYPAD PINS
		/*Row0*/
// 	{PORTB_PIN4 , PIN_OUTPUT},
// 		/*Row1*/
// 	{PORTB_PIN5 , PIN_OUTPUT},
// 		/*Row2*/
// 	{PORTB_PIN6 , PIN_OUTPUT},
// 		/*Row3*/
// 	{PORTB_PIN7 , PIN_OUTPUT},
// 		/*Col0*/
// 	{PORTD_PIN2 , PIN_INPUT},
// 		/*Col1*/
// 	{PORTD_PIN3 , PIN_INPUT},
// 		/*Col2*/
// 	{PORTD_PIN4 , PIN_INPUT},
// 		/*Col3*/
// 	{PORTD_PIN5 , PIN_INPUT}	
	
	
	
// 	/*7seg dig1 and dig2 as outputs*/
// 	{PORTC_PIN6 , PIN_OUTPUT},
// 	{PORTC_PIN7 , PIN_OUTPUT},
// 	/*output pins to the 7seg digits as outputs*/
// 	{PORTA_PIN0 , PIN_OUTPUT},
// 	{PORTA_PIN1 , PIN_OUTPUT},
// 	{PORTA_PIN2 , PIN_OUTPUT},
// 	{PORTA_PIN3 , PIN_OUTPUT},
// 	{PORTA_PIN4 , PIN_OUTPUT},
// 	{PORTA_PIN5 , PIN_OUTPUT},
// 	{PORTA_PIN6 , PIN_OUTPUT},
// 	{PORTA_PIN7 , PIN_OUTPUT},
// 	/*BUZZER as output	*/
// 	{PORTC_PIN5 , PIN_OUTPUT},
// 	/*buttons as inputs*/	
	{PORTD_PIN2 , PIN_INPUT},
	{PORTD_PIN3 , PIN_INPUT},
	{PORTD_PIN4 , PIN_INPUT},
	{PORTD_PIN5 , PIN_INPUT}	
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: PORT_LCFG.c
 *********************************************************************************************************************/
