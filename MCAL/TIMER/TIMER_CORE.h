/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <TIMER_CORE.h>
 *       Module:  -
 * Created: 9/15/2023 3:25:10 PM
 *  Author: ahmed
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
 #ifndef TIMER_CORE_H_
 #define TIMER_CORE_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD.h"
#include "MCU.h"
#include "BIT_MATH.h"
#include "TIMER_CFG.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define TIMER_ENABLE                 1U
#define TIMER_DISABLE                0U

#define NORMAL_MODE                  0U
#define CTC_MODE                     1U
// #define PWM_Phase_Frequency_Correct  2U
// #define PWM_Phase_Correct            3U
// #define Fast_PWM                     4U

#define NO_CLK_SRC                   0U
#define CLK_SRC_WITH_NO_PRESCALING	 1U
#define CLK_SRC_PRESCALING_8		 8U
#define CLK_SRC_PRESCALING_32 		 32U
#define CLK_SRC_PRESCALING_64 		 64U
#define CLK_SRC_PRESCALING_128 		 128U
#define CLK_SRC_PRESCALING_256 		 256U
#define CLK_SRC_PRESCALING_1024      1024U

#define INTERRUPT_ENABLED            1U
#define INTERRUPT_DISABLED           0U

// #define INVERTED_PWM				 0U
// #define NON_INVERTED_PWM			 1U

#define TIMER0_OVF_INTERRUPT_BIT     0U
#define TIMER0_OC_INTERRUPT_BIT      1U
#define TIMER1_OVF_INTERRUPT_BIT     2U
#define TIMER1_OC_INTERRUPT_BIT      4U
#define TIMER2_OVF_INTERRUPT_BIT     6U
#define TIMER2_OC_INTERRUPT_BIT      7U

#define TIMER0_COUNTING_REG_CAPACITY	256U
#define TIMER1_COUNTING_REG_CAPACITY	65535U
#define TIMER2_COUNTING_REG_CAPACITY	256U

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern uint32 Timer0_Number_OVRflows_g ;
extern uint32 Timer0_Init_Value_g ;
extern uint32 Timer1_Number_OVRflows_g ;
extern uint32 Timer1_Init_Value_g ;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 void GPT_Init(void);
 void GPT_SetTime(void);
 void PWM(uint8);

#endif /* TIMER_CORE_H_ */
/**********************************************************************************************************************
 *  END OF FILE: TIMER_CORE.h
 *********************************************************************************************************************/
