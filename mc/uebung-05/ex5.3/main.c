/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>
#include <unistd.h>
#include "semaphore.h"

int get_phase_time(semaphore_states);

int main(int argc, char **argv)
{
    set_semaphore_calback(get_phase_time);
    printf("Starting the semaphore...\n");
    start_semaphore();
    sleep(60);
    printf("Stopping the semaphore...\n");
    stop_semaphore();
    printf("Semaphore stopped...\n");

    return 0;
}

int get_phase_time(semaphore_states phase)
{
    int rc = 1;

    switch (phase) {
        case GREEN:
            rc = 6;
            break;
        case GREEN_BLINKING:
            rc = 2;
            break;
        case YELLOW:
            rc = 2;
            break;
        case RED:
            rc = 10;
            break;
        default:
            break;
    }
    return rc;
}
