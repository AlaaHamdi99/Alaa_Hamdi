/********************************************************/
/********************************************************/
/*****************  Author:Alaa Hamdi *******************/
/*****************  Layer:MCAL        *******************/
/*****************  SWC:ADC           *******************/
/*****************  Version:1         *******************/
/********************************************************/
/********************************************************/
#ifndef  ADC_REGISTER_H
#define  ADC_REGISTER_H

#define   ADMUX              *((volatile u8*) 0x27) // ADC multiplexer selection register
#define   ADMUX_MUX0         0
#define   ADMUX_MUX1         1
#define   ADMUX_MUX2         2
#define   ADMUX_MUX3         3
#define   ADMUX_MUX4         4
#define   ADMUX_ADLAR        5                      //ADC Left Adjust result
#define   ADMUX_REFS0        6                      //Reference voltage selection bit1
#define   ADMUX_REFS1        7                      //Reference voltage selection bit2

#define   ADCSRA             *((volatile u8*) 0x26) //ADC control and status register A
#define   ADCSRA_ADEN        7                      //ADC Enable
#define   ADCSRA_ADSC        6                      //Start conversion
#define   ADCSRA_ADATE       5                      //Auto trigger Enable
#define   ADCSRA_ADIF        4                      //Interrupt flag
#define   ADCSRA_ADIE        3                      //Interrupt enable
#define   ADCSRA_ADPS2       2                      //Pre_scaler bit2
#define   ADCSRA_ADPS1       1                      //Pre_scaler bit1
#define   ADCSRA_ADPS0       0                      //Pre_scaler bit0

#define   ADCH               *((volatile u8*) 0x25) //ADC high register
                      
#define   ADCL               *((volatile u8*) 0x24) //ADC low register

#define   SFIOR              *((volatile u8*) 0x50) //Special function I/O register
#define   SFIOR_ADTS2        7
#define   SFIOR_ADTS1        6
#define   SFIOR_ADTS0        5
                     
                             
#endif                       
