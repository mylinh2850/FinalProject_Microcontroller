/*
 * fsm_automatic.c
 *
 *  Created on: Nov 29, 2022
 *      Author: Linh
 */

#include "fsm_automatic.h"

int pedesStatus = 0;
int flag = 0;

void fsm_automatic_run() {
	switch (status) {
	case INIT:
		//TODO
		timeDisplay = GREEN_TIME;
		status = AUTO_RED1_GREEN2;
		setTimer1(GREEN_TIME * 1000);

		setRED1Light();
		setGREEN2Light();

		setTimer7(1000);
		HAL_UART_Transmit(&huart2, (uint8_t*) strDisplay,
				sprintf(strDisplay, "!7SEG:%d%d#", timeDisplay / 10,
						timeDisplay % 10), 50);
		break;

	case AUTO_RED1_GREEN2:
		//TODO
		if (timer1_flag == 1) {
			timeDisplay = YELLOW_TIME;
			status = AUTO_RED1_YELLOW2;
			setTimer1(YELLOW_TIME * 1000);

			setRED1Light();
			setYELLOW2Light();
		}
		if (timer7_flag == 1) {
			setTimer7(1000);
			HAL_UART_Transmit(&huart2, (uint8_t*) strDisplay,
					sprintf(strDisplay, "!7SEG:%d%d#", timeDisplay / 10,
							timeDisplay % 10), 50);
			timeDisplay--;
		}
//if button 4 is pressed -> turn on the pedestrian light and control buzzer
		if (isButtonPressed(3) == 1) {
			pedesStatus = 1;
			volumn = VOLUMN;
			timeOn = BUZZER_DELAY_TIME;
			setTimer3(WAITING_TIME * 1000);
			pedestrianLight(status);
			buzzer(status);
		} else if (pedesStatus == 1 && timer3_flag == 0) {
			pedestrianLight(status);
			buzzer(status);
		} else {
			pedesStatus = 0;
			turnOffPedestrianLight();
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
		}

		//if button1 is pressed -> manual mode
		if (isButtonPressed(0) == 1) {
			status = INIT_MAN;
			setTimer2(WAITING_TIME * 1000);
		}
		break;

	case AUTO_RED1_YELLOW2:
		//TODO
		if (timer1_flag == 1) {
			timeDisplay = GREEN_TIME;
			status = AUTO_GREEN1_RED2;
			setTimer1(GREEN_TIME * 1000);

			setGREEN1Light();
			setRED2Light();
		}
		if (timer7_flag == 1) {
			setTimer7(1000);
			HAL_UART_Transmit(&huart2, (uint8_t*) strDisplay,
					sprintf(strDisplay, "!7SEG:%d%d#", timeDisplay / 10,
							timeDisplay % 10), 50);
			timeDisplay--;
		}

		if (isButtonPressed(3) == 1) {
			pedesStatus = 1;
			volumn = VOLUMN;
			timeOn = BUZZER_DELAY_TIME;
			setTimer3(WAITING_TIME * 1000);
			pedestrianLight(status);
			buzzer(status);
			flag = 1;
		} else if (pedesStatus == 1 && timer3_flag == 0) {
			if (flag == 1) {
				setTimer4(0);
				flag = 0;
			}
			pedestrianLight(status);
			buzzer(status);
		} else {
			pedesStatus = 0;
			turnOffPedestrianLight();
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
		}

		//if button1 is pressed -> manual mode
		if (isButtonPressed(0) == 1) {
			status = INIT_MAN;
			setTimer2(WAITING_TIME * 1000);
		}

		break;

	case AUTO_GREEN1_RED2:
		//TODO
		if (timer1_flag == 1) {
			timeDisplay = YELLOW_TIME;
			status = AUTO_YELLOW1_RED2;
			setTimer1(YELLOW_TIME * 1000);

			setYELLOW1Light();
			setRED2Light();
		}
		if (timer7_flag == 1) {
			setTimer7(1000);
			HAL_UART_Transmit(&huart2, (uint8_t*) strDisplay,
					sprintf(strDisplay, "!7SEG:%d%d#", timeDisplay / 10,
							timeDisplay % 10), 50);
			timeDisplay--;
		}

		if (isButtonPressed(3) == 1) {
			pedesStatus = 1;
			volumn = VOLUMN;
			timeOn = BUZZER_DELAY_TIME;
			setTimer3(WAITING_TIME * 1000);
			pedestrianLight(status);
			buzzer(status);
		} else if (pedesStatus == 1 && timer3_flag == 0) {
			pedestrianLight(status);
			buzzer(status);
		} else {
			pedesStatus = 0;
			turnOffPedestrianLight();
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
		}

		//if button1 is pressed -> manual mode
		if (isButtonPressed(0) == 1) {
			status = INIT_MAN;
			setTimer2(WAITING_TIME * 1000);
		}

		break;

	case AUTO_YELLOW1_RED2:
		//TODO
		if (timer1_flag == 1) {
			status = INIT;
		}

		if (isButtonPressed(3) == 1) {
			pedesStatus = 1;
			volumn = VOLUMN;
			timeOn = BUZZER_DELAY_TIME;
			setTimer3(WAITING_TIME * 1000);
			pedestrianLight(status);
			buzzer(status);
		} else if (pedesStatus == 1 && timer3_flag == 0) {
			pedestrianLight(status);
			buzzer(status);
		} else {
			pedesStatus = 0;
			turnOffPedestrianLight();
			__HAL_TIM_SetCompare (&htim3, TIM_CHANNEL_1, 0);
		}

		//if button1 is pressed -> manual mode
		if (isButtonPressed(0) == 1) {
			status = INIT_MAN;
			setTimer2(WAITING_TIME * 1000);
		}
		break;

	default:
		break;
	}
}

