/*
 * io.h
 *
 * Created: 27.03.2023 17:12:46
 *  Author: olive
 */ 


#ifndef IO_H_
#define IO_H_

// IO Macros
#define BUTTON_PRESSED(x)	(~PINA & (1 << x))
#define SET_LED(x)			(PORTC |= (1 << x))
#define CLR_LED(x)			(PORTC &= ~(1 << x))

// Methods
extern void init_io(); 
extern void port_clr(char* port, int pin);
extern void port_set(char* port, int pin);
extern char is_bit_set(char input_port, int pin);

#endif /* IO_H_ */
