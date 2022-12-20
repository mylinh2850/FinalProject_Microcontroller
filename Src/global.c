/*
 * global.c
 *
 *  Created on: Nov 29, 2022
 *      Author: Linh
 */

#include "global.h"

int RED_TIME = 10;
int GREEN_TIME = 6;
int YELLOW_TIME = 4;
int WAITING_TIME = 10;
int BUZZER_DELAY_TIME = 500;
int VOLUMN = 100;
int TIME_INC_FOR_BUZZER = 1000;

int status = INIT;
int volumn;
int timeOn;
int timeDisplay = 0;
char strDisplay[10] = "";
