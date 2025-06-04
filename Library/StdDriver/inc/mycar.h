#ifndef __CARR__
#define __CARR__
#include <stdio.h>
#include <NUC029FAE.h>
#include "uart.h"

#define WHEEL_LEFT P05
#define WHEEL_RIGHT P06
#define GAS P15
#define CAR_MOD P14
#define SPEED1 P34
#define SPEED2 P35
#define SPEED3 P25
void CAR_MOVING(void);
void ATTACH_UART(void);
void DETACH_UART(void);
void CAR_MANUEL(void);

typedef struct cAr_settings{
	uint8_t duty;
	uint8_t u8IntChar;
	uint8_t port;
	uint32_t freq;
	uint32_t u32IntSts;
}settings;
settings *_settings(void);
#endif 
