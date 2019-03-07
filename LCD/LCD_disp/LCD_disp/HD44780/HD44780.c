//-------------------------------------------------------------------------------------------------
// Alpha-numerical LCD HD44780 display with 4 bit control,
// without usage of 'busy' flag, with free assignment of control signals
// File : HD44780.c
// Microcontroller: Atmel AVR
// Compiler: avr-gcc
// Author : Radosław Kwiecień
// Source : http://radzio.dxp.pl/hd44780/
// Date : 24.03.2007
//-------------------------------------------------------------------------------------------------

#include "HD44780.h"
//-------------------------------------------------------------------------------------------------
//
// Functions setting nibble onto the data bus
//
//-------------------------------------------------------------------------------------------------
void _LCD_OutNibble(unsigned char nibbleToWrite)
{
if(nibbleToWrite & 0x01)
	LCD_DB4_PORT |= LCD_DB4;
else
	LCD_DB4_PORT  &= ~LCD_DB4;

if(nibbleToWrite & 0x02)
	LCD_DB5_PORT |= LCD_DB5;
else
	LCD_DB5_PORT  &= ~LCD_DB5;

if(nibbleToWrite & 0x04)
	LCD_DB6_PORT |= LCD_DB6;
else
	LCD_DB6_PORT  &= ~LCD_DB6;

if(nibbleToWrite & 0x08)
	LCD_DB7_PORT |= LCD_DB7;
else
	LCD_DB7_PORT  &= ~LCD_DB7;
}
//-------------------------------------------------------------------------------------------------
//
// Function to write byte to display (no difference between data/control)
//
//-------------------------------------------------------------------------------------------------
void _LCD_Write(unsigned char dataToWrite)
{
LCD_E_PORT |= LCD_E;
_LCD_OutNibble(dataToWrite >> 4);
LCD_E_PORT &= ~LCD_E;
LCD_E_PORT |= LCD_E;
_LCD_OutNibble(dataToWrite);
LCD_E_PORT &= ~LCD_E;
_delay_us(50);
}
//-------------------------------------------------------------------------------------------------
//
// Writes control command to the display
//
//-------------------------------------------------------------------------------------------------
void LCD_WriteCommand(unsigned char commandToWrite)
{
LCD_RS_PORT &= ~LCD_RS;
_LCD_Write(commandToWrite);
}
//-------------------------------------------------------------------------------------------------
//
// Writes data to display
//
//-------------------------------------------------------------------------------------------------
void LCD_WriteData(unsigned char dataToWrite)
{
LCD_RS_PORT |= LCD_RS;
_LCD_Write(dataToWrite);
}
//-------------------------------------------------------------------------------------------------
//
// Writes text onto the display
//
//-------------------------------------------------------------------------------------------------
void LCD_WriteText(char * text)
{
while(*text)
  LCD_WriteData(*text++);
}
//-------------------------------------------------------------------------------------------------
//
// Sets the screen location to start write
//
//-------------------------------------------------------------------------------------------------
void LCD_GoTo(unsigned char x, unsigned char y)
{
LCD_WriteCommand(HD44780_DDRAM_SET | (x + (0x40 * y)));
}
//-------------------------------------------------------------------------------------------------
//
// Clears the screen
//
//-------------------------------------------------------------------------------------------------
void LCD_Clear(void)
{
LCD_WriteCommand(HD44780_CLEAR);
_delay_ms(2);
}
//-------------------------------------------------------------------------------------------------
//
// Returns cursor to the home position
//
//-------------------------------------------------------------------------------------------------
void LCD_Home(void)
{
LCD_WriteCommand(HD44780_HOME);
_delay_ms(2);
}
//-------------------------------------------------------------------------------------------------
//
// HD44870 initialization
//
//-------------------------------------------------------------------------------------------------
void LCD_Initalize(void)
{
unsigned char i;
LCD_DB4_DIR |= LCD_DB4; // Configuration of pins
LCD_DB5_DIR |= LCD_DB5; //
LCD_DB6_DIR |= LCD_DB6; //
LCD_DB7_DIR |= LCD_DB7; //
LCD_E_DIR 	|= LCD_E;   //
LCD_RS_DIR 	|= LCD_RS;  //
_delay_ms(15); // wait for power to stabilize
LCD_RS_PORT &= ~LCD_RS; // clear line RS
LCD_E_PORT &= ~LCD_E;  // clear line E

for(i = 0; i < 3; i++) // three times sending the commands block
  {
  LCD_E_PORT |= LCD_E; //  E = 1
  _LCD_OutNibble(0x03); // 8 bit mode
  LCD_E_PORT &= ~LCD_E; // E = 0
  _delay_ms(5); // wait 5ms
  }

LCD_E_PORT |= LCD_E; // E = 1
_LCD_OutNibble(0x02); // 4-bit mode
LCD_E_PORT &= ~LCD_E; // E = 0

_delay_ms(1); // wait 1ms 
LCD_WriteCommand(HD44780_FUNCTION_SET | HD44780_FONT5x7 | HD44780_TWO_LINE | HD44780_4_BIT); // Set up: 4-bits, 2-display lines, character 5x7
LCD_WriteCommand(HD44780_DISPLAY_ONOFF | HD44780_DISPLAY_OFF); // turn on display
LCD_WriteCommand(HD44780_CLEAR); // clear DDRAM memory
_delay_ms(2);
LCD_WriteCommand(HD44780_ENTRY_MODE | HD44780_EM_SHIFT_CURSOR | HD44780_EM_INCREMENT);// set the address incrementation and cursor shift mode
LCD_WriteCommand(HD44780_DISPLAY_ONOFF | HD44780_DISPLAY_ON | HD44780_CURSOR_OFF | HD44780_CURSOR_NOBLINK); // turn on LCD, no cursor display nor blinking
}

//-------------------------------------------------------------------------------------------------
//
// EOF HD44780.c
//
//-------------------------------------------------------------------------------------------------
