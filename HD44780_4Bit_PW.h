/*
 *HD44780_4Bit_PW.h
 *Title: HD44780 library for 4-Bit control
 *Author: Pawe³ Waœniowski
 *Created: 23.10.2019
*/

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <util/delay.h>
#include <avr/io.h>

#define Data_4bit_Mask 0x0f
//////////////////Pin control declaration/////////////////////////////////
//#define Different_data_pin
#define PIN_RS	(1 << PORTB1)
#define PORT_RS	PORTB
#define DDR_RS	DDRB
#define PIN_E	(1 << PORTB0)
#define PORT_E	PORTB
#define DDR_E	DDRB
//#define PIN_RW	(1 << PORTB3)
//#define PORT_RW	PORTB
//#define DDR_RW	DDRB
//Control pin
#ifdef Different_data_pin
#define PIN_D4	(1 << PORTD0)
#define PORT_D4	PORTD
#define DDR_D4	DDRD
#define PIN_D5	(1 << PORTD1)
#define PORT_D5	PORTD
#define DDR_D5	DDRD
#define PIN_D6	(1 << PORTD2)
#define PORT_D6	PORTD
#define DDR_D6	DDRD
#define PIN_D7	(1 << PORTD3)
#define PORT_D7	PORTD
#define DDR_D7	DDRD
#else
#define Data_Port PORTD
#define Data_Direct DDRD
#define PIN_D4	(1 << PORTD4)
#define PIN_D5	(1 << PORTD5)
#define PIN_D6	(1 << PORTD6)
#define PIN_D7	(1 << PORTD7)
#endif
//////////////////////////////////////////////////////////////////////////

///////////////////////////MAKRO//////////////////////////////////////////
#define Enable_High		PORT_E |= PIN_E
#define Enable_Low		PORT_E &= ~PIN_E
#define RS_High		PORT_RS |= PIN_RS
#define RS_Low		PORT_RS &= ~PIN_RS
//////////////////////////////////////////////////////////////////////////

/////////////////////////LCD COMMAND//////////////////////////////////////
#define LCD_COMMAND_CLEAR_SCREEN 0x01
#define LCD_COMMAND_RETURN_HOME 0x02
#define LCD_COMMAND_ENTRY_MODE_SET 0x04
#define LCD_COMMAND_ON_OFF 0x08
#define LCD_COMMAND_SHIFT 0x10
#define LCD_COMMAND_FUNCTION_SET 0x20
#define LCD_COMMAND_SET_CGRAM_ADDRESS 0x40
#define LCD_COMMAND_SET_DDRAM_ADDRESS 0x80
/********************************************************/
#define LCD_PARAM_ENTRY_MODE_SET_SHIFT 0x01
#define LCD_PARAM_ENTRY_MODE_SET_INCREMENT 0x02
#define LCD_PARAM_ON_OFF_BLINK 0x01
#define LCD_PARAM_ON_OFF_CURSOR 0x02
#define LCD_PARAM_ON_OFF_DISPLAY 0x04
#define LCD_PARAM_SHIFT_RIGHT 0x04
#define LCD_PARAM_SHIFT_DISPLAY 0x08
#define LCD_PARAM_FUNCTION_SET_5X10 0x04
#define LCD_PARAM_FUNCTION_SET_2LINES 0x08
#define LCD_PARAM_FUNCTION_SET_8BIT 0x10
//////////////////////////////////////////////////////////////////////////

///////////////////////////////Function///////////////////////////////////
void LCD_Init();
void LCD_Write(uint8_t data, uint8_t RS);
void LCD_WriteData(uint8_t Data);
void LCD_WriteCommand(uint8_t Command);
void LCD_Clear(void);
void LCD_Set_Cursor(uint8_t Command);
void LCD_Blink_Cursor_ON(void);
void LCD_Blink_Cursor_OFF(void);
void LCD_Cursor_ON(void);
void LCD_Cursor_OFF(void);
void LCD_BlackLight_ON(void);
void LCD_BlackLight_OFF(void);
void LCD_Adjust(uint8_t Data, uint8_t site);
//////////////////////////////////////////////////////////////////////////