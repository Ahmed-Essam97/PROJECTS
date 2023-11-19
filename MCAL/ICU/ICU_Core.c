
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  ICU_Core.c
 *        \brief  
 *
 *      \details  
 * Created: 9/23/2023 4:54:57 PM
 *  Author: ahmed
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "ICU_Core.h"

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
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void ICU_Init(void)
{
	GPT_Init();
	SET_BIT(TCCR1B,6);
	SET_BIT(TIMSK,5);
}
uint32 ICU_Capture_Time(void)
{
	uint32 Time = 0;
	
	if (ICU_Cnt == 2)
	{
		Time = (Cap_2 - Cap_1)*64;
		SET_BIT(TIMSK,5);
	}
	ICU_Cnt = 0;
	return Time;
}

/**********************************************************************************************************************
 *  END OF FILE: ICU_Core.c
 *********************************************************************************************************************/
