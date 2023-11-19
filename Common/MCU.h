/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <MCU.h>
 *       Module:  1.0
 *		Created on: Jul 3, 2020
 *      Author: Ali
 *  Description:  <GPIO of Micro Controller>     
 *  
 *********************************************************************************************************************/

#ifndef MCU_H_
#define MCU_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*************************************** GPIO Registers ************************************************/
#define PHYSICAL_GPIO_ACCESS(addr)      (*(volatile uint8*)(addr))
#define GPIOA_BASE_ADDRRESS             (0X39)
#define GPIOB_BASE_ADDRRESS             (0X36)
#define GPIOC_BASE_ADDRRESS             (0X33)
#define GPIOD_BASE_ADDRRESS             (0X30)

#define GPIO_INPUT_REGISTER_PIN         (0X00)
#define GPIO_DIRCETION_REGISTER_DDR     (0X01)
#define GPIO_OUTPUT_REGISTER_PORT       (0X02)

#define F_CPU 16000000U

						/*INTERRUPTS*/
#define		SREG					(*(volatile uint8*)(0X5F))
#define		GICR					(*(volatile uint8*)(0X5B))
#define		MCUCR					(*(volatile uint8*)(0X55))
#define		MCUCSR					(*(volatile uint8*)(0X54))
							/*ADC*/
#define		ADMUX					(*(volatile uint8*)(0X27))
#define		ADCSRA					(*(volatile uint8*)(0X26))
#define		ADCH					(*(volatile uint8*)(0X25))
#define		ADCL					(*(volatile uint8*)(0X24))
#define		ADC_input_16bit_access	(*(volatile uint16*)(0X24))


						/*TIMER0*/
#define	SFIOR		(*(volatile uint8*)(0X50))
#define TCCR0       (*(volatile uint8*)(0X53))
#define TIFR		(*(volatile uint8*)(0X58))
#define TIMSK		(*(volatile uint8*)(0X59))
#define TCNT0		(*(volatile uint8*)(0X52))
#define OCR0		(*(volatile uint8*)(0X5C))


						/*TIMER1*/

#define TCCR1A				(*(volatile uint8*)(0X4F))
#define TCCR1B				(*(volatile uint8*)(0X4E))


#define TCNT1L				(*(volatile uint8*)(0X4C))
#define TCNT1H				(*(volatile uint8*)(0X4D))
#define TCNT1_16bit_access	(*(volatile uint16*)(0X4C))

#define OCR1AL				(*(volatile uint16*)(0X4A))
#define OCR1AH				(*(volatile uint8*)(0X4B))
#define OCR1_16bit_access	(*(volatile uint16*)(0X4A))

#define ICR1L				(*(volatile uint8*)(0X46))
#define ICR1H				(*(volatile uint8*)(0X47))
#define ICR1_16bit_access	(*(volatile uint16*)(0X46))

//UART
#define UCSRC				(*(volatile uint8*)(0X40))
#define UCSRB				(*(volatile uint8*)(0X2A))
#define UCSRA				(*(volatile uint8*)(0X2B))
#define UBRRL				(*(volatile uint8*)(0X29))
#define UDR					(*(volatile uint8*)(0X2C))

//SPI


typedef struct {
	
	unsigned char SPCR ;
	unsigned char SPSR ;
	unsigned char SPDR ;
	
}SPI_REGISTERS;

#define SPI		((volatile SPI_REGISTERS*)(0X2D))

// typedef struct {
// 	
// 	unsigned char TWBR ;
// 	unsigned char TWSR ;
// 	unsigned char TWAR ;
// 	unsigned char TWDR ;
// 	
// }I2C_REGISTERS;
// 
// #define I2C		((volatile SPI_REGISTERS*)(0X20))

// #define TWBR			(*(volatile uint8*)(0X20))
// #define TWSR			(*(volatile uint8*)(0X21))
// #define TWAR			(*(volatile uint8*)(0X22))
// #define TWDR			(*(volatile uint8*)(0X23))
// #define TWCR			(*(volatile uint8*)(0X56))

// #define SPCR		(*(volatile uint8*)(0X2D))
// #define SPSR		(*(volatile uint8*)(0X2E))
// #define SPDR		(*(volatile uint8*)(0X2F))
#define TWCR    (*((volatile uint8*)0x56))
#define TWDR    (*((volatile uint8*)0x23))
#define TWAR    (*((volatile uint8*)0x22))
#define TWBR    (*((volatile uint8*)0x20))
#define TWSR    (*((volatile uint8*)0x21))



//Watchdog time1
#define WDTCR		(*(volatile uint8*)(0X41))
/*******************************************************************************************************/

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

 
#endif /* MCU_H_ */

/**********************************************************************************************************************
 *  END OF FILE: MCU.h
 *********************************************************************************************************************/


