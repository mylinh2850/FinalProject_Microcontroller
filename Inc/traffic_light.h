/*
 * traffic_light.h
 *
 *  Created on: Dec 1, 2022
 *      Author: Linh
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "global.h"

void offAllLed();

void setRED1Light();
void setGREEN1Light();
void setYELLOW1Light();

void setRED2Light();
void setGREEN2Light();
void setYELLOW2Light();

void toggleRED();
void toggleGREEN();
void toggleYELLOW();

void pedestrianLight(int status);
void turnOffPedestrianLight();
void buzzer(int status);

extern int flag;

#endif /* INC_TRAFFIC_LIGHT_H_ */
