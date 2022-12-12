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
		break;

	case MAN_RED1_GREEN2:
		//TODO
		//if button2 is pressed -> case MAN_RED1_YELLOW2
		if (isButtonPressed(1) == 1) {
			status = MAN_RED1_YELLOW2;
			setTimer2(WAITING_TIME * 1000);

			setRED1Light();
			setYELLOW2Light();
		}

		//if over 10s no button is pressed -> auto mode
		if (timer2_flag == 1) {
			status = AUTO_RED1_GREEN2;
		}

		//if button1 is pressed -> tuning mode, turn off pedestrian light
		if (isButtonPressed(0) == 1) {
			status = INIT_TUN;
			turnOffPedestrianLight();
		}
		break;

	case MAN_RED1_YELLOW2:
		//TODO
		//if button2 is pressed -> case MAN_GREEN1_RED2
		if (isButtonPressed(1) == 1) {
			status = MAN_GREEN1_RED2;
			setTimer2(WAITING_TIME * 1000);

			setGREEN1Light();
			setRED2Light();
		}

		//if over 10s no button is pressed -> auto mode
		if (timer2_flag == 1) {
			status = AUTO_RED1_GREEN2;
		}

		//if button1 is pressed -> tuning mode, turn off pedestrian light
		if (isButtonPressed(0) == 1) {
			status = INIT_TUN;
			turnOffPedestrianLight();
		}
		break;

	case MAN_GREEN1_RED2:
		//TODO
		//if button2 is pressed -> case MAN_YELLOW1_RED2
		if (isButtonPressed(1) == 1) {
			status = MAN_YELLOW1_RED2;
			setTimer2(WAITING_TIME * 1000);

			setYELLOW1Light();
			setRED2Light();
		}

		//if over 10s no button is pressed -> auto mode
		if (timer2_flag == 1) {
			status = AUTO_RED1_GREEN2;
		}

		//if button1 is pressed -> tuning mode, turn off pedestrian light
		if (isButtonPressed(0) == 1) {
			status = INIT_TUN;
			turnOffPedestrianLight();
		}
		break;

	case MAN_YELLOW1_RED2:
		//TODO
		//if button2 is pressed -> case MAN_RED1_GREEN2
		if (isButtonPressed(1) == 1) {
			status = MAN_RED1_GREEN2;
			setTimer2(WAITING_TIME * 1000);

			setRED1Light();
			setGREEN2Light();
		}

		//if over 10s no button is pressed -> auto mode
		if (timer2_flag == 1) {
			status = AUTO_RED1_GREEN2;
		}

		//if button1 is pressed -> tuning mode, turn off pedestrian light
		if (isButtonPressed(0) == 1) {
			status = INIT_TUN;
			turnOffPedestrianLight();
		}
		break;

	default:
		break;
	}
}

