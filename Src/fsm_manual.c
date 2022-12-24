/*
 * fsm_manual.c
 *
 *  Created on: Nov 29, 2022
 *      Author: Linh
 */

#include "fsm_manual.h"

void fsm_manual_run() {
	switch (status) {
	case INIT_MAN:
		setRED1Light();
		setGREEN2Light();
		status = MAN_RED1_GREEN2;
		timeDisplay = WAITING_TIME;
		setTimer7(1000);
		HAL_UART_Transmit(&huart2, (uint8_t*) strDisplay,
				sprintf(strDisplay, "!7SEG:%d%d#", timeDisplay / 10,
						timeDisplay % 10), 50);
		break;

	case MAN_RED1_GREEN2:
		//TODO
		//if button1 is pressed -> case MAN_RED1_YELLOW2
		if (isButtonPressed(1) == 1) {
			status = MAN_RED1_YELLOW2;
			setTimer2(WAITING_TIME * 1000);

			setTimer7(1000);
			timeDisplay = WAITING_TIME;
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

		//if over 10s no button is pressed -> auto mode
		if (timer2_flag == 1) {
			status = INIT;
		}

		//if button 3 is pressed -> turn on the pedestrian light and control buzzer
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

		//if button0 is pressed -> tuning mode, turn off pedestrian light
		if (isButtonPressed(0) == 1) {
			status = INIT_TUN;
			turnOffPedestrianLight();
		}
		break;

	case MAN_RED1_YELLOW2:
		//TODO
		//if button1 is pressed -> case MAN_GREEN1_RED2
		if (isButtonPressed(1) == 1) {
			setTimer7(1000);
			timeDisplay = WAITING_TIME;
			status = MAN_GREEN1_RED2;
			setTimer2(WAITING_TIME * 1000);

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

		//if over 10s no button is pressed -> auto mode
		if (timer2_flag == 1) {
			status = INIT;
		}

		//if button3 is pressed -> turn on the pedestrian light and control buzzer
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

		//if button0 is pressed -> tuning mode, turn off pedestrian light
		if (isButtonPressed(0) == 1) {
			status = INIT_TUN;
			turnOffPedestrianLight();
		}
		break;

	case MAN_GREEN1_RED2:
		//TODO
		//if button1 is pressed -> case MAN_YELLOW1_RED2
		if (isButtonPressed(1) == 1) {
			setTimer7(1000);
			timeDisplay = WAITING_TIME;
			status = MAN_YELLOW1_RED2;
			setTimer2(WAITING_TIME * 1000);

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

		//if over 10s no button is pressed -> auto mode
		if (timer2_flag == 1) {
			status = INIT;
		}

		//if button3 is pressed -> turn on the pedestrian light and control buzzer
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

		//if button0 is pressed -> tuning mode, turn off pedestrian light
		if (isButtonPressed(0) == 1) {
			status = INIT_TUN;
			turnOffPedestrianLight();
		}
		break;

	case MAN_YELLOW1_RED2:
		//TODO
		//if button1 is pressed -> case MAN_RED1_GREEN2
		if (isButtonPressed(1) == 1) {
			setTimer7(1000);
			timeDisplay = WAITING_TIME;
			status = MAN_RED1_GREEN2;
			setTimer2(WAITING_TIME * 1000);

			setRED1Light();
			setGREEN2Light();
		}
		if (timer7_flag == 1) {
			setTimer7(1000);
			HAL_UART_Transmit(&huart2, (uint8_t*) strDisplay,
					sprintf(strDisplay, "!7SEG:%d%d#", timeDisplay / 10,
							timeDisplay % 10), 50);
			timeDisplay--;
		}

		//if over 10s no button is pressed -> auto mode
		if (timer2_flag == 1) {
			status = INIT;
		}

		//if button3 is pressed -> turn on the pedestrian light and control buzzer
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

		//if button0 is pressed -> tuning mode, turn off pedestrian light
		if (isButtonPressed(0) == 1) {
			status = INIT_TUN;
			turnOffPedestrianLight();
		}
		break;

	default:
		break;
	}
}

