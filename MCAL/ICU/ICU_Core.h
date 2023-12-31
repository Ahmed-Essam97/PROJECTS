/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <ICU_Core.h>
 *       Module:  -
 * Created: 9/23/2023 4:55:08 PM
 *  Author: ahmed
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef ICU_CORE_H_
#define ICU_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "MCU.h"
#include "STD.h"
#include "TIMER_CORE.h"
#include "IRQH_CORE.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


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
void ICU_Init(void);
uint32 ICU_Capture_Time(void);
 
#endif /* ICU_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: ICU_Core.h
 *********************************************************************************************************************/
