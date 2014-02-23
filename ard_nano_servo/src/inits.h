/*
 * port_init.h
 *
 *  Created on: 21.02.2014
 *      Author: Phil
 */

#ifndef PORT_INIT_H_
#define PORT_INIT_H_

#define TCNT0_PRESET 249
#define T_PER 208          //20 ms period

void init_timer0(void);
void port_init(void);

#endif /* PORT_INIT_H_ */
