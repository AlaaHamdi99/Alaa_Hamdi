/********************************************************/
/********************************************************/
/*****************  Author:Alaa Hamdi *******************/
/*****************  Layer:MCAL        *******************/
/*****************  SWC:TIMER_1       *******************/
/*****************  Version:1         *******************/
/********************************************************/
/********************************************************/
#ifndef   TIMER1_REGISTER_H
#define   TIMER1_REGISTER_H

#define   TCCR1A       *((volatile u8*)0x4F)

#define   TCCR1B       *((volatile u8*)0x4E)

#define   OCR1AH       *((volatile u8*)0x4B) 
#define   OCR1AL       *((volatile u8*)0x4A)
#define   OCR1AH       *((volatile u8*)0x49)
#define   OCR1AL       *((volatile u8*)0x48)
#define   ICR1H        *((volatile u8*)0x47)
#define   ICR1L        *((volatile u8*)0x46)
#endif