/*
 * button.c
 *
 *  Created on: Nov 29, 2022
 *      Author: Linh
 */

#include "button.h"

int KeyReg0[NUM_OF_BUTTONS] = { NORMAL_STATE };
int KeyReg1[NUM_OF_BUTTONS] = { NORMAL_STATE };
int KeyReg2[NUM_OF_BUTTONS] = { NORMAL_STATE };
int KeyReg3[NUM_OF_BUTTONS] = { NORMAL_STATE };
int button_flag[NUM_OF_BUTTONS] = { 0 };
int TimeOutForKeyPress[NUM_OF_BUTTONS];

int isButtonPressed(int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index) {
	button_flag[index] = 1;
}

void clearButton() {
	HAL_GPIO_WritePin(Button1_GPIO_Port, Button1_Pin, 0);
	HAL_GPIO_WritePin(Button2_GPIO_Port, Button2_Pin, 0);
	HAL_GPIO_WritePin(Button3_GPIO_Port, Button3_Pin, 0);
	HAL_GPIO_WritePin(Button4_GPIO_Port, Button4_Pin, 0);
}

void getKeyInput() {
	clearButton();
	for (int i = 0; i < NUM_OF_BUTTONS; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];

		if (i == 0) {
			KeyReg2[i] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
		} else if (i == 1) {
			KeyReg2[i] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
		} else if (i == 2) {
			KeyReg2[i] = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
		} else if (i == 3) {
			KeyReg2[i] = HAL_GPIO_ReadPin(Button4_GPIO_Port, Button4_Pin);
		}
		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg3[i] != KeyReg2[i]) {
				KeyReg3[i] = KeyReg2[i];

				if (KeyReg2[i] == PRESSED_STATE) {
					TimeOutForKeyPress[i] = 300;
					subKeyProcess(i);
				}
			} else {
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0) {
					if (KeyReg2[i] == PRESSED_STATE) {
						subKeyProcess(i);
					}
					TimeOutForKeyPress[i] = 100;
				}
			}
		}
	}
}

