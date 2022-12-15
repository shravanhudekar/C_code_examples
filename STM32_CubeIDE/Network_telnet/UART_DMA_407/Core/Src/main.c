/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define TRUE 1
#define FALSE 0
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#define GETCHAR_PROTOTYPE int __io_getchar(void)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch,FILE *F)
#define GETCHAR_PROTOTYPE int fgets(FILE *f)
#endif
//#define TEST_IT
#define TELNET
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim6;

UART_HandleTypeDef huart2;
DMA_HandleTypeDef hdma_usart2_rx;
DMA_HandleTypeDef hdma_usart2_tx;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_TIM6_Init(void);
static void MX_USART2_UART_Init(void);
static void telnet_init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
typedef enum
{
	INIT = 0,
	START,
	AUTH,
	CONFIG,
	EXIT,
}UART_State_Machine;

#ifdef TEST_IT
uint8_t tx_buff[20]="Ready to Receive\n\r";
uint8_t rx_data;
uint8_t rx_buff[20];
uint8_t i=0;
#endif

#ifdef TELNET
uint8_t *user[]={"admin", "adam1","user1","test1"};
uint8_t *pass[]={"12345","54321","USER1","TEST1"};
uint8_t input[20],erase[4];
uint8_t input_user[10];
uint8_t input_pass[10];
uint8_t stage=INIT,flag=FALSE;
uint8_t rx_data,j=0,recieved=FALSE,count=0;
#endif
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM6_Init();
  MX_USART2_UART_Init();

  /* USER CODE BEGIN 2 */
#ifdef TEST_IT
  HAL_UART_Transmit(&huart2, tx_buff, sizeof(tx_buff), 50);
  HAL_UART_Receive_DMA(&huart2, rx_buff, 20);
  /* USER CODE END 2 */
#endif

#ifdef TELNET
  printf("*********************************************\r\n"
		 "*     Telnet connection started....         *\r\n "
		 "*********************************************\r\n");
  telnet_init();
#endif
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

#ifdef TELNET

	  if(stage==INIT)
	  {
		  telnet_init();
	  }
#endif
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 84;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 65535;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 19200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable IT controller clock
  */
static void MX_DMA_Init(void)
{

  /* IT controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* IT interrupt init */
  /* IT1_Stream5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
  /* IT1_Stream6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PD12 PD13 PD14 PD15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

PUTCHAR_PROTOTYPE
{  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY); return ch; }

GETCHAR_PROTOTYPE
{ 	uint8_t ch = 0;
/* Clear the Overrun flag just before receiving the first character */
	__HAL_UART_CLEAR_OREFLAG(&huart2);
	HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
	return ch;
}
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
#ifdef TEST_IT
//	if(rx_data != '\r' || (i>sizeof(rx_buff)))
//	{
//		rx_buff[i]=rx_data;
//		i++;
//	}
//	else
//	{
//		i=0;
		memset(rx_buff,0,sizeof(rx_buff));
		sprintf(tx_buff,"\n\rData Received\r\n");
		HAL_UART_Transmit(&huart2, tx_buff, sizeof(tx_buff),50);
		HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
//	}
	HAL_UART_Receive_DMA(&huart2, &rx_data, 1);
//	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
#endif

#ifdef TELNET

	if(rx_data == '\b' && j>0)
		{
			input[j]=0;
			j=j-2;
			sprintf(erase," \b");
			HAL_UART_Transmit(&huart2, erase, sizeof(erase), 50);
			memset(erase,0,sizeof(erase));
			rx_data=0;
		}

	if((rx_data != '\r') || j>(sizeof(input)) )
		{
			input[j]=rx_data;
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
			HAL_UART_Receive_DMA(&huart2,&rx_data, 1);

			j++;
		}

	else
	{
		recieved=TRUE;
		//printf("\r\n");
	}
	if(recieved)
	{
		switch(stage)
			{
				case START:
//					if(strcmp(input,"telnet"))
//					{
//						telnet_init();
//					}

					if(strlen(input)>8)
					{
						printf("input out of range!!\r\n");
					}
					else
					{
						memcpy(input_user,input,strlen(input));
						memset(input,0,sizeof(input));
						//printf("\n\rPassword: ");
						sprintf(input,"\n\rPassword: ");
						HAL_UART_Transmit(&huart2, input, sizeof(input), 50);
						memset(input,0,sizeof(input));
						stage=AUTH;
						HAL_UART_Receive_DMA(&huart2,&rx_data, 1);
						rx_data=0;
						j=0;
						recieved=FALSE;
					}
					break;

				case AUTH:
					if(strlen(input)>8)
					{
						printf("input out of range!!\r\n");
					}

					else
					{
						memcpy(input_pass,input,strlen(input));
						memset(input,0,sizeof(input));

						for(uint8_t i=0;i<4;i++)
						{
							if((strcmp(*(user+i),input_user)==0) && (strcmp(*(pass+i),input_pass)==0))
							{
								printf("\r\nSuccessfully Authenticated!\r\n");
								//printf("Config> ");
								sprintf(input,"\r\nConfig> ");
								HAL_UART_Transmit(&huart2, input, sizeof(input), 50);
								memset(input,0,sizeof(input));
								HAL_UART_Receive_DMA(&huart2,&rx_data, 1);
										rx_data=0;
										j=0;
										recieved=FALSE;
								flag=TRUE;
								stage=CONFIG;
								break;
							}
						}

						if(!flag)
						{
							stage=INIT;
							flag=FALSE;
							count++;
							j=0;

							if(count>3)
							{
								printf("\r\nlogin attempt excedded!!\r\n");
								stage=EXIT;
							}
						}
					}
						memset(input,0,sizeof(input));
						break;


				case CONFIG:
					if(strcmp(input,"exit")==0 ||  strcmp(input,"Z")==0 )
					{
						printf("\r\nsession ended!!\r\n");
						HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
						stage=EXIT;
					}
					else
					{

						if(strcmp(input,"turn ON LED")==0)
						{
							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
							printf("\r\nLED turned ON...\r\n");
						}

						else if(strcmp(input,"turn OFF LED")==0)
						{
							HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
							printf("\r\nLED turned OFF...\r\n");
						}

						else
						{
							printf("\r\ninput is invalid\r\n");
						}

						//printf("Config> ");
						memset(input,0,sizeof(input));
						sprintf(input,"\r\nConfig> ");
						HAL_UART_Transmit(&huart2, input, sizeof(input), 50);
						memset(input,0,sizeof(input));
						HAL_UART_Receive_DMA(&huart2,&rx_data, 1);
										recieved=FALSE;
										rx_data=0;
										j=0;
					}
					memset(input,0,sizeof(input));
					break;

				case EXIT:
					HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
					HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);

					memset(input,0,sizeof(input));
					HAL_UART_Receive_DMA(&huart2,&rx_data, 1);
									recieved=FALSE;
									rx_data=0;
									j=0;

					break;
			}
	}

	else
	{
		HAL_UART_Receive_DMA(&huart2,&rx_data, 1);
		recieved=FALSE;
	}


#endif

}
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
	huart->ErrorCode;
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_ErrorCallback could be implemented in the user file
   */
}

#ifdef TELNET
static void telnet_init(void)
  {
	  sprintf(input,"\r\nUsername: ");
	  HAL_UART_Transmit(&huart2, input, sizeof(input), 50);
	  stage=START;
	  flag=FALSE;
	  rx_data=0;
	  recieved=FALSE;

	  memset(input,0,sizeof(input));
	  memset(input_user,0,sizeof(input_user));
	  memset(input_pass,0,sizeof(input_pass));
	  HAL_UART_Receive_DMA(&huart2,&rx_data, 1);
  }
#endif
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM1 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/