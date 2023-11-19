/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  UART_Core.c
 *        \brief  
 * Created: 9/29/2023 2:49:20 PM
 *  Author: ahmed
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "UART_Core.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint8 UART_RECEIEVED_DATA[10]={0};
uint8 REC_DATA = 0;	
uint8 UART_TRANSMITTED_DATA[TX_BUFFER_SIZE]={0};
	
uint8 RECEIEVED_STATUS_FLAG = 0 ;
uint8 TX_STATUS_FLAG = 0 ;
uint8 TX_Cnt = 0 ;

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
void UART_Init(void)
{
	uint8 BaudRate_Value_l = 0 ;
// 	#if (UART_PARITY_STATE == ENABLE)	
// 	  #if   (UART_PARITY_TYPE == PARITY_ODD)
// 	  UCSRC |= 0XD0;
// 	  #elif (UART_PARITY_TYPE == PARITY_EVEN)
// 	  UCSRC |= 0XA0;	
// 	  #endif /*if (UART_POLARITY_TYPE == POLARITY_ODD)*/	  
// 	#endif /*if (UART_POLARITY_STATE == ENABLE)*/
// 	
	#if   (UART_DATA_BYTES == UART_DATA_BYTES_5)
	UCSRC |= 0X80;
	#elif (UART_DATA_BYTES == UART_DATA_BYTES_6)
	UCSRC |= 0X82;
	#elif (UART_DATA_BYTES == UART_DATA_BYTES_7)
	UCSRC |= 0X84;
	#elif (UART_DATA_BYTES == UART_DATA_BYTES_8)
	UCSRC |= 0X86;
	#elif (UART_DATA_BYTES == UART_DATA_BYTES_9)
	UCSRC |= 0X86;
	UCSRB |= 0X04;
	#endif /*if   (UART_DATA_BYTES == UART_DATA_BYTES_5)*/
	
	#if (UART_INTERRUPT_STATE == ENABLE)
	SET_BIT(UCSRB,6);
	SET_BIT(UCSRB,7);
	#elif (UART_INTERRUPT_STATE == DISABLE)
	CLR_BIT(UCSRB,6);
	CLR_BIT(UCSRB,7);
	#endif /*if (UART_INTERRUPT_STATE == ENABLE)*/
	
	SET_BIT(UCSRB,4); /*RX Enable*/
	SET_BIT(UCSRB,3); /*TX Enable*/
	
	BaudRate_Value_l = (160000/(UART_BAUD_RATE *16)) - 1;
	UBRRL = BaudRate_Value_l;
	
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
void UART_InitiateTX(void)
{
	TX_STATUS_FLAG = 1;
	SET_BIT(UCSRB , 6);
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

void UART_SendData(void)
{
	 
	if (UART_TRANSMITTED_DATA[TX_Cnt] == '.')
	{
		TX_Cnt = 0;
		TX_STATUS_FLAG = 0 ;
		CLR_BIT(UCSRB , 6);
	}
	
	if (TX_STATUS_FLAG == 1)
	{
		UDR = UART_TRANSMITTED_DATA[TX_Cnt];
		TX_STATUS_FLAG = 0 ;
	}
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
void UART_ReceiveData(void)
{
	static uint8 REC_COUNTER = 0 ;
	REC_DATA = UDR ;
	RECEIEVED_STATUS_FLAG = 1;
// 	REC_COUNTER++ ;
// 	if (UDR == '.')
// 	{
// 		REC_COUNTER = 0 ;
// 		RECEIEVED_STATUS_FLAG = 1;
// 	}
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

uint8 UART_ReceiveStatus(void)
{
	uint8 Rec_Statues_l = 0;
	
	if (RECEIEVED_STATUS_FLAG == 1)
	{
		Rec_Statues_l = 1;
		RECEIEVED_STATUS_FLAG = 0;
	}
	return Rec_Statues_l;
}
/**********************************************************************************************************************
 *  END OF FILE: UART_Core.c
 *********************************************************************************************************************/

