/********************************************************/
/********************************************************/
/*****************  Author:Alaa Hamdi *******************/
/*****************  Layer:MCAL        *******************/
/*****************  SWC:TIMER         *******************/
/*****************  Version:1         *******************/
/********************************************************/
/********************************************************/
#ifndef   TIMER_INTERFACE_H
#define   TIMER_INTERFACE_H

void  TIMER0_voidInit();

u8    TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));







#endif