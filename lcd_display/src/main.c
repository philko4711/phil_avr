/*
 * main.c
 *
 *  Created on: Jun 14, 2014
 *      Author: phil
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "inits.h"
#include "lcd_command.h"
#include "lcd_characteristics.h"

int main(void)
{
	cli();
	port_init();
	lcd_init();
	sei();
	volatile uint8_t ctr = 0;
	PORTB |= (1 << PORTB5);

	lcd_data( 'I' );
	_delay_ms(1000);
	lcd_data( 'c' );
	_delay_ms(1000);
	lcd_data( 'h' );
	_delay_ms(1000);
	lcd_data( ' ' );
	_delay_ms(1000);
	lcd_data( 'l' );
	_delay_ms(1000);
	lcd_data( 'i' );
	_delay_ms(1000);
	lcd_data( 'e' );
	_delay_ms(1000);
	lcd_data( 'b' );
	_delay_ms(1000);
	lcd_data( 'e' );
	_delay_ms(1000);
	lcd_data( ' ' );
	_delay_ms(1000);
	lcd_data( 'H' );
	_delay_ms(1000);
	lcd_data( 'a' );
	_delay_ms(1000);
	lcd_data( 's' );
	_delay_ms(1000);
	lcd_data( 'e' );
	_delay_ms(1000);
	lcd_data( '!' );
	_delay_ms(1000);


	while(1)
	{
		if(PORTB)
			PORTB &= ~((1 << PORTB5));
		else
			PORTB |= (1 << PORTB5);
		ctr++;
		//PORTB = PORTB ^ PORTB;
		//lcd_string("Ich liebe Hasi!");
		_delay_ms(2000);
		//lcd_clear();
		//		lcd_command(LCD_CLEAR_DISPLAY);
		//		_delay_ms(LCD_CLEAR_DISPLAY_MS);

	}
}
