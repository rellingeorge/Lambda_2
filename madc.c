#include"adcall.h"//ADC PROGRAM:

uint16_t sixteen=0;
uint8_t eight=0;
void initADC()
{
    ADMUX=(1 << REFS0);
    ADCSRA |=(1 << ADEN)|(7 << ADPS0);

}
uint16_t ReadADC(uint8_t ch)
{
    ADMUX&=0xf8;
    ch=ch&0b00000111;
    ADMUX |=ch;
    ADCSRA|=(1 << ADSC);
    while(!(ADCSRA& (1 << ADIF)));
    ADCSRA |=(1 << ADIF);

    eight=ADCL;
    sixteen=(ADCH<<8)|(eight);
    return(sixteen);
}
