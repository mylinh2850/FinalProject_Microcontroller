/*
 * software_timer.c
 *
 *  Created on: Nov 29, 2022
 *      Author: Linh
 */

#include "software_timer.h"
#define TICK 10

int timer1_flag = 0;
int timer1_counter = 0;
int timer2_flag = 0;
int timer2_counter = 0;
int timer3_flag = 0;
int timer3_counter = 0;
int timer4_flag = 0;
int timer4_counter = 0;
int timer5_flag = 0;
int timer5_counter = 0;
int timer6_flag = 0;
int timer6_counter = 0;
int timer7_flag = 0;
int timer7_counter = 0;

void setTimer1(int duration) {
	timer1_counter = duration / TICK;
	timer1_flag = 0;
}

void setTimer2(int duration) {
	timer2_counter = duration / TICK;
	timer2_flag = 0;
}

void setTimer3(int duration) {
	timer3_counter = duration / TICK;
	timer3_flag = 0;
}

void setTimer4(int duration) {
	timer4_counter = duration / TICK;
	timer4_flag = 0;
}

void setTimer5(int duration) {
	timer5_counter = duration / TICK;
	timer5_flag = 0;
}

void setTimer6(int duration) {
	timer6_counter = duration / TICK;
	timer6_flag = 0;
}

void setTimer7(int duration) {
	timer7_counter = duration / TICK;
	timer7_flag = 0;
}

void timerRun() {
	if (timer1_counter > 0) {
		timer1_counter--;
	}
	if (timer1_counter <= 0) {
		timer1_flag++;
	}
	if (timer2_counter > 0) {
		timer2_counter--;
	}
	if (timer2_counter <= 0) {
		timer2_flag++;
	}
	if (timer3_counter > 0) {
		timer3_counter--;
	}
	if (timer3_counter <= 0) {
		timer3_flag++;
	}
	if (timer4_counter > 0) {
		timer4_counter--;
	}
	if (timer4_counter <= 0) {
		timer4_flag++;
	}
	if (timer5_counter > 0) {
		timer5_counter--;
	}
	if (timer5_counter <= 0) {
		timer5_flag++;
	}
	if (timer6_counter > 0) {
		timer6_counter--;
	}
	if (timer6_counter <= 0) {
		timer6_flag++;
	}
	if (timer7_counter > 0) {
		timer7_counter--;
	}
	if (timer7_counter <= 0) {
		timer7_flag++;
	}
}

void clearTimer1() {
	setTimer1(0);
}

