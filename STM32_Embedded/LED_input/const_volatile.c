/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Clinton Holladay
 * Learning const and volatile.
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
    uint32_t volatile *const RCC = (uint32_t*)RCC_address;
    uint32_t volatile *const GPIOD_Mode = (uint32_t*)GPIOD_Mode_address;
    uint32_t volatile *const GPIOD_Data = (uint32_t*)GPIOD_Data_address;
    uint32_t volatile *const GPIOA_Mode = (uint32_t*)GPIOA_Data_address;//Default is INPUT;
    uint32_t const volatile *const GPIOA_Data = (uint32_t*)GPIOA_Data_address;
    //volatile stops the compiler from optimizing because the variable is subject to unexpected change
    //const prevents the programmer from being able to change the data but not the I/O peripherals

  //RCC AHB1 peripheral clock enable register Enable GPIOD & GPIOA
    *RCC        |= (1<<3) | (1<<0);

  //Configure GPIOs
    *GPIOD_Mode |= (1<<24); //OUTPUT. Set MODER12 to 01: General purpose output mode.
    *GPIOA_Mode &= ~(3<<0); //Default is 00 INPUT;

	while(1)
	{
		uint8_t readBit = (uint8_t)(*GPIOA_Data & 0x0001); // volatile tells compiler NOT to optimize this variable.
		if(readBit == 1)*GPIOD_Data |= (1<<12);
		else *GPIOD_Data &= ~(1<<12);
	}
}
