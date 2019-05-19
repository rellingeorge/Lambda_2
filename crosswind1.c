/*EMPLOYEE NAME:ROHANKUMAR GHOBADE
EMPLOYEE ID    : 140670*/

#include"adcall.h"
uint16_t cross_wind(uint16_t left_sensor, uint16_t right_sensor)
 {
     int n=512;
 if((right_sensor>=n)&&(left_sensor>=n))//if both sesor values are greater than set_value
                        {
                            PORTB|=(1<<PB7);   //right_side break should applied to right_side wheels
                            PORTB|=(1<<PB2);   //left_side break should applied to left_side wheels
                            _delay_ms(10);

                        }
                    else if(right_sensor>=n)   //if right_side sesor value is greater than set_value
                        {
                            PORTB|=(1<<PB7);   //right_side break should applied to right_side wheels
                            _delay_ms(10);
                            PORTB&=~(1<<PB2);  //not applied to left_side
                            _delay_ms(10);
                        }
                    else if(left_sensor>=n)   //if left_side sesor value is greater than set_value
                        {
                            PORTB&=~(1<<PB7);//not applied
                            PORTB|=(1<<PB2); //left_side break should applied to left_side wheels
                            _delay_ms(10);

                        }

                    else
                        {
                            PORTB&=~(1<<PB7);
                            PORTB&=~(1<<PB2);
                        }
 }
