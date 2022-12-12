/*
 * button.h
 *
 *  Created on: Nov 29, 2022
 *      Author: Linh
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

#define NUM_OF_BUTTONS	4

int isButtonPressed(int index);
void subKeyProcess(int index);
void clearButton();
void getKeyInput();

extern int button_flag[NUM_OF_BUTTONS];


#endif /* INC_BUTTON_H_ */
