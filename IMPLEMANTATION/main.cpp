#include "stm32f10x.h"
#include "EXTI.h"

#define BUTTON_PIN 12
#define BUTTON_PORT GPIOB

custom_libraries::_EXTI button(BUTTON_PORT,BUTTON_PIN,custom_libraries::RISING,custom_libraries::PULL_UP);

extern "C" void EXTI15_10_IRQHandler(void){
  //check that we are here becuse of external interrupt 9
  if(EXTI->PR & EXTI_PR_PR12){
    //clear the interrupt flag by writing 1 to it.
    EXTI->PR |= EXTI_PR_PR12;
    GPIOC->ODR ^= GPIO_ODR_ODR13;
  }
}

int main(void) {

    button.initialize();
  
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH |= GPIO_CRH_MODE13;
    GPIOC->CRH &= ~GPIO_CRH_CNF13;

    NVIC_SetPriority(EXTI15_10_IRQn,0X00);
    NVIC_EnableIRQ(EXTI15_10_IRQn);
  
  while(1){
 

  }
}
