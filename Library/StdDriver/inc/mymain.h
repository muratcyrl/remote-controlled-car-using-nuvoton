
#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdio.h>
#include <NUC029FAE.h>
#include "uart.h"
#include <stdio.h>
#include "pwm.h"
#include "gpio.h"
int32_t main(void);
void SYS_Init(void);
void UART_Init(void);
#endif
