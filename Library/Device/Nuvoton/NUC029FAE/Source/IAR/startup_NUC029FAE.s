;/*************************************************************************//**
; * @file     startup_NUC029FAE.s
; * @version  V2.00
; * $Revision: 2 $
; * $Date: 16/06/07 2:41p $
; * @brief    CMSIS ARM Cortex-M0 Core Device Startup File
; *
; * @note
; * SPDX-License-Identifier: Apache-2.0
; * Copyright (C) 2024 Nuvoton Technology Corp. All rights reserved.
;*****************************************************************************/



    MODULE  ?cstartup

    ;; Forward declaration of sections.
    SECTION CSTACK:DATA:NOROOT(3) ;; 8 bytes alignment

    SECTION .intvec:CODE:NOROOT(2);; 4 bytes alignment

    EXTERN  __iar_program_start
    EXTERN  ProcessHardFault
    PUBLIC  __vector_table

    DATA
__vector_table
    DCD     sfe(CSTACK)
    DCD     __iar_program_start

    DCD     NMI_Handler
    DCD     HardFault_Handler
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     0
    DCD     SVC_Handler
    DCD     0
    DCD     0
    DCD     PendSV_Handler
    DCD     SysTick_Handler

    ; External Interrupts
    DCD     BOD_IRQHandler              ; Brownout low voltage detected interrupt
    DCD     WDT_IRQHandler              ; Watch Dog Timer interrupt
    DCD     EINT0_IRQHandler            ; External signal interrupt from PB.14 pin
    DCD     EINT1_IRQHandler            ; External signal interrupt from PB.15 pin
    DCD     GPIO01_IRQHandler           ; External signal interrupt from P0[7:0] / P1[7:0]
    DCD     GPIO234_IRQHandler          ; External interrupt from P2[7:0]/P3[7:0]/P4[7:0]
    DCD     PWM_IRQHandler              ; PWM interrupt
    DCD     FB_IRQHandler
    DCD     TMR0_IRQHandler             ; Timer 0 interrupt
    DCD     TMR1_IRQHandler             ; Timer 1 interrupt
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     UART_IRQHandler             ; UART interrupt
    DCD     Default_Handler
    DCD     SPI_IRQHandler             ; SPI interrupt
    DCD     Default_Handler
    DCD     GPIO5_IRQHandler            ; GP5[7:0] interrupt
    DCD     HIRC_IRQHandler             ; HIRC interrupt
    DCD     I2C_IRQHandler              ; I2C interrupt
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     ACMP_IRQHandler
    DCD     Default_Handler
    DCD     Default_Handler
    DCD     PDWU_IRQHandler
    DCD     ADC_IRQHandler              ; ADC interrupt
    DCD     Default_Handler
    DCD     Default_Handler

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
    THUMB
    PUBWEAK Reset_Handler
    SECTION .text:CODE:REORDER:NOROOT(2)       ; 4 bytes alignment
Reset_Handler

        LDR      R0, =__iar_program_start
        BX       R0

    PUBWEAK HardFault_Handler
    SECTION .text:CODE:REORDER:NOROOT(2)
HardFault_Handler
        MOV     R0, LR
        MRS     R1, MSP
        MRS     R2, PSP
        LDR     R3, =ProcessHardFault
        BLX     R3
        BX      R0

    PUBWEAK NMI_Handler
    PUBWEAK SVC_Handler
    PUBWEAK PendSV_Handler
    PUBWEAK SysTick_Handler
    PUBWEAK BOD_IRQHandler
    PUBWEAK WDT_IRQHandler
    PUBWEAK EINT0_IRQHandler
    PUBWEAK EINT1_IRQHandler
    PUBWEAK GPIO01_IRQHandler
    PUBWEAK GPIO234_IRQHandler
    PUBWEAK PWM_IRQHandler
    PUBWEAK FB_IRQHandler
    PUBWEAK TMR0_IRQHandler
    PUBWEAK TMR1_IRQHandler
    PUBWEAK UART_IRQHandler
    PUBWEAK SPI_IRQHandler
    PUBWEAK GPIO5_IRQHandler
    PUBWEAK HIRC_IRQHandler
    PUBWEAK I2C_IRQHandler
    PUBWEAK ACMP_IRQHandler
    PUBWEAK PDWU_IRQHandler
    PUBWEAK ADC_IRQHandler

    SECTION .text:CODE:REORDER:NOROOT(2)

NMI_Handler
SVC_Handler
PendSV_Handler
SysTick_Handler
BOD_IRQHandler
WDT_IRQHandler
EINT0_IRQHandler
EINT1_IRQHandler
GPIO01_IRQHandler
GPIO234_IRQHandler
PWM_IRQHandler
FB_IRQHandler
TMR0_IRQHandler
TMR1_IRQHandler
UART_IRQHandler
SPI_IRQHandler
GPIO5_IRQHandler
HIRC_IRQHandler
I2C_IRQHandler
ACMP_IRQHandler
PDWU_IRQHandler
ADC_IRQHandler
Default_Handler
    B Default_Handler


;int32_t SH_DoCommand(int32_t n32In_R0, int32_t n32In_R1, int32_t *pn32Out_R0)
    PUBWEAK SH_DoCommand
    SECTION .text:CODE:REORDER:ROOT(2)
SH_DoCommand
    IMPORT      SH_Return

    BKPT    0xAB                ; Wait ICE or HardFault
    LDR     R3, =SH_Return
		PUSH    {R3 ,lr}
    BLX     R3                  ; Call SH_Return. The return value is in R0
		POP     {R3 ,PC}            ; Return value = R0


    END
;/*** (C) COPYRIGHT 2024 Nuvoton Technology Corp. ***/
