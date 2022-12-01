/*
 ******************************************************************************
 * @file           : main.c
 * @author         : Clinton Holladay
 * adding the new union/struct data structures to the LED file.
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

typedef union
{
	uint32_t rcc_ahb1enr; //AHB1ENR peripheral clock enable register
	struct
	{
		uint32_t gpioa_en       :1; //0: IO port clock disabled
		uint32_t gpiob_en       :1; //1: IO port clock enabled
		uint32_t gpioc_en       :1;
		uint32_t gpiod_en       :1;
		uint32_t gpioe_en       :1;
		uint32_t gpiof_en       :1;
		uint32_t gpiog_en       :1;
		uint32_t gpioh_en       :1;
		uint32_t gpioi_en       :1;
		uint32_t reserved_1     :3;
		uint32_t crc_en         :1;
		uint32_t reserved_2     :3;
		uint32_t reserved_3     :2;
		uint32_t bkpsram_en     :1;
		uint32_t reserved_4     :1;
		uint32_t ccmdataram_en  :1;
		uint32_t dma1_en        :1;
		uint32_t dma2_en        :1;
		uint32_t reserved_5     :2;
		uint32_t ethmac_en      :1;
		uint32_t ethmactx_en    :1;
		uint32_t ethmacrx_en    :1;
		uint32_t ethmacptp_en   :1;
		uint32_t otghs_en       :1;
		uint32_t otghsulpi_en   :1;
		uint32_t reserved_6     :1;
	}RCC_AHB1ENR_s;
}RCC_AHB1ENR_u;

typedef union
{
	uint32_t gpiox_moder; //GPIO MODE Data Register
	struct
	{
		uint32_t moder_0        :2; //00: Input (reset state)
		uint32_t moder_1        :2; //01: General purpose output mode
		uint32_t moder_2        :2; //10: Alternate function mode
		uint32_t moder_3        :2; //11: Analog mode
		uint32_t moder_4        :2;
		uint32_t moder_5        :2;
		uint32_t moder_6        :2;
		uint32_t moder_7        :2;
		uint32_t moder_8        :2;
		uint32_t moder_9        :2;
		uint32_t moder_10       :2;
		uint32_t moder_11       :2;
		uint32_t moder_12       :2;
		uint32_t moder_13       :2;
		uint32_t moder_14       :2;
		uint32_t moder_15       :2;
	}GPIOx_MODER_s;
}GPIOx_MODER_u;

typedef union
{
	uint32_t gpiox_idr; //IDR Input Data Register
	struct
	{
		uint32_t idr_0        :1; //READ ONLY
		uint32_t idr_1        :1;
		uint32_t idr_2        :1;
		uint32_t idr_3        :1;
		uint32_t idr_4        :1;
		uint32_t idr_5        :1;
		uint32_t idr_6        :1;
		uint32_t idr_7        :1;
		uint32_t idr_8        :1;
		uint32_t idr_9        :1;
		uint32_t idr_10       :1;
		uint32_t idr_11       :1;
		uint32_t idr_12       :1;
		uint32_t idr_13       :1;
		uint32_t idr_14       :1;
		uint32_t idr_15       :1;
		uint32_t reserved     :16;
	}GPIOx_IDR_s;
}GPIOx_IDR_u;

typedef union
{
	uint32_t gpiox_odr; //ODR Input Data Register
	struct
	{
		uint32_t odr_0        :1; //READ/WRITE
		uint32_t odr_1        :1; //1 -> HIGH
		uint32_t odr_2        :1; //0 -> LOW
		uint32_t odr_3        :1;
		uint32_t odr_4        :1;
		uint32_t odr_5        :1;
		uint32_t odr_6        :1;
		uint32_t odr_7        :1;
		uint32_t odr_8        :1;
		uint32_t odr_9        :1;
		uint32_t odr_10       :1;
		uint32_t odr_11       :1;
		uint32_t odr_12       :1;
		uint32_t odr_13       :1;
		uint32_t odr_14       :1;
		uint32_t odr_15       :1;
		uint32_t reserved     :16;
	}GPIOx_ODR_s;
}GPIOx_ODR_u;

int main(void)
{
	RCC_AHB1ENR_u clockRegister;
	GPIOx_MODER_u DmodeRegister;
	GPIOx_MODER_u AmodeRegister;
	GPIOx_IDR_u inputRegister;
	GPIOx_ODR_u outputRegister;

  //To directly set a pointer to an address you have to (cast*) the address# to a pointer variable.
    uint32_t volatile *const RCC = (uint32_t*)RCC_address;
    uint32_t volatile *const GPIOD_Mode = (uint32_t*)GPIOD_Mode_address;
    uint32_t volatile *const GPIOD_output = (uint32_t*)GPIOD_Data_address;
    uint32_t volatile *const GPIOA_Mode = (uint32_t*)GPIOA_Data_address;//Default is INPUT;
    uint32_t const volatile *const GPIOA_input = (uint32_t*)GPIOA_Data_address;

  //RCC AHB1 peripheral clock enable register Enable GPIOD & GPIOA
  //*RCC        |= (1<<3) | (1<<0);
    clockRegister.RCC_AHB1ENR_s.gpioa_en = 0x01;
    clockRegister.RCC_AHB1ENR_s.gpiod_en = 0x01;
    *RCC = clockRegister.rcc_ahb1enr;

  //Configure GPIOs
  //*GPIOD_Mode |= (1<<24); //OUTPUT. Set MODER12 to 01: General purpose output mode.
  //*GPIOA_Mode &= ~(3<<0); //Default is 00 INPUT;
    DmodeRegister.GPIOx_MODER_s.moder_12 = 0x01;
    *GPIOD_Mode = DmodeRegister.gpiox_moder;
    AmodeRegister.GPIOx_MODER_s.moder_0 = 0x00;
    *GPIOA_Mode = AmodeRegister.gpiox_moder;

	while(1)
	{
		//uint8_t readBit = (uint8_t)(*GPIOA_Data & 0x0001);
		inputRegister.gpiox_idr = *GPIOA_input;
		if(inputRegister.GPIOx_IDR_s.idr_0 == 1)
			{
				outputRegister.GPIOx_ODR_s.odr_12 = 0x01;
				*GPIOD_output = outputRegister.gpiox_odr;
				//*GPIOD_output |= (1<<12);
			}
		else
			{
				outputRegister.GPIOx_ODR_s.odr_12 = 0x00;
				*GPIOD_output = outputRegister.gpiox_odr;
				//*GPIOD_output &= ~(1<<12);
			}
	}
}
