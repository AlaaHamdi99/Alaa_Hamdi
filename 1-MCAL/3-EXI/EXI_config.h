/********************************************************/
/********************************************************/
/*****************  Author:Alaa Hamid *******************/
/*****************  Layer:MCAL        *******************/
/*****************  SWC:EXI          *******************/
/*****************  Version:1         *******************/
/********************************************************/
/********************************************************/

#ifndef  EXI_CONFIG_H
#define  EXI_CONFIG_H
/*Options:
1-LOW_LEVEL
2-ON_CHANGE
3-FALLING_EDGE
4-RISING_EDGE*/

#define INT0_SENSE_CONTROL  FALLING_EDGE
#define INT1_SENSE_CONTROL  ON_CHANGE
#define INT2_SENSE_CONTROL  RISING_EDGE

#define  ENABLED   1
#define  DISABLED   1

#define INT0_INITIAL_STATE  ENABLED
#define INT1_INITIAL_STATE  ENABLED
#define INT2_INITIAL_STATE  ENABLED


#endif
