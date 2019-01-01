/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "semaphore.h"

static int(*get_phase_time_function)(semaphore_states) = NULL;
static int thread_running = 0;
static semaphore_states state = RED;
static pthread_t thread_id;
static pthread_attr_t thread_attr;

void set_semaphore_calback(int (*phase_time_function)(semaphore_states))
{
    get_phase_time_function = phase_time_function;
}

static void print_thread_state(int sleep_time)
{
    char state_str[64];

    switch (state) {
        case GREEN:
            strcpy(state_str, "GREEN");
            break;
        case GREEN_BLINKING:
            strcpy(state_str, "GREEN BLINKING");
            break;
        case YELLOW:
            strcpy(state_str, "YELLOW");
            break;
        case RED:
            strcpy(state_str, "RED");
            break;
        default:
            strcpy(state_str, "UNDEFINED");
            break;
    }
    printf("The semaphore is %-14s for %2d seconds\n", state_str, sleep_time);
    fflush(stdout);
}

static void *thread_function(void *args)
{
    int sleep_time;

    while (thread_running) {
        switch (state) {
            case GREEN:
                state = GREEN_BLINKING;
                break;
            case GREEN_BLINKING:
                state = YELLOW;
                break;
            case YELLOW:
                state = RED;
                break;
            case RED:
                state = GREEN;
                break;
            default:
                state = RED;
                break;
        }
        if (get_phase_time_function != NULL) {
            sleep_time = get_phase_time_function(state);
        }
        print_thread_state(sleep_time);
        sleep(sleep_time);
    }
    printf("Semaphore thread stopped\n");

    return NULL;
}

void start_semaphore()
{
    thread_running = 1;
    pthread_attr_init(&thread_attr);
    pthread_create(&thread_id, &thread_attr, thread_function, NULL);
}

void stop_semaphore()
{
    thread_running = 0;
    pthread_join(thread_id, NULL);
    pthread_attr_destroy(&thread_attr);
}

