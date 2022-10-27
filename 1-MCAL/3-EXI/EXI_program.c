/********************************************************/
/********************************************************/
/*****************  Author:Alaa Hamid *******************/
/*****************  Layer:MCAL        *******************/
/*****************  SWC:EXI          *******************/
/*****************  Version:1         *******************/
/********************************************************/
/********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXI_interface.h"
#include "EXI_register.h"
#include "EXI_config.h"
#include "EXI_private.h"

void (*EXI_pvInt0Func)(void)=NULL;
void (*EXI_pvInt1Func)(void)=NULL;
void (*EXI_pvInt2Func)(void)=NULL;

void EXI_voidInt0Init(){
	/*Set sense control for INT0 to falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
	/*Peripheral interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);

}
void EXI_voidInt1Init(){
	/*Set sense control for INT0 to falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
	/*Peripheral interrupt enable for INT0*/
    SET_BIT(GICR,GICR_INT1);
	
}
void EXI_voidInt2Init(){
	/*Set sense control for INT0 to falling edge*/
	CLR_BIT(MCUCSR,MCUCSR_ISC2);
	/*Peripheral interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT2);
}
/*Pre_build Configuration functions */
void EXI_voidInt0PreInit(){
	/*Set the sense control*/
#if INT0_SENSE_CONTROL==LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_SENSE_CONTROL==ON_CHANGE
	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_SENSE_CONTROL==FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_SENSE_CONTROL==RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#else
#error "Wrong sense control"

#endif

#if  INT0_INITIAL_STATE==ENABLED
	/*Peripheral interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);
#elif INT0_INITIAL_STATE==DISABLED
	/*Peripheral interrupt enable for INT0*/
	CLR_BIT(GICR,GICR_INT0);
#else
#error  "Wrong INITIAL_STATE"
#endif
}
void EXI_voidInt1PreInit(){
	/*Set the sense control*/
#if INT1_SENSE_CONTROL==LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE_CONTROL==ON_CHANGE
	CLR_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE_CONTROL==FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT1_SENSE_CONTROL==RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	SET_BIT(MCUCR,MCUCR_ISC11);
#else
#error "Wrong sense control"

#endif
#if  INT1_INITIAL_STATE==ENABLED
	/*Peripheral interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT1);
#elif INT1_INITIAL_STATE==DISABLED
	/*Peripheral interrupt enable for INT0*/
	CLR_BIT(GICR,GICR_INT1);
#else
#error  "Wrong INITIAL_STATE"
#endif
}
void EXI_voidInt2PreInit(){
	/*Set the sense control*/
#if INT2_SENSE_CONTROL==FALLING_EDGE
	CLR_BIT(MCUCSR,MCUCSR_ISC2)
#elif INT2_SENSE_CONTROL==RISING_EDGE
	SET_BIT(MCUCSR,MCUCSR_ISC2);
#else
#error "Wrong sense control"
#endif

#if  INT2_INITIAL_STATE==ENABLED
	/*Peripheral interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);
#elif INT2_INITIAL_STATE==DISABLED
	/*Peripheral interrupt enable for INT0*/
	CLR_BIT(GICR,GICR_INT2);
#else
#error  "Wrong INITIAL_STATE"
#endif
}
/*Post build configuration every thing is alone
  every thing can be changed during the run time  */
/*Options:
  1-LOW_LEVEL
  2-ON_CHANGE
  3-FALLING_EDGE
  4-RISING_EDGE*/
u8 EXI_u8Int0SenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Sense){
	case LOW_LEVEL:CLR_BIT(MCUCR,MCUCR_ISC01);CLR_BIT(MCUCR,MCUCR_ISC00);break;
	case ON_CHANGE:CLR_BIT(MCUCR,MCUCR_ISC01);SET_BIT(MCUCR,MCUCR_ISC00);break;
	case FALLING_EDGE:SET_BIT(MCUCR,MCUCR_ISC01);CLR_BIT(MCUCR,MCUCR_ISC00);break;
	case RISING_EDGE:SET_BIT(MCUCR,MCUCR_ISC01);SET_BIT(MCUCR,MCUCR_ISC00);break;
	default: Local_u8ErrorState=NOK;break;
	}
	return Local_u8ErrorState;
}
u8 EXI_u8Int1SenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Sense){
		case LOW_LEVEL:CLR_BIT(MCUCR,MCUCR_ISC11);CLR_BIT(MCUCR,MCUCR_ISC10);break;
		case ON_CHANGE:CLR_BIT(MCUCR,MCUCR_ISC11);SET_BIT(MCUCR,MCUCR_ISC10);break;
		case FALLING_EDGE:SET_BIT(MCUCR,MCUCR_ISC11);CLR_BIT(MCUCR,MCUCR_ISC10);break;
		case RISING_EDGE:SET_BIT(MCUCR,MCUCR_ISC11);SET_BIT(MCUCR,MCUCR_ISC10);break;
		default: Local_u8ErrorState=NOK;break;
		}
	return Local_u8ErrorState;
}
u8 EXI_u8Int2SenseControl(u8 Copy_u8Sense){
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Sense){
		case FALLING_EDGE:CLR_BIT(MCUCSR,MCUCSR_ISC2);break;
		case RISING_EDGE:SET_BIT(MCUCSR,MCUCSR_ISC2);break;
		default: Local_u8ErrorState=NOK;break;
		}
	return Local_u8ErrorState;
}
/*Options:
 EXI_INT0
EXI_INT1
EXI_INT2   */
u8 EXI_u8IntEnable(u8 Copy_u8Int){
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Int){
	case EXI_INT0:	SET_BIT(GICR,GICR_INT0);break;
	case EXI_INT1:	SET_BIT(GICR,GICR_INT1);break;
	case EXI_INT2:	SET_BIT(GICR,GICR_INT2);break;
	default:Local_u8ErrorState=NOK;break;
	}
	return Local_u8ErrorState;
}
u8 EXI_u8IntDisable(u8 Copy_u8Int){
	u8 Local_u8ErrorState=OK;
	switch(Copy_u8Int){
		case EXI_INT0:	CLR_BIT(GICR,GICR_INT0);break;
		case EXI_INT1:	CLR_BIT(GICR,GICR_INT1);break;
		case EXI_INT2:	CLR_BIT(GICR,GICR_INT2);break;
		default:Local_u8ErrorState=NOK;break;
		}
	return Local_u8ErrorState;
}
u8 EXI_SendInt0ISR(void (*Copy_pvInt0Func)(void)){
	u8 Local_u8ErrorState=OK;
	if(Copy_pvInt0Func!=NULL){
	EXI_pvInt0Func=Copy_pvInt0Func;
	}
	else{
	 Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
u8 EXI_SendInt1ISR(void (*Copy_pvInt1Func)(void)){
	u8 Local_u8ErrorState=OK;
	if(Copy_pvInt1Func!=NULL){
	EXI_pvInt1Func=Copy_pvInt1Func;
	}
	else{
	 Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
u8 EXI_SendInt2ISR(void (*Copy_pvInt2Func)(void)){
	u8 Local_u8ErrorState=OK;
	if(Copy_pvInt2Func!=NULL){
	EXI_pvInt2Func=Copy_pvInt2Func;
	}
	else{
	 Local_u8ErrorState=NOK;
	}

	return Local_u8ErrorState;
}
void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(EXI_pvInt0Func!=NULL){
	EXI_pvInt0Func();
	}
	else{/*DO NOTHING*/}
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(EXI_pvInt1Func!=NULL){
	EXI_pvInt1Func();
	}
	else{/*DO NOTHING*/}
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if(EXI_pvInt2Func!=NULL){
	EXI_pvInt2Func();
	}
	else{/*DO NOTHING*/}
}
