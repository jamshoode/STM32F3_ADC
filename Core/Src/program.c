/*
 * program.c
 *
 *  Created on: Apr 22, 2025
 *      Author: vakalama
 */
#include "main.h"
#include <stdio.h>

extern ADC_HandleTypeDef hadc1;

void program(void)
{
	uint32_t value_adc;

	HAL_ADCEx_Calibration_Start(&hadc1, ADC_SINGLE_ENDED);

	while(1)
	{
		HAL_ADC_Start(&hadc1);
        HAL_ADC_PollForConversion(&hadc1, 1000);

		HAL_GPIO_TogglePin(GPIOE, LD4_Pin);
		value_adc = (uint32_t)HAL_ADC_GetValue(&hadc1);
		HAL_Delay(value_adc);

        HAL_ADC_Stop(&hadc1);
	}
}
