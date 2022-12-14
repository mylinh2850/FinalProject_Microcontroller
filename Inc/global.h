/*
 * global.h
 *
 *  Created on: Nov 29, 2022
 *      Author: Linh
 */
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#include "fsm_tuning.h"
#include "traffic_light.h"
#include "software_timer.h"


#define INIT 				100
#define AUTO_RED1_GREEN2	101
#define AUTO_RED1_YELLOW2	102
#define AUTO_GREEN1_RED2	103
#define AUTO_YELLOW1_RED2	104

#define INIT_MAN			200
#define MAN_RED1_GREEN2		201
#define MAN_RED1_YELLOW2	202
#define MAN_GREEN1_RED2		203
#define MAN_YELLOW1_RED2	204

#define INIT_TUN			300
#define TUN_RED				301
#define TUN_GREEN			302
#define TUN_YELLOW			303


extern int RED_TIME;
extern int GREEN_TIME;
extern int YELLOW_TIME;
extern int WAITING_TIME;
extern int BUZZER_DELAY_TIME;
extern int VOLUMN;

extern int volumn;
extern int timeOn;
extern int status;


#endif /* INC_GLOBAL_H_ */
