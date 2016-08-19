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
#include <stdlib.h>

uint16_t read_adc(uint8_t channel);

int main(void)
{
	cli();
	port_init();
	lcd_init();
	init_adc();
	sei();
	volatile uint8_t ctr = 0;
	PORTB |= (1 << PORTB5);

	while(1)
	{
//		if(PORTB)
//			PORTB &= ~((1 << PORTB5));
//		else
//			PORTB |= (1 << PORTB5);
//		ctr++;
		//PORTB = PORTB ^ PORTB;
		uint16_t adc = read_adc(7);
		char buffer[33];
		itoa(adc, buffer, 10);
		lcd_string("adc = ");
		lcd_string(buffer);

		//lcd_clear();
		//		lcd_command(LCD_CLEAR_DISPLAY);
		//		_delay_ms(LCD_CLEAR_DISPLAY_MS);
		_delay_ms(100);
		lcd_clear();
	}
}

uint16_t read_adc(uint8_t channel)
{
	ADMUX &= 0xF0;                    //Clear the older channel that was read
	ADMUX |= channel;                //Defines the new ADC channel to be read
	ADCSRA |= (1<<ADSC);                //Starts a new conversion
	while(ADCSRA & (1<<ADSC));            //Wait until the conversion is done
	return ADCW;                    //Returns the ADC value of the chosen channel
}
