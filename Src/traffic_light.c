/*
 * traffic_light.c
 *
 *  Created on: Dec 1, 2022
 *      Author: Linh
 */

#include "traffic_light.h"

void offAllLed() {
	HAL_GPIO_WritePin(LED1_0_GPIO_Port, LED1_0_Pin, RESET);
	HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, RESET);
	HAL_GPIO_WritePin(LED2_0_GPIO_Port, LED2_0_Pin, RESET);
	HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, RESET);
}

void setRED1Light() {
	HAL_GPIO_WritePin(LED1_0_GPIO_Port, LED1_0_Pin, SET);
	HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, RESET);
}

void setGREEN1Light() {
	HAL_GPIO_WritePin(LED1_0_GPIO_Port, LED1_0_Pin, RESET);
	HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, SET);
}

void setYELLOW1Light() {
	HAL_GPIO_WritePin(LED1_0_GPIO_Port, LED1_0_Pin, SET);
	HAL_GPIO_WritePin(LED1_1_GPIO_Port, LED1_1_Pin, SET);
}

void setRED2Light() {
	HAL_GPIO_WritePin(LED2_0_GPIO_Port, LED2_0_Pin, SET);
	HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, RESET);
}

void setGREEN2Light() {
	HAL_GPIO_WritePin(LED2_0_GPIO_Port, LED2_0_Pin, RESET);
	HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, SET);
}

void setYELLOW2Light() {
	HAL_GPIO_WritePin(LED2_0_GPIO_Port, LED2_0_Pin, SET);
	HAL_GPIO_WritePin(LED2_1_GPIO_Port, LED2_1_Pin, SET);
}

void setRED3Light() {
	HAL_GPIO_WritePin(LED3_0_GPIO_Port, LED3_0_Pin, SET);
	HAL_GPIO_WritePin(LED3_1_GPIO_Port, LED3_1_Pin, RESET);
}

void setGREEN3Light() {
	HAL_GPIO_WritePin(LED3_0_GPIO_Port, LED3_0_Pin, RESET);
	HAL_GPIO_WritePin(LED3_1_GPIO_Port, LED3_1_Pin, SET);
}

void toggleRED() {
	HAL_GPIO_TogglePin(LED1_0_GPIO_Port, LED1_0_Pin);
	HAL_GPIO_TogglePin(LED2_0_GPIO_Port, LED2_0_Pin);
}

void toggleGREEN() {
	HAL_GPIO_TogglePin(LED1_1_GPIO_Port, LED1_1_Pin);
	HAL_GPIO_TogglePin(LED2_1_GPIO_Port, LED2_1_Pin);
}

void toggleYELLOW() {
	HAL_GPIO_TogglePin(LED1_0_GPIO_Port, LED1_0_Pin);
	HAL_GPIO_TogglePin(LED1_1_GPIO_Port, LED1_1_Pin);
	HAL_GPIO_TogglePin(LED2_0_GPIO_Port, LED2_0_Pin);
	HAL_GPIO_TogglePin(LED2_1_GPIO_Port, LED2_1_Pin);
}

void pedestrianLight(int status) {
	if (status == AUTO_RED1_GREEN2 || status == MAN_RED1_GREEN2) {
		setGREEN3Light();
		setTimer4(0);
		setTimer6(TIME_INC_FOR_BUZZER);
	}

	else if (status == AUTO_RED1_YELLOW2 || status == MAN_RED1_YELLOW2) {
		setGREEN3Light();
	}

	else if (status == AUTO_YELLOW1_RED2 || status == MAN_YELLOW1_RED2) {
		setRED3Light();

	}

	else if (status == AUTO_GREEN1_RED2 || status == MAN_GREEN1_RED2) {
		setRED3Light();
	}
}

void turnOffPedestrianLight() {
	HAL_GPIO_WritePin(LED3_0_GPIO_Port, LED3_0_Pin, RESET);
	HAL_GPIO_WritePin(LED3_1_GPIO_Port, LED3_1_Pin, RESET);
}

void buzzer(int status) {
	if (status == AUTO_RED1_YELLOW2 || status == MAN_RED1_YELLOW2) {
		if (timer4_flag == 1) {
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, volumn);
			setTimer5(timeOn);
		}
		if (timer5_flag == 1) {
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);

			setTimer4(timeOn);
		}
		if (timer6_flag == 1) {
			setTimer6(TIME_INC_FOR_BUZZER);
			timeOn -= 100;
			volumn += 200;

			if (timeOn < 50) {
				timeOn = 50;
			}
		}
	} else {
		__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
	}
}
