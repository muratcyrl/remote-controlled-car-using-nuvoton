/**************************************************************************//**
 * @file     main.c
 * @version  V2.00
 * $Revision: 3 $
 * $Date: 14/06/11 10:13a $
 * @brief    Transmit and receive data from PC terminal through RS232 interface.
 *
 * @note
 
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
 *
 ******************************************************************************/
#include "mymain.h"
#include "mycar.h"
int32_t main(void){
    SYS_Init();
    UART_Init();
	  while(1)CAR_MANUEL();
}



