/*
 * 
 *
 * Created: 10/27/2023 3:48:23 PM
 *  Author: ahmed
 */ 
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Scheduler_Core.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Scheduler_Core.h"

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
void Scheduler_TaskCreate(void(*Ptr)(void) ,uint32 Priodicity,uint8 Priority,uint8 ID)
{
	static uint8 Task_number = 0;
	
	System_Tasks[Task_number].Task_Ptr = Ptr;
	System_Tasks[Task_number].Task_Priodicity = Priodicity;
	System_Tasks[Task_number].Task_Priority = Priority;
	System_Tasks[Task_number].Task_Status = Ready;
	System_Tasks[Task_number].Task_ID = ID;
	
	Task_number++;
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

void Scheduler_TaskSuspend(uint8 ID)
{
	uint8 Task_cnt = 0;
	for (Task_cnt = 0 ; Task_cnt < Tasks_Num ; Task_cnt++)
	{
		if (System_Tasks[Task_cnt].Task_ID == ID)
		{
			System_Tasks[Task_cnt].Task_Status = Suspended;
		}
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

void Scheduler_CallBack(void)
{
	uint8 Task_cnt = 0;
	static uint32 System_Tick = 0;
	System_Tick++;
	
	for (Task_cnt = 0;Task_cnt<Tasks_Num;Task_cnt++)
	{
		if (System_Tasks[Task_cnt].Task_Status==waiting)
		{
			if (System_Tick % System_Tasks[Task_cnt].Task_Priodicity == 0)
			{
				System_Tasks[Task_cnt].Task_Status = Ready;
			}
		}
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

void Scheduler_Run(void)
{
	uint8 Task_number = 0;
	GPT_Init();
	IRQH_SetCallBack(Timer_Counter0_Overflow_VECTOR_INDEX,Scheduler_CallBack);
	GPT_SetTime();
	while (1)
	{
		for  (Task_number = 0;Task_number<Tasks_Num;Task_number++)
		{
			if (System_Tasks[Task_number].Task_Status==Ready)
			{
				//priority
				System_Tasks[Task_number].Task_Status = waiting;
				System_Tasks[Task_number].Task_Ptr();
			}
		}
	}
}	
/**********************************************************************************************************************
 *  END OF FILE: Scheduler_Core.c
 *********************************************************************************************************************/

