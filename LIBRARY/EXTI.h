/*
 * EXTI.h
 *
 *  Created on: Apr 19, 2020
 *      Author: MCLEANS
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "stm32f10x.h"

namespace custom_libraries {

enum edge{
	FALLING,
	RISING
};

enum Default_state{
	PULL_UP,
	PULL_DOWN
};

class _EXTI {
private:
	GPIO_TypeDef *GPIO;
	uint8_t PIN;
	edge interrupt_edge;
	Default_state default_state;

private:
public:
public:
	_EXTI(GPIO_TypeDef *GPIO,
			uint8_t PIN,
			edge interrupt_edge,
			Default_state default_state);
	void initialize();
	~_EXTI();
};

} /* namespace custom_libraries */

#endif /* EXTI_H_ */
