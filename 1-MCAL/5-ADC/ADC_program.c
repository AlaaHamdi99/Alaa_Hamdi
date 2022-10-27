/********************************************************/
/********************************************************/
/*****************  Author:Alaa Hamid *******************/
/*****************  Layer:MCAL        *******************/
/*****************  SWC:ADC           *******************/
/*****************  Version:1         *******************/
/********************************************************/
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_interface.h"
#include "ADC_register.h"
#include "ADC_config.h"
#include "ADC_private.h"

static u16 * ADC_u16Reading=NULL;
static void  (*ADC_pvCallBackNotificationFunc)(void)=NULL;
static u16 * ADC_u16ChainReading;
static u8    ADC_u8ChainIndex=0;
static u8    ADC_u8ChainSize=0;
static u8  * ADC_u8ChainChannelID=0;

u8 ADC_u8ISRSource;
u8 ADC_u8BusyState=IDLE;

void  ADC_voidInit(){
	/* Avcc reference voltage*/
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
	/*ADC left adjust result MSB(D2-->D9)*/
	SET_BIT(ADMUX,ADMUX_ADLAR);
	/*Set pre_scaler to divide by 128*/
	SET_BIT(ADCSRA,ADCSRA_ADPS2);
	SET_BIT(ADCSRA,ADCSRA_ADPS1);
	SET_BIT(ADCSRA,ADCSRA_ADPS0);

	/*ADC peripherals enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}
u8    ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16 *Copy_pu16Reading){
	u32 Local_u32Counter=0;u8 Local_u8ErrorState=OK;

	if(ADC_u8BusyState==IDLE){
		/*Make the ADC busy in order not to work until being idle*/
		ADC_u8BusyState=BUSY;
		/*Clear MUX Bits (0-->4)*/
		ADMUX &=ADC_ADMUX_MASK;
		/*Oaring ADMUX with Copy_u8Channel  to select channel*/
		ADMUX |=Copy_u8Channel;
#if ADC_AUTO_TRIGGER_STATE==DISABLED
		/*Start conversion*/
		SET_BIT(ADCSRA,ADCSRA_ADSC);
		/*Polling till the interrupt flag be one or counter reaching time out*/
		while((GET_BIT(ADCSRA,ADCSRA_ADIF)==0)&&(Local_u32Counter!=ADC_u32TIMEOUT)){
			Local_u32Counter++;
		}
#endif
		if(Local_u32Counter==ADC_u32TIMEOUT){
			Local_u8ErrorState=NOK;//Loop is broken because the timeout is reached
		}
		else{
			/*Loop is broken because flag is raised*/
			/*Clearing the flag*/
			SET_BIT(ADCSRA,ADCSRA_ADIF);
			/*Return the reading*/
#if   ADC_DATA_RESOLUTION==_8_bit
			*Copy_pu16Reading= ADCH;
#elif ADC_DATA_RESOLUTION=_10_bit
			*Copy_pu16Reading=ADC_TOTAL_DATA;
#else
#error  "Wrong ADC_DATA_RESOLUTION selection"
#endif
			/*Make the ADC idle because it finished */
			ADC_u8BusyState=IDLE;
		}
	}
	else{
		Local_u8ErrorState=BUSY_FUNC;
	}


	return Local_u8ErrorState;
}
u8    ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u16 *Copy_pu16Reading,void (*Copy_pvNotificationFunc)(void)){
	u8 Local_u8ErrorState=OK;
	if(ADC_u8BusyState==IDLE){
		if((Copy_pu16Reading==NULL)||(Copy_pvNotificationFunc==NULL)){
			Local_u8ErrorState=NULL_POINTER;
		}
		else{
			/*Make the ADC busy in order not to work until being idle*/
			ADC_u8BusyState=BUSY;
			/*make ISR source single channel ASYN*/
			ADC_u8ISRSource=SINGLE_ASYN_CONVERSION;
			/*Initialize the reading globally */
			ADC_u16Reading=Copy_pu16Reading;
			/*Initialize the Notification globally */
			ADC_pvCallBackNotificationFunc=Copy_pvNotificationFunc;
			/*Clear MUX Bits (0-->4)*/
			ADMUX &=ADC_ADMUX_MASK;
			/*Oaring ADMUX with Copy_u8Channel  to select channel*/
			ADMUX |=Copy_u8Channel;
			/*Start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*Enable the  ADC interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else{
		return Local_u8ErrorState=BUSY_FUNC;
	}
	return Local_u8ErrorState;
}

void  ADC_voidPreInit(){
	/*reference voltage*/
#if   ADC_REFERENCE_VOLTAGE==AVCC
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_REFERENCE_VOLTAGE==AREF
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif ADC_REFERENCE_VOLTAGE==Intrnal_REF2
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#else
#warning  "Wrong ADC_REFERENCE_VOLTAGE option "
#endif
	/*ADC Direction adjust result */
#if ADC_DATA_RESOLUTION==_8_bit
	/*ADC left adjust result MSB(D2-->D9)*/
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif  ADC_DATA_RESOLUTION==_10_bit
	/*ADC Right adjust result MSB(D0-->D9)*/
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#warning		"Wrong ADC_READING_DATA_OPTION option"
#endif
	/*Set pre_scaler to divide vector*/
	ADCSRA&=ADC_PRESCALER_MASK;
	ADCSRA|=ADC_PRESCALER_OPTION;
#if ADC_AUTO_TRIGGER_STATE==ENABLED
	/*Auto trigger enable*/
	SET_BIT(ADCSRA,ADCSRA_ADATE);
	/*Special function I/O register Masking*/
	SFIOR&=ADC_AUTO_TRIGGER_MASK;
	/*Giving a value to Special function I/O register*/
	SFIOR|=ADC_AUTO_TRIGGER_MODE;
	/*start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);
#elif  ADC_AUTO_TRIGGER_STATE==DISABLED
	/*Auto trigger disabled*/
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
#else
#error   "Wrong  ADC_AUTO_TRIGGER_STATE ,please check your configuration"


#endif
	/*ADC peripherals enable*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u8  ADC_vStartChainConversionsAsynch(ADC_Chain_t * Copy_Chain){
	u8 Local_u8ErrorState=OK;
	if(Copy_Chain==NULL){
		Local_u8ErrorState=NULL_POINTER;
	}
	else{
		if(ADC_u8BusyState==IDLE){
			/*Make ADC busy*/
			ADC_u8BusyState=BUSY;
			/*make ISR source chain ASYN*/
			ADC_u8ISRSource=CHAIN_ASYN_CONVERSION;

			/*Initialize the global notification function */
			ADC_pvCallBackNotificationFunc=Copy_Chain->CallBackNotification;
			/*Initialize the global result array */
			ADC_u16ChainReading=Copy_Chain->resultArr;
			/*Initialize the global chain size */
			ADC_u8ChainSize=Copy_Chain->SIZE;
			/*Initialize the global chain channel array*/
			ADC_u8ChainChannelID=Copy_Chain->channel;
			/*Make index firstly =0*/
			ADC_u8ChainIndex=0;
			/*set channel*/
			/*ADMUX masking*/
			ADMUX&=ADC_ADMUX_MASK;
			/*Specify the channel*/
			ADMUX|=ADC_u8ChainChannelID[ADC_u8ChainIndex];
			/*Enable the ADC interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
			/*Start conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*ADC enable*/
			SET_BIT(ADCSRA,ADCSRA_ADEN);
		}
		else{
			Local_u8ErrorState=BUSY_FUNC;
		}

	}

	return Local_u8ErrorState;

}


void __vector_16(void) __attribute__((signal));
void __vector_16(void){
	if(ADC_u8ISRSource==SINGLE_ASYN_CONVERSION){/*ISR source is the Asynchronous channel */
		/*Read the result*/
#if ADC_DATA_RESOLUTION==_8_bit
		*ADC_u16Reading=ADC_ONLY_MS_DATA;
#elif ADC_DATA_RESOLUTION==_10_bit
		*ADC_u16Reading=ADC_TOTAL_DATA;
#else
#error  "Wrong ADC_DATA_RESOLUTION selection"
#endif

		/*Make the ADC idle because it finished */
		ADC_u8BusyState=IDLE;
		/*Invoke the callback Notification function*/
		ADC_pvCallBackNotificationFunc();
		/*Disable the ADC conversion complete interrupt*/
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else if(ADC_u8ISRSource==CHAIN_ASYN_CONVERSION){/*ISR source is the Asynchronous chain */
		/*Read the result*/
#if     ADC_DATA_RESOLUTION==_8_bit
		ADC_u16ChainReading[ADC_u8ChainIndex]=ADC_ONLY_MS_DATA;
#elif ADC_DATA_RESOLUTION==_10_bit
		*ADC_u16ChainReading=ADC_TOTAL_DATA;
#else
#error  "Wrong ADC_DATA_RESOLUTION selection"
#endif
		ADC_u8ChainIndex++;
		if(ADC_u8ChainIndex==ADC_u8ChainSize){
			/*Make the ADC idle because it finished */
			ADC_u8BusyState=IDLE;
			/*Invoke the callback Notification function*/
			ADC_pvCallBackNotificationFunc();
			/*Disable the ADC conversion complete interrupt*/
			CLR_BIT(ADCSRA,ADCSRA_ADIE);


		}
		else{
			/*Invoke ISR every time while Interrupt is enabled */
			/*Set the next channel*/
			ADMUX&=ADC_ADMUX_MASK;
			ADMUX|=ADC_u8ChainChannelID[ADC_u8ChainIndex];
			/*Start new conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
	}
}







