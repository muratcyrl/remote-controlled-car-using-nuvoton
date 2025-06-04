
#include "mymain.h"
#include "mycar.h"
void SYS_Init(void)
{
   SYS_UnlockReg();
    /* Enable internal 22.1184MHz */
		CLK->PWRCON = CLK_PWRCON_IRC22M_EN_Msk;
		CLK_WaitClockReady(CLK_CLKSTATUS_IRC22M_STB_Msk);
    /* Enable IP clock */
    CLK->APBCLK |= CLK_APBCLK_UART_EN_Msk; // UART Clock Enable
		/* Start UART Clock */
    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate PllClock, SystemCoreClock and CycylesPerUs automatically. */
    SystemCoreClockUpdate();
    /*---------------------------------------------------------------------------------------------------------*/
    /* Init I/O Multi-function                                                                                 */
    /*---------------------------------------------------------------------------------------------------------*/
    /* Set P1 multi-function pins for UART1 RXD and TXD  */
    SYS->P1_MFP &= ~(SYS_MFP_P12_Msk | SYS_MFP_P13_Msk);
    SYS->P1_MFP |= (SYS_MFP_P12_RXD | SYS_MFP_P13_TXD);
		//Settings of PWM
		CLK->APBCLK |= CLK_APBCLK_PWM23_EN_Msk;
    SYS->P2_MFP= SYS_MFP_P24_PWM2;
    /* Lock protected registers */
    SYS_LockReg();
}
void UART_Init()
{
	  UART_Open(UART, 9600);
	  PWM_EnableOutput(PWM,(1<<2));
	  GPIO_SetMode(P0,BIT5,GPIO_PMD_OUTPUT);
	  GPIO_SetMode(P0,BIT6,GPIO_PMD_OUTPUT);
	  GPIO_SetMode(P2,BIT5,GPIO_PMD_OUTPUT);
	  GPIO_SetMode(P1,BIT5,GPIO_PMD_INPUT);
	  GPIO_SetMode(P1,BIT4,GPIO_PMD_INPUT);
}








