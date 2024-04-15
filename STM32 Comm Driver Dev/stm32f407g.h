/*
 * stm32f407g.h
 *
 *  Created on: Apr 10, 2024
 *      Author: C. Holladay
 */

#ifndef INC_STM32F407G_H_
#define INC_STM32F407G_H_

// Base Address MACROs

#define FLASH_BASEADDR				0x08000000U
#define SRAM         				0x20000000U // 112KB
#define SRAM2        				0x2001C000U // 16KB (after SRAM1) ends at 0x2001FFFF
#define ROM_BASEADDR				0x1FFF0000U // OTP area (Oone-Time Programmable) (ROM)

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
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
}; GPIO_RegDef_t;

#define GPIOA				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF				((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG				((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH				((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI				((GPIO_RegDef_t*)GPIOI_BASEADDR)

#endif /* INC_STM32F407G_H_ */
