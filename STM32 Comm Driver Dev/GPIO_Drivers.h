/*
 * GPIO_Drivers.h
 *
 *  Created on: Apr 15, 2024
 *      Author: C. Holladay
 */

#ifndef INC_GPIO_DRIVERS_H_
#define INC_GPIO_DRIVERS_H_

#include "stm32f407g.h"


// Configuration struct for the GPIO pin
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;



// handle struct for GPIO pin

typedef struct
{
	//pointer to hold the GPIO base address of whichever GPIO you want.
	GPIO_RegDef_t *pGPIOx; // = GPIOA etc. ((GPIO_RegDef_t*)GPIOA_BASEADDR)
	GPIO_PinConfig_t GPIO_PinConfig; // hold config settings.
}GPIO_Handle_t;


//*********************************************************************************
//-------------------------APIs supported by this driver---------------------------
//*********************************************************************************

// Clock Control

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);
                          // not sure why the video said to use GPIO_RegDef_t instead of the RCC_RegDef_t.

// GPIO init / deinit

void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx); // video said to use GPIO_RegDef_t,
                                         // but i think i should be using RCC_RegDef_t *pRCC_RegDef as an argument...
                                         // 7.3.5 in manual is the RCC reset reg.
// Data read write

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WrietToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WrietToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

// IRQ Config and ISR handling

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDI);
void GPIO_IRQHandling(uint8_t PinNumber);





















#endif /* INC_GPIO_DRIVERS_H_ */
