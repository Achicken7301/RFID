#include "scheduler.h"

vTask SCH_Tasks[SCH_MAX_TASK];

void SCH_Update()
{
    for (int i = 0; i < SCH_MAX_TASK; i++)
    {
        if (SCH_Tasks[i].pFn)
        {
            if (SCH_Tasks[i].delay == 0)
            {
                SCH_Tasks[i].flag += 1;
                if (SCH_Tasks[i].period)
                {
                    SCH_Tasks[i].delay = SCH_Tasks[i].period;
                }
            }
            else
            {
                SCH_Tasks[i].delay -= 1;
            }
        }
    }
}

void SCH_Dispatch()
{
    for (int i = 0; i < SCH_MAX_TASK; i++)
    {
        if (SCH_Tasks[i].flag > 0)
        {
            // Execute function
            // printf("Exe SCH_Tasks[%d].pFn\n", i);
            ((void (*)())SCH_Tasks[i].pFn)();
            SCH_Tasks[i].flag -= 1;

            if (SCH_Tasks[i].period == 0)
                SCH_Delete_Task(SCH_Tasks[i].pFn);
        }
    }
}

void SCH_Delete_Task(void *task)
{
    int i = 0;
    while (SCH_Tasks[i].pFn != task)
    {
        i++;
    }

    SCH_Tasks[i].pFn = 0x00;
    SCH_Tasks[i].flag = 0;
    SCH_Tasks[i].period = 0;
    SCH_Tasks[i].delay = 0;
}

void SCH_Add_Task(void *task, uint16_t delay, uint16_t period)
{
    // find .pFn is NULL
    uint8_t index = 0;
    while (SCH_Tasks[index].pFn)
    {
        index++;
    }

    // Found index in Task which is null, then add Task.
    SCH_Tasks[index].pFn = task;
    SCH_Tasks[index].delay = delay / CLOCK;
    SCH_Tasks[index].period = period / CLOCK;
    SCH_Tasks[index].flag = 0;

    // Found index in Task which is null, then add Task.
    // SCH_Tasks[index].pFn = task;
    // SCH_Tasks[index].delay = delay * CLOCK;
    // SCH_Tasks[index].period = period * CLOCK;
    // SCH_Tasks[index].flag = 0;
}
