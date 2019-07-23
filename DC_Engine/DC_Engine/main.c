/*
 * DC_Engine.c
 *
 * Created: 02.04.2019 19:59:45
 * Author : Adas
 */ 

#include <avr/io.h>
//#include <stdint.h>
#include <util/delay.h>
#include "HD44780.h"
#include <stdlib.h>
int main(void)
{
	LCD_Initalize();
	char buffer[8];
	//PD4, PD5 PWM
	DDRD |= ((1<<PD6) | (1<<PD5));
	PORTD |= ((1<<PD6) | (1<<PD5));

	TCCR1A = (1<<WGM10) | (1<<COM1A1) | (1<<COM1B1) | (1<<COM1A0) | (1<<COM1B0);
	TCCR1B = (1<<WGM12) | (1<CS12) | (1<CS10);
    
	OCR1A = 200;
	OCR1B = 12000;
	/* Replace with your application code */
 while(1)
 {
	LCD_Clear();
	LCD_GoTo(0,0);
//	LCD_WriteText("ADAS3");
	LCD_WriteText(itoa(TCNT1,buffer,16));
	LCD_GoTo(0,1);
	LCD_WriteText(itoa(OCR1B,buffer,16));
	_delay_ms(50);
 } 
}

