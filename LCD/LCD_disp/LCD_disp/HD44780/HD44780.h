//-------------------------------------------------------------------------------------------------
// Alpha-numerical LCD HD44780 display with 4 bit control,
// without usage of 'busy' flag, with free assignment of control signals
// File : HD44780.h
// Microcontroller: Atmel AVR
// Compiler: avr-gcc
// Author : Radosław Kwiecień
// Source : http://radzio.dxp.pl/hd44780/
// Date : 24.03.2007
//-------------------------------------------------------------------------------------------------

#include <avr/io.h>
#include <util/delay.h>

//-------------------------------------------------------------------------------------------------
//
// Configuration of control signals
// Change it according to your needs
//
//-------------------------------------------------------------------------------------------------
#define LCD_RS_DIR		DDRD
#define LCD_RS_PORT 	PORTD
#define LCD_RS			(1 << PD2)

#define LCD_E_DIR		DDRD
#define LCD_E_PORT		PORTD
#define LCD_E			(1 << PD3)

#define LCD_DB4_DIR		DDRD
#define LCD_DB4_PORT	PORTD
#define LCD_DB4			(1 << PD4)

#define LCD_DB5_DIR		DDRD
#define LCD_DB5_PORT	PORTD
#define LCD_DB5			(1 << PD5)

#define LCD_DB6_DIR		DDRD
#define LCD_DB6_PORT	PORTD
#define LCD_DB6			(1 << PD6)

#define LCD_DB7_DIR		DDRD
#define LCD_DB7_PORT	PORTD
#define LCD_DB7			(1 << PD7)

//-------------------------------------------------------------------------------------------------
//
// Instructions of Hitachi HD44780 controller
//
//-------------------------------------------------------------------------------------------------

#define HD44780_CLEAR					0x01

#define HD44780_HOME					0x02

#define HD44780_ENTRY_MODE				0x04
	#define HD44780_EM_SHIFT_CURSOR		0
	#define HD44780_EM_SHIFT_DISPLAY	1
	#define HD44780_EM_DECREMENT		0
	#define HD44780_EM_INCREMENT		2

#define HD44780_DISPLAY_ONOFF			0x08
	#define HD44780_DISPLAY_OFF			0
	#define HD44780_DISPLAY_ON			4
	#define HD44780_CURSOR_OFF			0
	#define HD44780_CURSOR_ON			2
	#define HD44780_CURSOR_NOBLINK		0
	#define HD44780_CURSOR_BLINK		1

#define HD44780_DISPLAY_CURSOR_SHIFT	0x10
	#define HD44780_SHIFT_CURSOR		0
	#define HD44780_SHIFT_DISPLAY		8
	#define HD44780_SHIFT_LEFT			0
	#define HD44780_SHIFT_RIGHT			4

#define HD44780_FUNCTION_SET			0x20
	#define HD44780_FONT5x7				0
	#define HD44780_FONT5x10			4
	#define HD44780_ONE_LINE			0
	#define HD44780_TWO_LINE			8
	#define HD44780_4_BIT				0
	#define HD44780_8_BIT				16

#define HD44780_CGRAM_SET				0x40

#define HD44780_DDRAM_SET				0x80

//-------------------------------------------------------------------------------------------------
//
// Functions declarations
//
//-------------------------------------------------------------------------------------------------

void LCD_WriteCommand(unsigned char);
void LCD_WriteData(unsigned char);
void LCD_WriteText(char *);
void LCD_GoTo(unsigned char, unsigned char);
void LCD_Clear(void);
void LCD_Home(void);
void LCD_Initalize(void);

//-------------------------------------------------------------------------------------------------
//
// EOF HD44780.h
//
//-------------------------------------------------------------------------------------------------
