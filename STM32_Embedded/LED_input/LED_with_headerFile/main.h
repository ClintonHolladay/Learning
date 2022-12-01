/*
 * main.h
 *
 *  Created on: Dec 1, 2022
 *      Author: Clinton Holladay
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

typedef struct//AHB1ENR peripheral clock enable register
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


typedef struct//GPIO MODE Data Register
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


typedef struct//IDR Input Data Register
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


typedef struct //ODR Input Data Register
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


#endif /* MAIN_H_ */
