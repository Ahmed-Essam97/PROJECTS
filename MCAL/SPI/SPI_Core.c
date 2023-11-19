/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  SPI_Core.c
 *        \brief  
 * Created: 9/30/2023 6:18:03 PM
 *  Author: ahmed
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SPI_Core.h"

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
void SPI_Init(void)
{
	#if   (SPI_MODE == SPI_MASTER)
	SPI->SPCR |=0x50;
	#if   (SPI_CLK_RATE == SPI_CLK_4)
	CLR_BIT(SPI->SPCR , 0);
	CLR_BIT(SPI->SPCR , 1);
	#elif (SPI_CLK_RATE == SPI_CLK_16)
	SET_BIT(SPI->SPCR , 0);
	#elif (SPI_CLK_RATE == SPI_CLK_64)
	SET_BIT(SPI->SPCR , 1);
	#elif (SPI_CLK_RATE == SPI_CLK_128)
	#endif /*if (SPI_CLK_RATE==SPI_CLK_128)*/

	
	#if   (SPI_CLK_SAMPLE == LEADING_EDGE)
	CLR_BIT(SPI->SPCR , 2);
	#elif (SPI_CLK_SAMPLE == TRAILING_EDGE)
	SET_BIT(SPI->SPCR , 2);
	#endif /*if (SPI_CLK_SAMPLE==LEADING_EDGE)*/
	
	#if   (SPI_CLK_POLARITY_RISING == LEADING_EDGE)
	CLR_BIT(SPI->SPCR , 3);
	#elif (SPI_CLK_POLARITY_RISING == TRAILING_EDGE)
	SET_BIT(SPI->SPCR , 3);
	#endif /*if (SPI_CLK_POLARITY_RISING==LEADING_EDGE)*/
	
	#if   (SPI_DATA_ORDER == ORDER_MSB)
	CLR_BIT(SPI->SPCR , 5);
	#elif (SPI_DATA_ORDER == ORDER_LSB)
	SET_BIT(SPI->SPCR , 5);
	#endif /*if (SPI_DATA_ORDER==ORDER_MSB)*/
	
	#elif (SPI_MODE == SPI_SLAVE)
	SET_BIT(SPI->SPCR , 6);
	#endif /*if(SPI_MODE == SPI_MASTER)*/
	
	#if   (SPI_INT_STATUS == SPI_INT_ENABLE)
	SET_BIT(SPI->SPCR , 7);
	#elif (SPI_INT_STATUS == SPI_INT_DISABLE)
	CLR_BIT(SPI->SPCR , 7);
	#endif /*if (SPI_INT_STATUS==DISABLE)*/
	
	// 	#if   (SPI_MODE == SPI_MASTER)
	/*	SPI->SPCR |= 0X53;*/
	// 	#elif (SPI_MODE == SPI_SLAVE)
	// 	SPI->SPCR |= 0X40;
	// 	#endif /*if   (SPI_STATUS == SPI_MASTER)*/
}
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

uint8 SPI_TranSiver(uint8 Trans_Data)
{
	uint8 Rec_Data = 0;
	SPI->SPDR = Trans_Data;
	
	while (!GET_BIT(SPI->SPSR , 7));
	
	Rec_Data = SPI->SPDR;
	return Rec_Data;
}
/**********************************************************************************************************************
 *  END OF FILE: SPI_Core.c
 *********************************************************************************************************************/
