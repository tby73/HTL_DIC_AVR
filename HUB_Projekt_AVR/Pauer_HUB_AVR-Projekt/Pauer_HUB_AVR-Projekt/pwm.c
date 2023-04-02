/*
 * pwm.c
 *
 * Created: 27.03.2023 17:33:38
 *  Author: olive
 */ 

#include "pwm.h"

void set_pwm_0(int duty)
{
	// Prescaler = 1 : 64, FPWM, Compare Match
	TCCR0 |= (1 << CS00) | (1 << CS01);
	TCCR0 |= (1 << WGM00) | (1 << WGM01);
	TCCR0 |= (1 << COM01);
	
	// enable PWM_OUT (OC0 => PB3)
	DDRB |= (1 << PB3);
	
	// set value
	OCR0 = duty; 
}

