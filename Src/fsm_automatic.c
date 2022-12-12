/*
 * fsm_automatic.c
 *
 *  Created on: Nov 29, 2022
 *      Author: Linh
 */

#include "fsm_automatic.h"

int pedesStatus = 0;
/*--------------------------------*/

//AUTO_RED		10
//AUTO_GREEN	01
//AUTO_YELLOW	11
/*--------------------------------*/

//Press button1 để chuyển từ mode auto -> manual -> tuning
//	Trong mode manual:
//		Press button1 để chuyển sang mode tuning
//		Press button2 để chuyển từ red1, green2 -> red1, yellow2 -> green1, red2 -> yellow1, red2 -> red1, green2
//		Trong 10s không bấm gì gì thì tự động quay về mode auto
//	Trong mode tuning:
//		Press button2 để chuyển từ thay đổi tgian đèn red -> green -> yellow
//		Press button3 để tăng tgian của đèn tương ứng
//		Press button1 để submit và chuyển về mode auto
//		Thay đổi tgian đèn nào thì blink đèn đó
/*--------------------------------*/

void fsm_automatic_run() {
	switch (status) {
	case INIT:
		//TODO
		status = AUTO_RED1_GREEN2;
		setTimer1(GREEN_TIME * 1000);
		setRED1Light();
		setGREEN2Light();
		break;

	case AUTO_RED1_GREEN2:
		//TODO
		if (timer1_flag == 1) {
			status = AUTO_RED1_YELLOW2;
			setTimer1(YELLOW_TIME * 1000);

			setRED1Light();
			setYELLOW2Light();
		}

//		//if button1 is pressed -> manual mode
//		if (isButtonPressed(0) == 1) {
//			status = INIT_MAN;
//			setTimer2(WAITING_TIME * 1000);
//		}
//
		break;

	case AUTO_RED1_YELLOW2:
		//TODO
		if (timer1_flag == 1) {
			status = AUTO_GREEN1_RED2;
			setTimer1(GREEN_TIME * 1000);

			setGREEN1Light();
			setRED2Light();
		}
//
//		//if button1 is pressed -> manual mode
//		if (isButtonPressed(0) == 1) {
//			status = INIT_MAN;
//			setTimer2(WAITING_TIME * 1000);
//		}
//
		break;

	case AUTO_GREEN1_RED2:
		//TODO
		if (timer1_flag == 1) {
			status = AUTO_YELLOW1_RED2;
			setTimer1(YELLOW_TIME * 1000);

			setYELLOW1Light();
			setRED2Light();
		}

//		//if button1 is pressed -> manual mode
//		if (isButtonPressed(0) == 1) {
//			status = INIT_MAN;
//			setTimer2(WAITING_TIME * 1000);
//		}
//
		break;

	case AUTO_YELLOW1_RED2:
		//TODO
		if (timer1_flag == 1) {
			status = AUTO_RED1_GREEN2;
			setTimer1(GREEN_TIME * 1000);

			setRED1Light();
			setGREEN2Light();
		}

//		//if button1 is pressed -> manual mode
//		if (isButtonPressed(0) == 1) {
//			status = INIT_MAN;
//			setTimer2(WAITING_TIME * 1000);
//		}
//
		break;

	default:
		break;
	}
}

