/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <SPI_Core.h>
 *       Module:  -
 * Created: 9/30/2023 6:18:13 PM
 *  Author: ahmed
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SPI_CORE_H_
#define SPI_CORE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD.h"
#include "MCU.h"
#include "BIT_Math.h"
#include "SPI_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define		SPI_INT_ENABLE		0U
#define		SPI_INT_DISABLE		1U

#define		SPI_SLAVE			0U
#define		SPI_MASTER			1U

#define		SPI_CLK_4			4U
#define		SPI_CLK_16			16U
#define		SPI_CLK_64			64U
#define		SPI_CLK_128			128U

#define		LEADING_EDGE		0U
#define		TRAILING_EDGE		1U

#define		ORDER_MSB		0U
#define		ORDER_LSB		1U

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
void SPI_Init(void);

uint8 SPI_TranSiver(uint8);
 
#endif /* SPI_CORE_H_ */

/**********************************************************************************************************************
 *  END OF FILE: SPI_Core.h
 *********************************************************************************************************************/
