#ifndef __SOFTWARE_TIMER_H__
#define __SOFTWARE_TIMER_H__



#define CLOCK_TICK 10

extern int timer_flag;

void timerRun();
void setTimer(int duration);

#endif