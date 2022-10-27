/********************************************************/
/********************************************************/
/*****************  Author:Alaa Hamdi *******************/
/*****************  Layer:MCAL        *******************/
/*****************  SWC:ADC           *******************/
/*****************  Version:1         *******************/
/********************************************************/
/********************************************************/

#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

#define  AREF             1   //any other external voltage < 5v
#define  AVCC             2   //internal reference voltages 5v
#define  Intrnal_REF2  3      //internal reference voltages 2.56v
/*Options :
 1-AVCC
 2-AREF
  */
#define  ADC_REFERENCE_VOLTAGE  AVCC


#define ADC_PRESCALER_DIVIDE_BY_2     1     //Faster and more power
#define ADC_PRESCALER_DIVIDE_BY_4     2
#define ADC_PRESCALER_DIVIDE_BY_8     3
#define ADC_PRESCALER_DIVIDE_BY_16    4     //in the middle
#define ADC_PRESCALER_DIVIDE_BY_32    5
#define ADC_PRESCALER_DIVIDE_BY_64    6
#define ADC_PRESCALER_DIVIDE_BY_128   7     //Slower and less power
/*Options:
1- ADC_PRESCALER_DIVIDE_BY_2
2- ADC_PRESCALER_DIVIDE_BY_4
3- ADC_PRESCALER_DIVIDE_BY_8
4- ADC_PRESCALER_DIVIDE_BY_16
5- ADC_PRESCALER_DIVIDE_BY_32
6- ADC_PRESCALER_DIVIDE_BY_64
7- ADC_PRESCALER_DIVIDE_BY_128
 */
#define ADC_PRESCALER_MASK     0b11111000
#define ADC_ADMUX_MASK         0b11100000
#define ADC_PRESCALER_OPTION   ADC_PRESCALER_DIVIDE_BY_128




#define _8_bit           1
#define _10_bit          2
#define ADC_TOTAL_DATA            *((volatile u16*) 0x24)
#define ADC_ONLY_MS_DATA          ADCH

/* Options:
1-_8_bit
2-_10_bit
 */

#define ADC_DATA_RESOLUTION   _8_bit   //Data will be returned



#define ADC_AUTO_TRIGGER_MASK      0b00011111
/*********************************************/
#define ADC_FREE_RUNNING_MODE            0
#define ADC_ANALOGE_COMPARATOR_MODE      1
#define ADC_EXI_INT0_MODE                2
#define ADC_TIM_C0_COMPARE_MATCH_A       3
#define ADC_TIM_C0_OVER_FLOW             4
#define ADC_TIM_C_COMPARE_MATCH_B        5
#define ADC_TIM_C1_OVER_FLOW             6
#define ADC_TIM_C1_CAPTURE_EVENT         7
/*Options:
 1-ADC_FREE_RUNNING_MODE
 2-ADC_ANALOGE_COMPARATOR_MODE
 3-ADC_EXI_INT0_MODE
 4-ADC_TIM_C0_COMPARE_MATCH_A
 5-ADC_TIM_C0_OVER_FLOW
 6-ADC_TIM_C_COMPARE_MATCH_B
 7-ADC_TIM_C1_OVER_FLOW
 8-ADC_TIM_C1_CAPTURE_EVENT
 */
#define ENABLED   1
#define DISABLED  2
#define ADC_AUTO_TRIGGER_STATE  DISABLED
#define ADC_AUTO_TRIGGER_MODE   ADC_FREE_RUNNING_MODE


#define ADC_u32TIMEOUT        50000
#define ADC_u8ChainSTATE      ENABLED



#endif
