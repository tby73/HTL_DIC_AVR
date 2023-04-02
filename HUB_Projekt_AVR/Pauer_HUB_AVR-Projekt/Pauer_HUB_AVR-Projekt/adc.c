/*
 * adc.c
 *
 * Created: 27.03.2023 17:22:52
 *  Author: olive
 */ 

#include "adc.h"

unsigned int read_adc(int channel)
{
	// MUX: 2.56 internal ref, CSR: Enable ADC, 1 : 64
	ADMUX |= (1 << REFS0) | (1 << REFS1) | channel;
	ADCSRA |= (1 << ADEN) | (1 << ADPS1) | (1 << ADPS2);
	
	// start measurement
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC));
	
	// return voltage in millivolts
	return (unsigned long)((ADC * 2.56 / 1024) * 1000); 
}

unsigned int avg(int n, int channel)
{
	int sum = 0; 
	
	for (int i = 0; i < n; i++)
	{
		sum += read_adc(channel); // sum measurements up 
	}
	
	// return arithmetic average
	return sum / n; 
}

