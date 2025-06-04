#include "mycar.h"
#include "mymain.h"

settings *_settings(){
	settings *me;
	settings introduce;
	me=&introduce;
	me->freq=200000;
	me->u8IntChar=0xFF;
	me->port=2;
	if(me->duty==NULL) me->duty=10;
	me->u32IntSts= UART->ISR;
	return me;
}

settings *car_setting;
settings *car_setting_manuel;

void UART_IRQHandler(void)
{
    CAR_MOVING();
}

void ATTACH_UART()
{
    UART_ENABLE_INT(UART, (UART_IER_RDA_IEN_Msk | UART_IER_THRE_IEN_Msk | UART_IER_RTO_IEN_Msk));
    NVIC_EnableIRQ(UART_IRQn);
}

void DETACH_UART(){
	
	if(CAR_MOD==1){
		 UART_DisableInt(UART, (UART_IER_RDA_IEN_Msk | UART_IER_THRE_IEN_Msk | UART_IER_RTO_IEN_Msk));
     NVIC_DisableIRQ(UART_IRQn);
		}
}

void CAR_MANUEL()
{
	    car_setting_manuel=_settings();
	    if(CAR_MOD==0){
				 ATTACH_UART();
			}
			                                                                                  /*Car Gas Control*/
			if(GAS==0){
				PWM_ConfigOutputChannel(PWM,car_setting_manuel->port,car_setting_manuel->freq,car_setting_manuel->duty);
				PWM_Start(PWM,(1<<2));
				
				
			}
			else{
				PWM_Stop(PWM,(1<<2));
			}
			                                                                                  /*CAR MANUEL SPEED SETTINGS*/
			if(SPEED1==0){
				car_setting_manuel->duty=70;
			}
			if(SPEED2==0){
				car_setting_manuel->duty=40;
			}
			if(SPEED3==0){
				car_setting_manuel->duty=10;
			}
}

void CAR_MOVING()
{
	  
    car_setting=_settings();
	  DETACH_UART();
	
    if(car_setting->u32IntSts & UART_ISR_RDA_INT_Msk)
    {
			  
        printf("\nInput:");

        while(UART_IS_RX_READY(UART))
        {			
				   PWM_ConfigOutputChannel(PWM,car_setting->port,car_setting->freq,car_setting->duty);     
           car_setting->u8IntChar = UART_READ(UART);          
           printf("%c ", car_setting->u8IntChar);
							                                                    /*SPEED SETTINGS*/
				 switch(car_setting->u8IntChar){
						 case '1':
							 car_setting->duty=90;
							 break;
						 case '2':
							 car_setting->duty=80;
							 break;
						 case '3':
							 car_setting->duty=70;
							 break;
						 case '4':
							 car_setting->duty=60;
							 break;
						 case '5':
							 car_setting->duty=50;
							 break;
						 case '6':
							 car_setting->duty=40;
							 break;
						 case '7':
							 car_setting->duty=30;
							 break;
						 case '8':
							 car_setting->duty=20;
							 break;
						 case '9':
							 car_setting->duty=10;
							 break;
						 case 'q':
							 car_setting->duty=9;
							 break;
					 }
					                                                       /*Motor MOVING*/
					 if (car_setting->u8IntChar=='F' || GAS==0){
						 PWM_Start(PWM,(1<<2));
					  }
					 				                                               /*LEFT AND RIGHT  WHEELS' SETTINGS*/
					  if(car_setting->u8IntChar=='L'){
							WHEEL_RIGHT=0;
							WHEEL_LEFT=1;
						}
						if(car_setting->u8IntChar=='R'){
							WHEEL_RIGHT=1;
							WHEEL_LEFT=0;
						}
						                                                     /*If There is no move */
						if(GAS==1 && car_setting->u8IntChar!='F'){
							PWM_Stop(PWM,(1<<2));
						}
						if(car_setting->u8IntChar=='S'){
							WHEEL_LEFT=0;
							WHEEL_RIGHT=0;
						}	
        }
        printf("\nTransmission Test:");
    }
}
