/*********************************************************/
/*********************************************************/
/*****************  Author:Alaa Hamid  *******************/
/*****************  Layer:MCAL         *******************/
/***************** SWC:GIE(PSW(I_bit)) *******************/
/*****************  Version:1          *******************/
/*********************************************************/
/*********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_register.h"
#include "GIE_interface.h"


void GIE_voidEnable(){
	/*Enable General interrupts*/
   SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(){
	/*Disable General interrupts*/
    CLR_BIT(SREG,SREG_I);
}
