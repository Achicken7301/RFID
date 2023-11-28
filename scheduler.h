#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include <stdint.h>

/**
 * @brief This Scheduler with O(n) complexity
 * @Todo: Make this to O(1)
 *
 */

#define CLOCK 10

typedef struct
{
    void *pFn;
    uint16_t delay;
    uint16_t period;
    uint8_t flag;
} vTask;

#define SCH_MAX_TASK 10



void SCH_Update();
void SCH_Dispatch();
void SCH_Add_Task(void *task, uint16_t delay, uint16_t period);
void SCH_Delete_Task(void *task);
void SCH_status();
#endif