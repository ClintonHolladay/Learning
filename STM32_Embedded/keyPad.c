/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Clinton Holladay
 * key pad using direct bit manipulation
 ******************************************************************************
*/

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
                             //Address
#define RCC_address          (0x40023800 + 0x30) //RCC AHB1 peripheral clock register Address offset :0x30
#define GPIOD_Mode_address    0x40020C00         //GPIO port mode register Address offset            :0x00
#define GPIO_Reistor_address (0x40020C00 + 0x0C) //GPIO port PU/PDN register Address offset          :0x0C
#define GPIOD_Input_address  (0x40020C00 + 0x10) //GPIO port output data register Address offset     :0x10
#define GPIOD_Output_address (0x40020C00 + 0x14) //GPIO port output data register Address offset     :0x14

void delay();

int main(void)
{
	uint32_t volatile *const RCC       = (uint32_t*)RCC_address;
	uint32_t volatile *const D_Mode    = (uint32_t*)GPIOD_Mode_address;
	uint32_t volatile *const D_Reistor = (uint32_t*)GPIO_Reistor_address;
	uint32_t volatile *const D_Input   = (uint32_t*)GPIOD_Input_address;
	uint32_t volatile *const D_Output  = (uint32_t*)GPIOD_Output_address;


  //RCC AHB1 peripheral clock enable register Enable GPIOD
	*RCC |= (1<<3);

  //Configure GPIOs
	*D_Mode = 0x0;
	*D_Mode |= (1<<0) | (1<<2) | (1<<4) | (1<<6);

  //Configure Pullup resistors
	*D_Reistor |= (1<<16) | (1<<18) | (1<<20) | (1<<22);

	while(1)
	{
		uint8_t keyPress = 0;
		//Set outputs to HIGH
		*D_Output |= (1<<0) | (1<<1) | (1<<2) | (1<<3);

		//Check Row 1
		*D_Output &= ~(1<<0);
		keyPress = (uint8_t)((*D_Input >> 8) & 0x0F);
		switch(keyPress)
		{
			case 0x0E: delay(); printf("1\n"); break; //0b1110
			case 0x0D: delay(); printf("2\n"); break; //0b1101
			case 0x0B: delay(); printf("3\n"); break; //0b1011
			case 0x07: delay(); printf("A\n"); break; //0b0111
			default: break;
		}

		//Check Row 2
		*D_Output |= (1<<0);
		*D_Output &= ~(1<<1);
		keyPress = (uint8_t)((*D_Input >> 8) & 0x0F);
		switch(keyPress)
		{
			case 0x0E: delay(); printf("4\n"); break; //0b1110
			case 0x0D: delay(); printf("5\n"); break; //0b1101
			case 0x0B: delay(); printf("6\n"); break; //0b1011
			case 0x07: delay(); printf("B\n"); break; //0b0111
			default: break;
		}

		//Check Row 3
		*D_Output |= (1<<1);
		*D_Output &= ~(1<<2);
		keyPress = (uint8_t)((*D_Input >> 8) & 0x0F);
		switch(keyPress)
		{
			case 0x0E: delay(); printf("7\n"); break; //0b1110
			case 0x0D: delay(); printf("8\n"); break; //0b1101
			case 0x0B: delay(); printf("9\n"); break; //0b1011
			case 0x07: delay(); printf("C\n"); break; //0b0111
			default: break;
		}

		//Check Row 4
		*D_Output |= (1<<2);
		*D_Output &= ~(1<<3);
		keyPress = (uint8_t)((*D_Input >> 8) & 0x0F);
		switch(keyPress)
		{
			case 0x0E: delay(); printf(".\n"); break; //0b1110
			case 0x0D: delay(); printf("0\n"); break; //0b1101
			case 0x0B: delay(); printf("#\n"); break; //0b1011
			case 0x07: delay(); printf("D\n"); break; //0b0111
			default: break;
		}
	}
}

void delay()
{
	for(int i = 0; i < 300000; i++);
}
