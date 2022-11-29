/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Clinton Holladay
 * Turns on the LED if PA0 is HIGH.
 * I looked in the reference manual to find the memory addresses for all the GPIOA info
 ******************************************************************************
*/

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define RCC_address        0x40023830 //RCC AHB1 peripheral clock register Address offset: 0x30

#define GPIOD_Mode_address 0x40020C00 //GPIO port mode register Address offset: 0x00
#define GPIOD_Data_address 0x40020C14 //GPIO port output data register Address offset: 0x14

#define GPIOA_Mode_address 0x40020000 //GPIO port mode register Address offset: 0x00
#define GPIOA_Data_address 0x40020010 //GPIO port input data register Address offset: 0x10

int main(void)
{
  //To directly set a pointer to an address you have to (cast*) the address# to a pointer variable.
    uint32_t* RCC = (uint32_t*)RCC_address;
    uint32_t* GPIOD_Mode = (uint32_t*)GPIOD_Mode_address;
    uint32_t* GPIOD_Data = (uint32_t*)GPIOD_Data_address;
  //uint32_t* GPIOA_Mode = (uint32_t*)GPIOA_Data_address;//Default is INPUT;
    uint32_t* GPIOA_Data = (uint32_t*)GPIOA_Data_address;

  //RCC AHB1 peripheral clock enable register Enable GPIOD & GPIOA
    *RCC        |= (1<<3) | (1<<0);

  //Configure GPIOs
    *GPIOD_Mode |= (1<<24); //OUTPUT. Set MODER12 to 01: General purpose output mode.
  //*GPIOA_Mode |= (0<<0); //Default is 00 INPUT;

	while(1)
	{
		uint32_t readBit = (*GPIOA_Data & 0x0001);
		if(readBit == 1)*GPIOD_Data |= (1<<12);
		else *GPIOD_Data &= ~(1<<12);
	}
}
