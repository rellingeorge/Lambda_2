#ifndef ADC_H_INCLUDED
#define ADC_H_INCLUDED

#include <avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
void initADC(void);
uint16_t ReadADC(uint8_t );

uint16_t speed_sensor_value(uint16_t);
uint16_t cross_wind(uint16_t,uint16_t);

uint16_t rain_sensor(uint16_t);

void power_window(void);

void clock_wise(int);
void anti_clock(int);

#endif // ADC_H_INCLUDED
