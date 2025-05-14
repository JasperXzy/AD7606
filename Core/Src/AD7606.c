//
// Created by JasperXzy on 2025/5/14.
//

#include "stm32f1xx.h"
#include "AD7606.h"
#include "delay.h"

void GPIO_AD7606_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();

	HAL_GPIO_DeInit(GPIOA,GPIO_PIN_5);
	HAL_GPIO_DeInit(GPIOB, GPIO_PIN_3 |GPIO_PIN_4 |GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9);
	HAL_GPIO_DeInit(GPIOE,GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 |GPIO_PIN_5);

	// CS_N -> PE4			RD/SCLK -> PE5
	GPIO_InitStructure.Pin = GPIO_PIN_4 | GPIO_PIN_5;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);

	// FRSTDATA -> PE2		BUSY -> PE3
	GPIO_InitStructure.Pin = GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Mode = GPIO_MODE_EVT_RISING_FALLING;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);

	//	rst -> PB3
	//	convstB -> PB4
	//	convstA -> PB5
	//	STby -> PB6
	//	OS12 -> PB7
	//	OS11 -> PB8
	//	OS10 -> PB9
	GPIO_InitStructure.Pin = GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 ;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);

	// DoutA -> PA5
	GPIO_InitStructure.Pin = GPIO_PIN_5 ;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void AD7606_Init(void)
{
	convstA_Set;
	convstB_Set;
	STby_Set;
	clk_Set;
	cs_Set;
	OS10_Reset;
	OS11_Reset;
	OS12_Reset;
	AD7606_reset();
	AD7606_startconvst();
}

void AD7606_startconvst(void)
{
	convstA_Reset;
	convstB_Reset;
	delay_us(11);
	convstA_Set;
	convstB_Set;
}


void AD7606_reset(void)
{
	rst_Reset;
	delay_100ns();
	rst_Set;
	delay_us(1);
	rst_Reset;
}

void AD7606_read_data(int16_t * DB_data)
{
	uint8_t i,j;
	for(i=0; i<8; i++)
	{
		uint16_t DB_data1 = 0;
		cs_Reset;
		delay_us (3);
		for(j=0; j<16; j++)
		{
		clk_Reset;
		delay_us (4);
		DB_data1 = ((uint16_t)(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5))<< (15-j)) + DB_data1;
		clk_Set;
		delay_us (4);
		}
		cs_Set;
		DB_data[i] = (uint16_t)DB_data1;
	}
}
