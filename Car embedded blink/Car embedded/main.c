/*
 * Car embedded.c
 *
 * Created: 17.02.2019 17:53:17
 * Author : Adas
 */ 

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
    DDRC = 0xFF; //Nakes PORTC as Output
    while(1) //infinite loop
    {
	    PORTC = 0xFF; //Turns ON All LEDs
	    _delay_ms(1000); //1 second delay
	    PORTC= 0x00; //Turns OFF All LEDs
	    _delay_ms(1000); //1 second delay
    }
}

