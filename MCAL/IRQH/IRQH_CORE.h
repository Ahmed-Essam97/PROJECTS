/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <IRQH_CORE.h>
 *       Module:  1.0.0
 * Created: 8/23/2023 9:28:46 PM
 *  Author: Ahmed Essam
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef IRQH_CORE_H_
#define IRQH_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "MCU.h"
#include "BIT_Math.h"
#include "IRQH_CFG.h"
#include "STD.h"
#include "TIMER_CORE.h"
#include "ADC_Core.h"

#include <avr/interrupt.h>
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define INT_ENABLE	1
#define INT_DISABLE	0

#define EXT_INT_TRIGGER_FALLING_EDGE			0
#define EXT_INT_TRIGGER_RISING_EDGE				1
#define EXT_INT_TRIGGER_LOW_LEVEL				2
#define EXT_INT_TRIGGER_ANY_LOGICAL_CHANGE		3

#define  External_Interrupt_Request_0_VECTOR_INDEX      0U
#define  External_Interrupt_Request_1_VECTOR_INDEX      1U
#define  External_Interrupt_Request_2_VECTOR_INDEX		2U
#define  Timer_Counter2_Compare_Match_VECTOR_INDEX		3U
#define  Timer_Counter2_Overflow_VECTOR_INDEX			4U
#define  Timer_Counter1_Capture_Event_VECTOR_INDEX		5U
#define  Timer_Counter1_Compare_Match_A_VECTOR_INDEX	6U
#define  Timer_Counter1_Compare_Match_B_VECTOR_INDEX	7U
#define  Timer_Counter1_Overflow_VECTOR_INDEX			8U
#define  Timer_Counter0_Compare_Match_VECTOR_INDEX		9U
#define  Timer_Counter0_Overflow_VECTOR_INDEX			10U
#define  Serial_Transfer_Complete_VECTOR_INDEX			11U
#define  USART_Rx_Complete_VECTOR_INDEX					12U
#define  USART_Data_Register_Empty_VECTOR_INDEX			13U
#define  USART_Tx_Complete_VECTOR_INDEX					14U
#define  ADC_Conversion_Complete_VECTOR_INDEX			15U
#define  EE_RDY_EEPROM_Ready_VECTOR_INDEX				16U
#define  ANA_COMP_Analog_Comparator_VECTOR_INDEX		17U
#define  Two_wire_Serial_Interface_VECTOR_INDEX			18U
#define  Store_Program_Memory_Ready_VECTOR_INDEX		19U

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern uint8 ICU_Cnt;
extern uint32 Cap_1, Cap_2;

// extern uint32 ADC_Vin_Value ;
// extern uint32 Timer0_Number_OVRflows_g;
// extern uint32 Timer0_Init_Value_g;
// extern uint32 Timer1_Number_OVRflows_g;
// extern uint32 Timer1_Init_Value_g;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void IRQH_SetGloabINT(uint8);

void IRQH_SetExternalINT(void);

void IRQH_SetCallBack(uint8 Interrupt_Vector_Index , void(*p)(void));

#endif /* IRQH_CORE_H_ */

/**************************************************************************************************************
 *  END OF FILE: IRQH_CORE.h
********/
