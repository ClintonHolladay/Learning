/*
 * stm32f407g.h
 *
 *  Created on: Apr 10, 2024
 *      Author: C. Holladay
 */

#ifndef INC_STM32F407G_H_
#define INC_STM32F407G_H_

#include <stdint.h>

// Base Address MACROs

#define FLASH_BASEADDR				0x08000000U
#define SRAM         				0x20000000U // 112KB
#define SRAM2        				0x2001C000U // 16KB (after SRAM1) ends at 0x2001FFFF
#define ROM_BASEADDR				0x1FFF0000U // OTP area (One-Time Programmable) (ROM)

// Bus Base Addresses

#define APB1_BASEADDR				0x40000000U // Advanced Peripheral Bus 1
#define APB2_BASEADDR				0x40010000U // Advanced Peripheral Bus 2
#define AHB1_BASEADDR				0x40020000U // Advanced High Performance Bus 1
#define AHB2_BASEADDR				0x50000000U // Advanced High Performance Bus 2
#define AHB3_BASEADDR				0xA0000000U // Advanced High Performance Bus 3

// AHB1 Peripheral Base Addresses for GPIO

#define GPIOA_BASEADDR				0x40020000U
#define GPIOB_BASEADDR				0x40020400U
#define GPIOC_BASEADDR				0x40020800U
#define GPIOD_BASEADDR				0x40020C00U
#define GPIOE_BASEADDR				0x40021000U
#define GPIOF_BASEADDR				0x40021400U
#define GPIOG_BASEADDR				0x40021800U
#define GPIOH_BASEADDR				0x40021C00U
#define GPIOI_BASEADDR				0x40022000U
#define RCC_BASEADDR				0x40023800U

// APB1 Peripheral Base Addresses

#define I2C1_BASEADDR				0x40005400U
#define I2C2_BASEADDR				0x40005800U
#define I2C3_BASEADDR				0x40005C00U
#define SPI2_BASEADDR				0x40003800U
#define SPI3_BASEADDR				0x40003C00U
#define UART5_BASEADDR				0x40005000U
#define UART4_BASEADDR				0x40004C00U
#define USART3_BASEADDR				0x40004800U
#define USART2_BASEADDR				0x40004400U

// APB2 Peripheral Base Addresses

#define EXTI_BASEADDR				0x40013C00U
#define SPI1_BASEADDR	 			0x40013000U
#define USART1_BASEADDR				0x40011000U
#define USART6_BASEADDR				0x40011400U
#define SYSCFG_BASEADDR				0x40013800U

// Structures to hold GPIO registers

typedef struct
{
	volatile uint32_t MODER;		//GPIO port mode register
	volatile uint32_t OTYPER;		//GPIO port output type register
	volatile uint32_t OSPEEDR;		//GPIO port output speed register
	volatile uint32_t PUPDR;		//GPIO port pull-up/pull-down register
	volatile uint32_t IDR;			//GPIO port input data register
	volatile uint32_t ODR;			//GPIO port output data register
	volatile uint32_t BSRR;			//GPIO port bit set/reset register
	volatile uint32_t LCKR;			//GPIO port configuration lock register
	volatile uint32_t AFRL;			//GPIO alternate function low register
	volatile uint32_t AFRH;			//GPIO alternate function high register
}; GPIO_RegDef_t;

// GPIO_RegDef_t MACROs

#define GPIOA						((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB						((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC						((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD						((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE						((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF						((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG						((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH						((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI						((GPIO_RegDef_t*)GPIOI_BASEADDR)

// RCC Reset Clock Control Register

typedef struct
{
	volatile uint32_t RCC_CR;		//RCC clock control register
	volatile uint32_t PLLCFGR;		//RCC PLL configuration register
	volatile uint32_t CFGR;			//RCC clock configuration register
	volatile uint32_t CIR;			//RCC clock interrupt register
	volatile uint32_t AHB1RSTR;		//RCC AHB1 peripheral reset register
	volatile uint32_t AHB2RSTR;		//RCC AHB2 peripheral reset register
	volatile uint32_t AHB3RSTR;		//RCC AHB3 peripheral reset register
	volatile uint32_t Reserved1;
	volatile uint32_t APB1RSTR;		//RCC APB1 peripheral reset register
	volatile uint32_t APB2RSTR;		//RCC APB2 peripheral reset register
	volatile uint32_t Reserved2;
	volatile uint32_t Reserved3;
	volatile uint32_t AHB1ENR;		//RCC AHB1 peripheral clock register
	volatile uint32_t AHB2ENR;		//RCC AHB2 peripheral clock enable register
	volatile uint32_t AHB3ENR;		//RCC AHB3 peripheral clock enable register
	volatile uint32_t Reserved4;
	volatile uint32_t APB1ENR;		//RCC APB1 peripheral clock enable register
	volatile uint32_t APB2ENR;		//RCC APB2 peripheral clock enable register
	volatile uint32_t Reserved5;
	volatile uint32_t Reserved6;
	volatile uint32_t AHB1LPENR;	//RCC AHB1 peripheral clock enable in low power mode register
	volatile uint32_t AHB2LPENR;	//RCC AHB2 peripheral clock enable in low power mode register
	volatile uint32_t AHB3LPENR;	//RCC AHB3 peripheral clock enable in low power mode register
	volatile uint32_t Reserved7;
	volatile uint32_t APB1LPENR;	//RCC APB1 peripheral clock enable in low power mode register
	volatile uint32_t APB2LPENR;	//RCC APB2 peripheral clock enabled in low power mode register
	volatile uint32_t Reserved8;
	volatile uint32_t Reserved9;
	volatile uint32_t BDCR;			//RCC Backup domain control register
	volatile uint32_t CSR;			//RCC clock control & status register
	volatile uint32_t Reserved10;
	volatile uint32_t Reserved11;
	volatile uint32_t SSCGR;		//RCC spread spectrum clock generation register
	volatile uint32_t PLLI2SCFGR; 	//RCC PLLI2S configuration register
}; RCC_RegDef_t;

// RCC_RegDef_t MACROs

#define RCC							((RCC_RegDef_t*)RCC_BASEADDR)

// GPIOx Clock Enable MACROs

#define GPIOA_PCLK_EN()				(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()				(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()				(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()				(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()				(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()				(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()				(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()				(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()				(RCC->AHB1ENR |= (1 << 8))

// I2Cx Clock Enable MACROs

#define I2C1_PCLK_EN()				(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()				(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()				(RCC->APB1ENR |= (1 << 23))

// SPIx Clock Enable MACROs

#define SPI1_PCLK_EN()				(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()				(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()				(RCC->APB1ENR |= (1 << 15))

// USARTx Clock Enable MACROs

#define USART1_PCLK_EN()				(RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()				(RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()				(RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN()					(RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()					(RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN()				(RCC->APB2ENR |= (1 << 5))

// SYSCFGx Clock Enable MACROs

#define SYSCFG_PCLK_EN()				(RCC->AHB2ENR |= (1 << 14))

// GPIOx Clock Disable MACROs

#define GPIOA_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 7))
#define GPIOI_PCLK_DI()				(RCC->AHB1ENR &= ~(1 << 8))

// I2Cx Clock Disable MACROs

#define I2C1_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 23))

// SPIx Clock Disable MACROs

#define SPI1_PCLK_DI()				(RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 15))

// USARTx Clock Disable MACROs

#define USART1_PCLK_DI()				(RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()				(RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DI()					(RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI()					(RCC->APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DI()				(RCC->APB2ENR &= ~(1 << 5))

// SYSCFGx Clock Disable MACROs

#define SYSCFG_PCLK_DI()				(RCC->AHB2ENR &= ~(1 << 14))


#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET 			DISABLE




#endif /* INC_STM32F407G_H_ */
