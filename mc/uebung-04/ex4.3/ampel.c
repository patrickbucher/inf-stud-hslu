/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>
#include <unistd.h>
#include "ampel.h"

static state s = RED;

state getState()
{
    return s;
}

void nextState()
{
    switch (s) {
    case RED:
        sleep(5);
        s = YELLOW;
        break;
    case YELLOW:
        sleep(1);
        s = GREEN;
        break;
    case GREEN:
        sleep(2);
        s = GREEN_BLINKING;
        break;
    case GREEN_BLINKING:
        s = RED;
        sleep(1);
        break;
    }
    return;
}

void printState()
{
    switch (s) {
    case RED:
        puts("red");
        break;
    case YELLOW:
        puts("yellow");
        break;
    case GREEN:
        puts("green");
        break;
    case GREEN_BLINKING:
        puts("green blinking");
        break;
    }
}
