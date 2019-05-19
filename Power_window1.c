/*EMPLOYEE NAME:RELLIN GEORGE
EMPLOYEE ID    : 140667*/

#include"adcall.h"


volatile uint16_t flag3=0,c1=0,c2=0;
void power_window()
{

    DDRB&=~(1<<PB0);//
    DDRC&=~(1<<PC6);//

    DDRD=1;

    PORTB|=(1<<PB0);
    PORTC|=(1<<PC6);

    PCICR|=(1<<PCIE0);
    PCICR|=(1<<PCIE1);

    PCMSK0|=(1<<PCINT0);
    PCMSK1|=(1<<PCINT14);

    sei();

   if(!(PINB&1))
    {


            clock_wise(1);
            PORTD=0X00;
         _delay_ms(50);
    }
    else
    {


        anti_clock(1);

       PORTD=0X00;
         _delay_ms(50);
        //_delay_ms(30);
    }
}


void clock_wise(int r)
{
   // int r;
    for(r;r<=20;r++)
   // while(i)
    {
            PORTD=0X90;
            _delay_ms(10);
            PORTD=0X80;
            _delay_ms(10);
            PORTD=0XC0;
            _delay_ms(10);
            PORTD=0X40;
            _delay_ms(10);
            PORTD=0X60;
            _delay_ms(10);
            PORTD=0X20;
            _delay_ms(10);
            PORTD=0X30;
            _delay_ms(10);
            PORTD=0X10;
            _delay_ms(10);
           // --i;
     }

//while(r);
}


void anti_clock(int r1)
{
    //int r;
for(r1;r1<=20;r1++)
    //while(j)
    {
        if(flag3==1)
            {
                clock_wise(5);
                PORTD=0X00;
                _delay_ms(50);
            }
        else
            {
                PORTD=0X10;
                _delay_ms(10);
                PORTD=0X30;
                _delay_ms(10);
                PORTD=0X20;
                _delay_ms(10);
                PORTD=0X60;
                _delay_ms(10);
                PORTD=0X40;
                _delay_ms(10);
                PORTD=0XC0;
                _delay_ms(10);
                PORTD=0X80;
                _delay_ms(10);
                PORTD=0X90;
                _delay_ms(10);
            }

              //  --j;


    }
//while(r);
}



ISR(PCINT1_vect)
{
	 flag3=1;
}






