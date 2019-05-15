
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"


volatile int ticks=0;
extern "C" void SysTicks_Handler(){
	ticks++;
}
void delay_ms(int interval){
	int temp=ticks+interval;
	while (ticks<temp);
}

int main(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); //habilitando o periférico
	GPIO_InitTypeDef X1, X2, X3, X4;    // inicializando os objetos de config

	X1.GPIO_Mode=GPIO_Mode_OUT;    // configurando o 'a'
	X1.GPIO_OType=GPIO_OType_PP;
	X1.GPIO_PuPd=GPIO_PuPd_NOPULL;
	X1.GPIO_Speed=GPIO_Speed_2MHz;

	X4=X3=X2=X1;                      // replicando as config de a nos demais

	X1.GPIO_Pin=GPIO_Pin_13;		  // dando a cada um o pino correspondente
	X2.GPIO_Pin=GPIO_Pin_12;
	X3.GPIO_Pin=GPIO_Pin_15;
	X4.GPIO_Pin=GPIO_Pin_14;


	GPIO_Init(GPIOD, &X1);     // inicializando os pinos
	GPIO_Init(GPIOD, &X2);
	GPIO_Init(GPIOD, &X3);
	GPIO_Init(GPIOD, &X4);

	SysTick_Config(168000);

	while(1){
		GPIO_SetBits(GPIOD, GPIO_Pin_15);
		delay_ms(100);
		GPIO_ResetBits(GPIOD, GPIO_Pin_15);

		GPIO_SetBits(GPIOD, GPIO_Pin_14);
		delay_ms(100);
		GPIO_ResetBits(GPIOD, GPIO_Pin_14);

		GPIO_SetBits(GPIOD, GPIO_Pin_13);
		delay_ms(100);
		GPIO_ResetBits(GPIOD, GPIO_Pin_13);

		GPIO_SetBits(GPIOD, GPIO_Pin_12);
		delay_ms(100);
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);
	}

}

extern "C" void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
extern "C" uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
