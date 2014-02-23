/*
 * uart.h
 *
 *  Created on: 23.02.2014
 *      Author: phil
 */

#ifndef UART_H_
#define UART_H_

#define BAUD 9600UL                             // baudrate

#define UBRR_VAL ((F_CPU+BAUD*8)/(BAUD*16)-1)   // round clever
#define BAUD_REAL (F_CPU/(16*(UBRR_VAL+1)))     // real baudrate
#define BAUD_ERROR ((BAUD_REAL*1000)/BAUD)      // error value in promille, 1000 = no error.
#if ((BAUD_ERROR<990) || (BAUD_ERROR>1010))
#error ERROR! Baudrate error > 1%! Take a look on UART init with its defines!
#endif

#include <inttypes.h>

void init_uart(uint16_t ubrr);
void send_char(uint8_t c);
void send_string(uint8_t* string);
void send_number(uint8_t number);


#endif /* UART_H_ */
