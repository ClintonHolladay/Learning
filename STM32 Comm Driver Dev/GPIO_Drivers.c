/*
 * GPIO_Drivers.c
 *
 *  Created on: Apr 15, 2024
 *      Author: C. Holladay
 */

#include "stm32f407g.h"
#include "GPIO_Drivers.h"


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
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
	}
}	else //((EnorDi == DISABLE))
	{
		//TODO
	}

// GPIO init / deinit
/**********************************************************************************
 * @Function Name 	- GPIO_Init
 *
 * @Description		- Initializes a given GPIO register
 *
 * @Param[in1]		- Base address of the given GPIO
 * @Param[in2]		-
 * @Param[in3]		-
 *
 * @return value	- NONE
 *
 * @Notes			- NONE
 *
 **********************************************************************************/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{

}

/**********************************************************************************
 * @Function Name 	- GPIO_DeInit
 *
 * @Description		- Disables a given GPIO
 *
 * @Param[in1]		- Base address of the given GPIO
 * @Param[in2]		-
 * @Param[in3]		-
 *
 * @return value	- NONE
 *
 * @Notes			- NONE
 *
 **********************************************************************************/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)  // video said to use GPIO_RegDef_t,
                                         // but i think i should be using RCC_RegDef_t *pRCC_RegDef as an argument...
                                         // 7.3.5 in manual is the RCC reset reg.
{

}

// Data read write
/**********************************************************************************
 * @Function Name 	- GPIO_ReadFromInputPin
 *
 * @Description		- Read data from a given GPIO pin
 *
 * @Param[in1]		- Base address of the given GPIO
 * @Param[in2]		- any given pin # for the GPIO that you want to read data from
 * @Param[in3]		-
 *
 * @return value	- uint8_t
 *
 * @Notes			- NONE
 *
 **********************************************************************************/
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

}

/**********************************************************************************
 * @Function Name 	- GPIO_ReadFromInputPort
 *
 * @Description		- Read data from a given GPIO port... not sure of the difference from a pin
 *
 * @Param[in1]		- Base address of the given GPIO
 * @Param[in2]		- any given port # for the GPIO that you want to read data from
 * @Param[in3]		-
 *
 * @return value	- uint16_t
 *
 * @Notes			- NONE
 *
 **********************************************************************************/

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{

}

/**********************************************************************************
 * @Function Name 	- GPIO_WriteToOutputPin
 *
 * @Description		- write data to a given GPIO pin
 *
 * @Param[in1]		- Base address of the given GPIO
 * @Param[in2]		- any given pin # for the GPIO that you want to write data to
 * @Param[in3]		-
 *
 * @return value	- NONE
 *
 * @Notes			- NONE
 *
 **********************************************************************************/

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{

}

/**********************************************************************************
 * @Function Name 	- GPIO_WrietToOutputPort
 *
 * @Description		- write data to a given GPIO port
 *
 * @Param[in1]		- Base address of the given GPIO
 * @Param[in2]		- any given port # for the GPIO that you want to write data to
 * @Param[in3]		-
 *
 * @return value	- NONE
 *
 * @Notes			- NONE
 *
 **********************************************************************************/

void GPIO_WrietToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{

}

/**********************************************************************************
 * @Function Name 	- GPIO_ToggleOutputPin
 *
 * @Description		- Toggle a given GPIO pin
 *
 * @Param[in1]		- Base address of the given GPIO
 * @Param[in2]		- any given pin # for the GPIO that you want to toggle
 * @Param[in3]		-
 *
 * @return value	- NONE
 *
 * @Notes			- NONE
 *
 **********************************************************************************/

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

}

// IRQ Config and ISR handling
/**********************************************************************************
 * @Function Name 	- GPIO_IRQConfig
 *
 * @Description		- Configure interrupts
 *
 * @Param[in1]		- IRQ #
 * @Param[in2]		- IRQ Priority
 * @Param[in3]		- 1 or 2 Activate / deactivate
 *
 * @return value	- NONE
 *
 * @Notes			- NONE
 *
 **********************************************************************************/
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDI)
{

}

/**********************************************************************************
 * @Function Name 	- GPIO_IRQHandling
 *
 * @Description		- Interrupt maipulations of some sort?
 *
 * @Param[in1]		- A given GPIO pin#
 * @Param[in2]		-
 * @Param[in3]		-
 *
 * @return value	- NONE
 *
 * @Notes			- NONE
 *
 **********************************************************************************/

void GPIO_IRQHandling(uint8_t PinNumber)
{

}














