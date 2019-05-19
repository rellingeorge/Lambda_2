/*EMPLOYEE NAME:RESHMA NADAF
EMPLOYEE ID    : 140668*/

#include"adcall.h"
uint16_t rain_sensor(uint16_t x)

{

TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);//for 10 bit adc_purpose
TCCR1B|=(1<<WGM12) |(1<<CS10 )|(1<<CS11);

TCNT1=0x00;
DDRB|=(1<<PB1);

{
    if((x>=100)&&(x<=500))
       {
            OCR1A=250;
            _delay_ms(30);
       }
    else if((x>500)&&(x<700))
       {
            OCR1A=512;
            _delay_ms(30);
       }
    else if(x>700)
       {
            OCR1A=750;
            _delay_ms(30);
       }
   else
       {
            OCR1A=0;
            _delay_ms(30);
       }
}
}
