/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <TIMER_CFG.h>
 *       Module:  -
 * Created: 9/15/2023 4:58:11 PM
 *  Author: ahmed
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Timer0_State TIMER_DISABLE
#define Timer1_State TIMER_ENABLE
#define Timer2_State TIMER_DISABLE

#define TIMER0_MODE NORMAL_MODE
#define TIMER1_MODE NORMAL_MODE
#define TIMER2_MODE NORMAL_MODE

#define TIMER0_PRESCALER CLK_SRC_PRESCALING_1024
#define TIMER1_PRESCALER CLK_SRC_PRESCALING_1024
#define TIMER2_PRESCALER CLK_SRC_PRESCALING_8

#define TIMER0_INTERRUPT_STATE INTERRUPT_ENABLED
#define TIMER1_INTERRUPT_STATE INTERRUPT_ENABLED
#define TIMER2_INTERRUPT_STATE INTERRUPT_ENABLED


#define TIMER0_COUNTED_MS	1000U
#define TIMER1_COUNTED_MS	1000U
#define TIMER2_COUNTED_MS	500U

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif /* TIMER_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: TIMER_CFG.h
 *********************************************************************************************************************/