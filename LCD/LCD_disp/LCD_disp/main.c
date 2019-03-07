/*
 * LCD_disp.c
 *
 * Created: 07.03.2019 18:29:07
 * Author : Adas
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "HD44780.h"

int main(void)
{
    LCD_Initalize();
	LCD_Clear();
	while(1)
	{
	LCD_GoTo(2,0);
	LCD_WriteText("Klaudia jest");
	LCD_GoTo(3,1);
	LCD_WriteText("SUPER! B-)");
	_delay_ms(2000);
	}
}

