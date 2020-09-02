/*
 * EXTI.cpp
 *
 *  Created on: Apr 19, 2020
 *      Author: MCLEANS
 */

#include "EXTI.h"

namespace custom_libraries {

_EXTI::_EXTI(GPIO_TypeDef *GPIO,
			uint8_t PIN,
			edge interrupt_edge,
			Default_state default_state):GPIO(GPIO),
								PIN(PIN),
								interrupt_edge(interrupt_edge),
								default_state(default_state){
	//enable AFIO RCC
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;

	//Enable GPIO_RCC
	if(GPIO == GPIOA) RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	if(GPIO == GPIOB) RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	if(GPIO == GPIOC) RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	if(GPIO == GPIOD) RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
	if(GPIO == GPIOE) RCC->APB2ENR |= RCC_APB2ENR_IOPEEN;

	//select actual ext_int pin in interrupt system configuration register.
	if(PIN < 4 ){
		if(GPIO == GPIOA){
			AFIO->EXTICR[0] &= ~(1<<(PIN*4));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+1));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+2));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+3));
		}
		if(GPIO == GPIOB){
			AFIO->EXTICR[0] |= (1<<(PIN*4));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+1));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+2));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+3));
		}
		if(GPIO == GPIOC){
			AFIO->EXTICR[0] &= ~(1<<(PIN*4));
			AFIO->EXTICR[0] |= (1<<((PIN*4)+1));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+2));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+3));
		}
		if(GPIO == GPIOD){
			AFIO->EXTICR[0] |= (1<<(PIN*4));
			AFIO->EXTICR[0] |= (1<<((PIN*4)+1));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+2));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+3));
		}
		if(GPIO == GPIOE){
			AFIO->EXTICR[0] &= ~(1<<(PIN*4));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+1));
			AFIO->EXTICR[0] |= (1<<((PIN*4)+2));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+3));
		}
		if(GPIO == GPIOF){
			AFIO->EXTICR[0] |= (1<<(PIN*4));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+1));
			AFIO->EXTICR[0] |= (1<<((PIN*4)+2));
			AFIO->EXTICR[0] &= ~(1<<((PIN*4)+3));
		}
}

	if(PIN > 3 and PIN < 8){
		if(GPIO == GPIOA){
			AFIO->EXTICR[1] &= ~(1<<((PIN-4)*4));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+1));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+2));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+3));
		}
		if(GPIO == GPIOB){
			AFIO->EXTICR[1] |= (1<<((PIN-4)*4));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+1));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+2));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+3));
		}
		if(GPIO == GPIOC){
			AFIO->EXTICR[1] &= ~(1<<((PIN-4)*4));
			AFIO->EXTICR[1] |= (1<<(((PIN-4)*4)+1));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+2));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+3));
		}
		if(GPIO == GPIOD) {
			AFIO->EXTICR[1] |= (1<<((PIN-4)*4));
			AFIO->EXTICR[1] |= (1<<(((PIN-4)*4)+1));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+2));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+3));
		}
		if(GPIO == GPIOE){
			AFIO->EXTICR[1] &= ~(1<<((PIN-4)*4));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+1));
			AFIO->EXTICR[1] |= (1<<(((PIN-4)*4)+2));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+3));
		}
		if(GPIO == GPIOF){
			AFIO->EXTICR[1] |= (1<<((PIN-4)*4));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+1));
			AFIO->EXTICR[1] |= (1<<(((PIN-4)*4)+2));
			AFIO->EXTICR[1] &= ~(1<<(((PIN-4)*4)+3));
		}
	}

	if(PIN > 8 and PIN <12){
		if(GPIO == GPIOA){
			AFIO->EXTICR[2] &= ~(1<<((PIN-8)*4));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+1));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+2));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+3));
		}
		if(GPIO == GPIOB){
			AFIO->EXTICR[2] |= (1<<((PIN-8)*4));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+1));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+2));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+3));
		}
		if(GPIO == GPIOC) {
			AFIO->EXTICR[2] &= ~(1<<((PIN-8)*4));
			AFIO->EXTICR[2] |= (1<<(((PIN-8)*4)+1));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+2));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+3));
		}
		if(GPIO == GPIOD) {
			AFIO->EXTICR[2] |= (1<<((PIN-8)*4));
			AFIO->EXTICR[2] |= (1<<(((PIN-8)*4)+1));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+2));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+3));
		}
		if(GPIO == GPIOE){
			AFIO->EXTICR[2] &= ~(1<<((PIN-8)*4));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+1));
			AFIO->EXTICR[2] |= (1<<(((PIN-8)*4)+2));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+3));
		}
		if(GPIO == GPIOF) {
			AFIO->EXTICR[2] |= (1<<((PIN-8)*4));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+1));
			AFIO->EXTICR[2] |= (1<<(((PIN-8)*4)+2));
			AFIO->EXTICR[2] &= ~(1<<(((PIN-8)*4)+3));
		}
	}

	if(PIN > 11 and PIN < 16){
		if(GPIO == GPIOA){
			AFIO->EXTICR[3] &= ~(1<<((PIN-12)*4));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+1));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+2));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+3));
		}
		if(GPIO == GPIOB) {
			AFIO->EXTICR[3] |= (1<<((PIN-12)*4));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+1));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+2));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+3));
		}
		if(GPIO == GPIOC) {
			AFIO->EXTICR[3] &= ~(1<<((PIN-12)*4));
			AFIO->EXTICR[3] |= (1<<(((PIN-12)*4)+1));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+2));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+3));
		}
		if(GPIO == GPIOD){
			AFIO->EXTICR[3] |= (1<<((PIN-12)*4));
			AFIO->EXTICR[3] |= (1<<(((PIN-12)*4)+1));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+2));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+3));
		}
		if(GPIO == GPIOE){
			AFIO->EXTICR[3] &= ~(1<<((PIN-12)*4));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+1));
			AFIO->EXTICR[3] |= (1<<(((PIN-12)*4)+2));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+3));
		}
		if(GPIO == GPIOF){
			AFIO->EXTICR[3] |= (1<<((PIN-12)*4));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+1));
			AFIO->EXTICR[3] |= (1<<(((PIN-12)*4)+2));
			AFIO->EXTICR[3] &= ~(1<<(((PIN-12)*4)+3));
		}

	}
}

void _EXTI::initialize(){
	//Unmask the interrupt
	EXTI->IMR |= (1<<PIN);
	//set whether falling edge or rising edge
	if(interrupt_edge == FALLING){
		EXTI->FTSR |= (1<<PIN);
	}
	else if(interrupt_edge == RISING){
		EXTI->RTSR |= (1<<PIN);
	}
	//set interrupt line to input pull_up
	if(default_state == PULL_UP){
		if(PIN < 8){
			//INPUT MODE
			GPIO->CRL &= ~(1<<(PIN*4));
			GPIO->CRL &= ~(1<<((PIN*4)+1));

			GPIO->CRL &= ~(1<<((PIN*4)+2));
			GPIO->CRL |= (1<<((PIN*4)+3));

			//PULL_UP
			GPIO->ODR |= (1<<PIN);
		}
		else{
			//INPUT MODE
			GPIO->CRL &= ~(1<<((PIN-8)*4));
			GPIO->CRL &= ~(1<<(((PIN-8)*4)+1));

			GPIO->CRL &= ~(1<<(((PIN-8)*4)+2));
			GPIO->CRL |= (1<<(((PIN-8)*4)+3));

			//PULL_UP
			GPIO->ODR |= (1<<PIN);

		}
		
	}
	else if(default_state == PULL_DOWN){
		if(PIN < 8){
			//INPUT MODE
			GPIO->CRL &= ~(1<<(PIN*4));
			GPIO->CRL &= ~(1<<((PIN*4)+1));

			GPIO->CRL &= ~(1<<((PIN*4)+2));
			GPIO->CRL |= (1<<((PIN*4)+3));

			//PULL_DOWN
			GPIO->ODR &= ~(1<<PIN);
		}
		else{
			//INPUT MODE
			GPIO->CRL &= ~(1<<((PIN-8)*4));
			GPIO->CRL &= ~(1<<(((PIN-8)*4)+1));

			GPIO->CRL &= ~(1<<(((PIN-8)*4)+2));
			GPIO->CRL |= (1<<(((PIN-8)*4)+3));

			//PULL_DOWN
			GPIO->ODR &= ~(1<<PIN);

		}
	}
}

_EXTI::~_EXTI() {
	// TODO Auto-generated destructor stub
}

} /* namespace custom_libraries */
