/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**       \file  BTN.c
 *        \brief  get the value of the buttons if pressed or not
 *		  \Created: 8/17/2023 4:41:52 PM
 *		  \Author: Ahmed
 *		  \details  BUTTON_get_val ->	return with the value if pressed or not

 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "BTN.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

 

/******************************************************************************
* \Syntax          : uint8 BTN_GetValue(uint8 Button_num)
* \Description     : return with the value if pressed or not
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : uint8  E_OK
*                                    E_NOT_OK
*******************************************************************************/
uint8 BTN_GetValue(uint8 Button_num)
{
	uint8 button = 1, temp = 0;
	
	DIO_ReadChennel(Button_num , &button);
	
	while(temp == 0)
	{
		DIO_ReadChennel(Button_num , &temp);
	}
	_delay_ms(10);
	
	return button;
}

/**********************************************************************************************************************
 *  END OF FILE: BTN.c
 *********************************************************************************************************************/
