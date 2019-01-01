/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#ifndef _SEMAPHORE_H
#define _SEMAPHORE_H

typedef enum {
    GREEN = 1,
    GREEN_BLINKING,
    YELLOW,
    RED
} semaphore_states;

void set_semaphore_calback(int (*f)(semaphore_states));
void start_semaphore();
void stop_semaphore();

#endif
