/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void PeripheralInit(void);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define FRSTDATA_Pin GPIO_PIN_2
#define FRSTDATA_GPIO_Port GPIOE
#define BUSY_Pin GPIO_PIN_3
#define BUSY_GPIO_Port GPIOE
#define CS_N_Pin GPIO_PIN_4
#define CS_N_GPIO_Port GPIOE
#define RD_SCLK_Pin GPIO_PIN_5
#define RD_SCLK_GPIO_Port GPIOE
#define DoutA_Pin GPIO_PIN_5
#define DoutA_GPIO_Port GPIOA
#define rst_Pin GPIO_PIN_3
#define rst_GPIO_Port GPIOB
#define convstB_Pin GPIO_PIN_4
#define convstB_GPIO_Port GPIOB
#define convstA_Pin GPIO_PIN_5
#define convstA_GPIO_Port GPIOB
#define STby_Pin GPIO_PIN_6
#define STby_GPIO_Port GPIOB
#define OS12_Pin GPIO_PIN_7
#define OS12_GPIO_Port GPIOB
#define OS11_Pin GPIO_PIN_8
#define OS11_GPIO_Port GPIOB
#define OS10_Pin GPIO_PIN_9
#define OS10_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
