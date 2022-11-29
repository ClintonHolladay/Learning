/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Clinton Holladay
 * LED blink with software timer and bitwise XOR
 ******************************************************************************
*/

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define RCC_address        0x40023830
#define GPIOD_Mode_address 0x40020C00 //GPIO port mode register Address offset: 0x00
#define GPIOD_Data_address 0x40020C14
#define GPIOA_Mode_address 0x40020000 
#define GPIOA_Data_address 0x40020C14

int main(void)
{
  //To directly set a pointer to an address you have to (cast*) the address# to a pointer variable.
    uint32_t* RCC = (uint32_t*)RCC_address;
    uint32_t* GPIOD_Mode = (uint32_t*)GPIOD_Mode_address;
    uint32_t* GPIOD_Data = (uint32_t*)GPIOD_Data_address;

  //RCC AHB1 peripheral clock enable register (RCC_AHB1ENR) GPIODEN is the 3rd bit position
  //*RCC        |= 0b1000;
  //*RCC        |= 0x08;
    *RCC        |= (1<<3);

  //Clear GPIOD Mode register.
  //*GPIOD_Mode &= ~(0b00000011000000000000000000000000);
  //*GPIOD_Mode &  0xFCFFFFFF;
    *GPIOD_Mode &  ~(3<<24);

  //Configure GPIOD to OUTPUT. Set MODER12 to 01: General purpose output mode.
  //*GPIOD_Mode |= 0b00000001000000000000000000000000;
  //*GPIOD_Mode |= 0x01000000;
    *GPIOD_Mode |= (1<<24);

  //Set GPIOD port output data register (PIN 12) to HIGH.
  //*GPIOD_Data |= 0b0001000000000000;
  //*GPIOD_Data |= 0x1000;
    *GPIOD_Data |= (1<<12);

	while(1)
	{
		for(uint32_t i = 0; i < 1000000; i++)// Software timer delay
		{
			;
		}

		*GPIOD_Data ^= (1<<12);// Toggle the LED
		//*GPIOD_Data &= ~(1<<12); would work to just turn the LED off.
	}



}
