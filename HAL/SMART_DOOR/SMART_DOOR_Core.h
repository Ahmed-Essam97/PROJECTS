/*
 * SMART_DOOR_Core.h
 *
 * Created: 10/11/2023 10:22:59 PM
 *  Author: ahmed
 */ 


#ifndef SMART_DOOR_CORE_H_
#define SMART_DOOR_CORE_H_


#define  F_CPU  16000000U
#include <util/delay.h>
#include "SERVO_MOTOR_Core.h"
#include "EEPROM_Core.h"
#include "LCD_Core.h"
#include "LED.h"
#include "BUZZER.h"
#include "UART_Core.h"

uint8* Smart_Door_Get_Pass(void);
void Smart_Door_Enter(uint8*);
void Smart_Door_Set(uint8*);
uint8 Chk_Pass(uint8* );
void Smart_Door_Close(void);

#endif /* SMART_DOOR_CORE_H_ */