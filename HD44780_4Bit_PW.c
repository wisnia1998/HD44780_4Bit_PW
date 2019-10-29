#include "HD44780_4Bit_PW.h"



void LCD_Init()
{
	DDR_E  |= PIN_E;
	DDR_RS |= PIN_RS;
	DDR_D4 |= PIN_D4;
	DDR_D5 |= PIN_D5;
	DDR_D6 |= PIN_D6;
	DDR_D7 |= PIN_D7;
	_delay_ms(15);
	LCD_WriteCommand(LCD_COMMAND_FUNCTION_SET);
	_delay_ms(5);
	LCD_WriteCommand(LCD_COMMAND_FUNCTION_SET);
	_delay_ms(0.1);
	LCD_WriteCommand(LCD_COMMAND_FUNCTION_SET);
	_delay_ms(1);
	LCD_WriteCommand(LCD_COMMAND_FUNCTION_SET | LCD_PARAM_FUNCTION_SET_2LINES);
}

void LCD_Write(uint8_t data, uint8_t RS)
{
	if (RS){	RS_High;	}
	else {	 RS_Low;		}
	
	Enable_High;
	_delay_us(1);
	
	PORT_D4 &= ~PIN_D4;
	PORT_D5 &= ~PIN_D5;
	PORT_D6 &= ~PIN_D6;
	PORT_D7 &= ~PIN_D7;
	
	#ifdef Diferent_data_pin
	
	if (data & 0x01)
		PORT_D4 |= PIN_D4;
	if (data & 0x02)
		PORT_D5 |= PIN_D5;
	if (data & 0x04)
		PORT_D6 |= PIN_D6;
	if (data & 0x08)
		PORT_D7 |= PIN_D7;
	
	#else
	Data_Port |= data & Data_4bit_Mask;
	#endif
	_delay_us(1);
	Enable_Low;
	
}

void LCD_WriteData(uint8_t Data)
{
	LCD_Write(Data, 1);
	_delay_ms(1);
	LCD_Write(Data >> 4, 1);
}

void LCD_WriteCommand(uint8_t Command)
{
	LCD_Write(Command, 0);
	_delay_ms(1);
	LCD_Write(Command >> 4, 0);
}

