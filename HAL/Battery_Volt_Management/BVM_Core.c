
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  BVM_CORE.c
 *        \brief  battery volt measurment
 * Created: 9/15/2023 8:55:05 PM
 *  Author: ahmed
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "BVM_CORE.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint32 arr[size_arr]= {0};
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
* \Syntax          : void BVM_Init(void)       
* \Description     : init the ADC Signal                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : void  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void BVM_Init(void)
{
	ADC_Init();
}
/******************************************************************************
* \Syntax          : void BVM_Read(void)
* \Description     : Read the measured volt and display on LCD
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : void  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void BVM_Read(void)
{
	uint8 i =0 , j =0 ;
	uint32 temp = 0;

	static uint32 BVM_Reading = 0 ;
	for (i = 0 ; i < size_arr ; i++)
	{
		arr[i]=ADC_Vin_Value;
	}
	for(i=0;i<size_arr-1;i++)
	{
		for(j=i+1;j<size_arr;j++)
		{
			if(arr[j]<arr[i])
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}
	}
	BVM_Reading =(((arr[size_arr/2]*(37900+50500))/37900));
	LCD_WriteClear();
	//LCD_WriteString("The Battery Volt");
	LCD_GoTo(1,0);
	//LCD_WriteString("= ");
	LCD_WriteInteger(BVM_Reading);
	//LCD_WriteString(" mV ");
	LCD_WriteChar(0x06);
	Custom_char();
	_delay_ms(100);
}



/**********************************************************************************************************************
 *  END OF FILE: BVM_CORE.c
 *********************************************************************************************************************/