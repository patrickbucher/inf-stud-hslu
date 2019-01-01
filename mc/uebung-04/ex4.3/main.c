/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include "ampel.h"

int main()
{
    for (;;) {
        printState();
        nextState();
    }

    return 0;
}
