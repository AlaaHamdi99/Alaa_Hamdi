/********************************************************/
/********************************************************/
/*****************  Author:Alaa Hamdi *******************/
/*****************  Layer:MCAL        *******************/
/*****************  SWC:DAC           *******************/
/*****************  Version:1         *******************/
/********************************************************/
/********************************************************/
#ifndef   TIMER_REGISTER_H
#define   TIMER_REGISTER_H

#define   TCCR0          *((volatile u8*)0x53)     /*Timer0 control register*/
#define   TCCR0_FOC0     7                         /**/
#define   TCCR0_WGM00    6                         /*Waveform generation mode bit0*/
#define   TCCR0_COM01    5                        
#define   TCCR0_COM00    4                        
#define   TCCR0_WGM01    3                         /*Waveform generation mode bit1*/
#define   TCCR0_CS02     2                         /*Prescaler bit2*/
#define   TCCR0_CS01     1                         /*Prescaler bit1*/
#define   TCCR0_CS00     0                         /*Prescaler bit0*/

#define   OCR0           *((volatile u8*) 0x5C)    /*Output compare register 0*/
#define   TIMISK         *((volatile u8*) 0x59)    /*Timer  mask*/
#define   TIMISK_OCIE0   1                         /*Output compare 0 interrupt enable*/
               
#endif