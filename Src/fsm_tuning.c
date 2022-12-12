/*
 * fsm_tuning.c
 *
 *  Created on: Dec 1, 2022
 *      Author: Linh
 */

#include "fsm_tuning.h"

void fsm_tuning_run() {
	switch (status) {
	case INIT_TUN:
		status = TUN_RED;
		offAllLed();
		toggleRED();
		break;

	case TUN_RED:
		//TODO
		//if button3 is pressed -> increase time of led red
		if (isButtonPressed(2) == 1) {
			RED_TIME++;
			if (RED_TIME > 99) {
				RED_TIME = 1;
			}
		}

		//if button2 is pressed -> case TUN_GREEN
		if (isButtonPressed(1) == 1) {
			status = TUN_GREEN;
			offAllLed();
			toggleGREEN();
		}

		//if button1 is pressed -> auto mode
		if (isButtonPressed(0) == 1) {
			status = INIT;
			setTimer1(GREEN_TIME);
		}
		break;

	case TUN_GREEN:
		//TODO
		//if button3 is pressed -> increase time of led green
		if (isButtonPressed(2) == 1) {
			GREEN_TIME++;
			if (GREEN_TIME > 99) {
				GREEN_TIME = 1;
			}
		}

		//if button2 is pressed -> case TUN_YELLOW
		if (isButtonPressed(1) == 1) {
			status = TUN_YELLOW;
			offAllLed();
			toggleYELLOW();
		}

		//if button1 is pressed -> auto mode
		if (isButtonPressed(0) == 1) {
			status = INIT;
			setTimer1(GREEN_TIME);
		}
		break;

	case TUN_YELLOW:
		//TODO
		//if button3 is pressed -> increase time of led yellow
		if (isButtonPressed(2) == 1) {
			YELLOW_TIME++;
			if (YELLOW_TIME > 99) {
				YELLOW_TIME = 1;
			}
		}

		//if button2 is pressed -> case TUN_RED
		if (isButtonPressed(1) == 1) {
			status = TUN_RED;
			offAllLed();
			toggleRED();
		}

		//if button1 is pressed -> auto mode
		if (isButtonPressed(0) == 1) {
			status = INIT;
			setTimer1(GREEN_TIME);
		}
		break;

	default:
		break;
	}
}
