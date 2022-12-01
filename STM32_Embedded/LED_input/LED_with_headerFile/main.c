/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Clinton Holladay
 * adding the new union/struct data structures to the LED file.
 ******************************************************************************
*/

#include <stdint.h>
#include "main.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
                           //Address
#define RCC_address        0x40023830 //RCC AHB1 peripheral clock register Address offset: 0x30

#define GPIOD_Mode_address 0x40020C00 //GPIO port mode register Address offset: 0x00
#define GPIOD_Data_address 0x40020C14 //GPIO port output data register Address offset: 0x14

#define GPIOA_Mode_address 0x40020000 //GPIO port mode register Address offset: 0x00
#define GPIOA_Data_address 0x40020010 //GPIO port input data register Address offset: 0x10

#define ON 1
#define OFF 0
#define OUTPUT 1
#define INPUT 0
#define ENABLE 1
#define DISABLE 0

int main(void)
{
  //To directly set a pointer to an address you have to (cast*) the address# to a pointer variable.
	RCC_AHB1ENR_s volatile *const clockRegister = (RCC_AHB1ENR_s*)RCC_address;
	GPIOx_MODER_s volatile *const DmodeRegister = (GPIOx_MODER_s*)GPIOD_Mode_address;
	GPIOx_ODR_s volatile *const outputRegister = (GPIOx_ODR_s*)GPIOD_Data_address;
	GPIOx_MODER_s volatile *const AmodeRegister = (GPIOx_MODER_s*)GPIOA_Mode_address;//Default is INPUT;
	GPIOx_IDR_s const volatile *const inputRegister = (GPIOx_IDR_s*)GPIOA_Data_address;

  //RCC AHB1 peripheral clock enable register Enable GPIOD & GPIOA
    clockRegister->gpioa_en = ENABLE;
    clockRegister->gpiod_en = ENABLE;

  //Configure GPIOs
    DmodeRegister->moder_12 = OUTPUT; //output
    AmodeRegister->moder_0 = INPUT;  //input

	while(1)
	{
		if(inputRegister->idr_0 == ON) outputRegister->odr_12 = ON;
		else outputRegister->odr_12 = OFF;
	}
}
