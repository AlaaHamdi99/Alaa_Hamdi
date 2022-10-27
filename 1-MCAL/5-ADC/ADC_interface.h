/********************************************************/
/********************************************************/
/*****************  Author:Alaa Hamid *******************/
/*****************  Layer:MCAL        *******************/
/*****************  SWC:ADC           *******************/
/*****************  Version:1         *******************/
/********************************************************/
/********************************************************/
#ifndef  ADC_INTERFACE_H
#define  ADC_INTERFACE_H

typedef struct {
	u8 * channel;
	u16 *resultArr;
	u8  SIZE;
	void (*CallBackNotification)(void);

}ADC_Chain_t;
void  ADC_voidInit();
void  ADC_voidPreInit();
u8    ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16 *Copy_pu16Reading);
u8    ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u16 *Copy_pu16Reading,void (*Copy_pvNotificationFunc)(void));
u8  ADC_vStartChainConversionsAsynch(ADC_Chain_t * Copy_Chain);


/*Single ended mode ADMUX DATA Bits*/
#define  ADC_ADC0             0
#define  ADC_ADC1             1
#define  ADC_ADC2             2
#define  ADC_ADC3             3
#define  ADC_ADC4             4
#define  ADC_ADC5             5
#define  ADC_ADC6             6
#define  ADC_ADC7             7
/*Differential mode  ADMUX DATA Bits*/
#define  ADC_PADC0_NADC0_10x  8
#define  ADC_PADC1_NADC0_10x  9
#define  ADC_PADC0_NADC0_200x 10
#define  ADC_PADC1_NADC0_200x 11
#define  ADC_PADC2_NADC2_10x  12
#define  ADC_PADC3_NADC2_10x  13
#define  ADC_PADC2_NADC2_200x 14
#define  ADC_PADC3_NADC2_200x 15
#define  ADC_PADC0_NADC1_1x   16
#define  ADC_PADC1_NADC1_1x   17
#define  ADC_PADC2_NADC1_1x   18
#define  ADC_PADC3_NADC1_1x   19
#define  ADC_PADC4_NADC1_1x   20
#define  ADC_PADC5_NADC1_1x   21
#define  ADC_PADC6_NADC1_1x   22
#define  ADC_PADC7_NADC1_1x   23
#define  ADC_PADC0_NADC2_1x   24
#define  ADC_PADC1_NADC2_1x   25
#define  ADC_PADC2_NADC2_1x   26
#define  ADC_PADC3_NADC2_1x   27
#define  ADC_PADC4_NADC2_1x   28
#define  ADC_PADC5_NADC2_1x   29


#endif
