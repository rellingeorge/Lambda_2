#include"adcall.h" //PWD header file

volatile uint16_t left_sensor=0,right_sensor=0,speed_sensor=0,flag1=0,flag2=0,rain_sensor_value=0;//variable initialisation

 int main()
{

            DDRB|=(1<<PB1);//Pin B1 given as pwm  output
            DDRB|=(1<<PB7); //pin B7 used as output(right_side LED indication)
            DDRB|=(1<<PB2);//pin B2 used as output(left_side LED indication)

            DDRD&=~(1<<PD2);//pin D2 used as input (driver is present/not)
            DDRD&=~(1<<PD3);//pin D3 used as input(seat_belt indication)

            PORTD|=(1<<PD2);//making D2 pin with high voltage(5v)/1
            PORTD|=(1<<PD3);//making D3 pin with high voltage(5v)/1

            EICRA|=(1<<ISC00);//for any logic changes in INT0 jump to isr
            EICRA|=(1<<ISC10);//for any logic changes in INT1  jump to

            EIMSK|=(1<<INT0);// selecting interrupt 0(INT0)(for engine on/off)
            EIMSK|=(1<<INT1);//selecting interrupt 1(INT1(seat_belt_monitoring)

            sei();
            SREG |=(1<<7);         //global interrupt register

            DDRC&=~(1<<PC0); //pin C0 used as input of left_sensor used to read wind pressure
            DDRC&=~(1<<PC1);//pin C1 used as input of right_sensor used to read wind pressure
            DDRC&=~(1<<PC3); //rain sensor reading

            DDRB|=(1<<PB3);//output unsafe speed
            DDRB|=(1<<PB4);//output safe speed
            DDRC&=~(1<<PC2);//adc read1 for speed  monitor

            initADC();        //ADC initialization






            while(1)         //for continuous monitoring purpose

            {


                if((flag1==1)&&(flag2==1)) //checking both conditions engine on/offn and seat_belt fasten/not (true)

                {



                 rain_sensor_value=ReadADC(3);//reading rain_sensor value
                     _delay_ms(50);              //delay
                    rain_sensor(rain_sensor_value);//according to rain_sensor value action should be taken
                    _delay_ms(50);


                    speed_sensor=ReadADC(2);//reading speed from wheels
                    _delay_ms(50);
                    speed_sensor_value(speed_sensor);//according to speed LED indication made

                    left_sensor=ReadADC(0);//read ADC_value from left side and put into left_sensor
                    _delay_ms(50);        //delay purpose

                    right_sensor=ReadADC(1);//read ADC value from right side and put into right_sensor
                    _delay_ms(50);

                    cross_wind(left_sensor,right_sensor);//according to left and right sensor LED indication will operate
                    _delay_ms(50);

                   power_window();//either open/close the window

                }
                else                //if codition fales
                {
                    PORTB&=~(1<<PB7);//off the right_LED_indication
                    PORTB&=~(1<<PB2);//off the left_LED_indication

                    PORTB&=~(1<<PB3);//safe indication off
                    PORTB&=~(1<<PB4);//unsafe indication off

                    PORTB&=~(1<<PB1);//pwm is zero


            }


            }

            return 0;
}


ISR(INT0_vect)
{
    flag1=1;//this flag indicates engine is on

}

ISR(INT1_vect)
{
    flag2=1;//this flag indicates seat_belt fastened
}






























