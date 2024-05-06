/*
 * GPIO_Drivers.c
 *
 *  Created on: Apr 15, 2024
 *      Author: C. Holladay
 */

#include "stm32f407g.h"


//*********************************************************************************
//-------------------------API definitions supported by this driver---------------------------
//*********************************************************************************

// Clock Control
/**********************************************************************************
 * @Function Name 	- GPIO_PeriClockControl
 *
 * @Description		- Enables or Disables the peripheral clock for the given GPIO
 *
 * @Param[in1]		- Base address of the given GPIO
 * @Param[in2]		- ENABLE or DISBALE macros
 * @Param[in3]		-
 *
 * @return value	- NONE
 *
 * @Notes			- NONE
 *
 **********************************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
                          // not sure why the video said to use GPIO_RegDef_t instead of the RCC_RegDef_t.
{

}

// GPIO init / deinit

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)  // video said to use GPIO_RegDef_t,
                                         // but i think i should be using RCC_RegDef_t *pRCC_RegDef as an argument...
                                         // 7.3.5 in manual is the RCC reset reg.
{

}
// Data read write

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{

}
void GPIO_WrietToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{

}
void GPIO_WrietToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{

}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

}

// IRQ Config and ISR handling

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDI)
{

}
void GPIO_IRQHandling(uint8_t PinNumber)
{

}














