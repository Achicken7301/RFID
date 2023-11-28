#ifndef __SOFTWARE_TIMER_H__
#define __SOFTWARE_TIMER_H__

#include "stm32f10x_tim.h"

#define CLOCK_TICK 10

extern int timer_flag;

void timerRun();
void setTimer(int duration);

#endif