#include "stm32f10x.h"
#include "EXTI.h"

#define BUTTON_PIN 9
#define BUTTON_PORT GPIOA

custom_libraries::_EXTI button(BUTTON_PORT,BUTTON_PIN,custom_libraries::FALLING,custom_libraries::PULL_UP);

extern "C" void EXTI9_5_IRQHandler(void){
  //check that we are here becuse of external interrupt 9
  if(EXTI->PR & EXTI_PR_PR9){
    //clear the interrupt flag by writing 1 to it.
    EXTI->PR |= EXTI_PR_PR9;
    GPIOC->ODR ^= GPIO_ODR_ODR13;
  }
}

int main(void) {

    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH |= GPIO_CRH_MODE13;
    GPIOC->CRH &= ~GPIO_CRH_CNF13;

    NVIC_SetPriority(EXTI9_5_IRQn,0X00);
    NVIC_EnableIRQ(EXTI9_5_IRQn);
  
  while(1){
      

  }
}
