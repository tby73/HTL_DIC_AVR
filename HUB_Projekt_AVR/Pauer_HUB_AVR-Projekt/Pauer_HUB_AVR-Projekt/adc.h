/*
 * adc.h
 *
 * Created: 27.03.2023 17:22:42
 *  Author: olive
 */ 


#ifndef ADC_H_
#define ADC_H_

extern unsigned int read_adc(int channel);
extern unsigned int avg(int n, int channel);

#endif /* ADC_H_ */
