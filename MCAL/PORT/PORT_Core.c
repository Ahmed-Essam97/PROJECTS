/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT_Core.c
 *        \brief initialize the direction of pins as input/output
 *		Created: 8/19/2023 3:52:43 PM
 *		Author: Ahmed
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PORT_Core.h"

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
* \Syntax          : void PORT_Init(void)       
* \Description     : takes the port and pin and set the direction as input/output                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void PORT_Init(void)
{
	uint8 Cnt = 0 , Port = 0 , Pin = 0 , Dir = 0 ;
	
	for(Cnt = 0 ; Cnt < DEFINED_PINS ; Cnt++)
	{
		Port = PORT_Initialization[Cnt].PIN_NUM / NUMBER_OF_EACH_PORT_PINS ;
		Pin = PORT_Initialization[Cnt].PIN_NUM % NUMBER_OF_EACH_PORT_PINS  ;
		Dir = PORT_Initialization[Cnt].PIN_DIR ;
		
		switch(Dir)
		{
			case PIN_OUTPUT :
			
			switch(Port)
			{
				case 0:
				SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR) ,Pin );

				break;
				
				case 1:
				SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR) ,Pin );
				
				break;
				
				case 2:
				SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR) ,Pin );
				
				break;
				
				case 3:
				SET_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR) ,Pin );
				
				break;
				
				default:
				break;
			}
			break;
			
			case PIN_INPUT :
			switch(Port)
			{
				case 0:
				CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOA_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR) ,Pin );

				break;
				
				case 1:
				CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOB_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR) ,Pin );
				
				break;
				
				case 2:
				CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOC_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR) ,Pin );
				
				break;
				
				case 3:
				CLR_BIT(PHYSICAL_GPIO_ACCESS(GPIOD_BASE_ADDRRESS + GPIO_DIRCETION_REGISTER_DDR) ,Pin );
				
				break;
				
				default:
				break;
			}
			break;
			
			default:
			break;
		}
	}
}
/**********************************************************************************************************************
 *  END OF FILE: PORT_Core.c
 *********************************************************************************************************************/
