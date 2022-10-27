/********************************************************/
/********************************************************/
/*****************  Author:Alaa Hamid *******************/
/*****************  Layer:MCAL        *******************/
/*****************  SWC:EXI          *******************/
/*****************  Version:1         *******************/
/********************************************************/
/********************************************************/

#ifndef  EXI_INTERFACE_H
#define  EXI_INTERFACE_H

#define LOW_LEVEL    1
#define ON_CHANGE    2
#define FALLING_EDGE 3
#define RISING_EDGE  4

#define EXI_INT0     0
#define EXI_INT1     1
#define EXI_INT2     2

void EXI_voidInt0Init();
void EXI_voidInt1Init();
void EXI_voidInt2Init();

/*Pre_build initialize functions*/
void EXI_voidInt0PreInit();
void EXI_voidInt1PreInit();
void EXI_voidInt2PreInit();
/*Post_build initialize functions*/
u8 EXI_u8Int0SenseControl(u8 Copy_u8Sense);
u8 EXI_u8Int1SenseControl(u8 Copy_u8Sense);
u8 EXI_u8Int2SenseControl(u8 Copy_u8Sense);

u8 EXI_u8IntEnable(u8 Copy_u8Int);
u8 EXI_u8IntDisable(u8 Copy_u8Int);
u8 EXI_SendInt0ISR(void (*Copy_pvInt0Func)(void));
u8 EXI_SendInt1ISR(void (*Copy_pvInt1Func)(void));
u8 EXI_SendInt2ISR(void (*Copy_pvInt2Func)(void));
u8 EXI_u8GetInt0Flag(u8 *Copy_pu8FlagValue);
u8 EXI_u8GetInt1Flag(u8 *Copy_pu8FlagValue);
u8 EXI_u8GetInt2Flag(u8 *Copy_pu8FlagValue);







#endif
