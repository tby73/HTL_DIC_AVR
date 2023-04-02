/*
 * io.c
 *
 * Created: 27.03.2023 17:12:36
 *  Author: olive
 */ 

#include "io.h"

// default MGC I/O settings
void init_io()
{
	DDRC = 0xff; 
	DDRA &= 0xf0; 
	PORTA |= 0x0f; 
	PORTC = 0; 
}

// set port pin
void port_set(char* port, int pin)
{
	*port |= (1 << pin);
}

// clear port pin
void port_clr(char* port, int pin)
{
	*port &= ~(1 << pin);
}

// check if button press
char is_bit_set(char input_port, int pin)
{
	return ~input_port & (1 << pin);
}

