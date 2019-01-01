/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

typedef enum {
    RED = 1,
    YELLOW = 2,
    GREEN = 3,
    GREEN_BLINKING = 4
} state;

state getState();
void nextState();
void printState();
