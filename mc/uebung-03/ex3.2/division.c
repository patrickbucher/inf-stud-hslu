/**
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdbool.h>
#include <stdlib.h>
#include "division.h"

division *divide(int a, int b)
{
    division *div;

    div = (division *)malloc(sizeof(division));
    div->dividend = a;
    div->divisor= b;
    div->remainder = a % b;
    if (div->remainder) {
        div->quotient.floatingpoint = a / (float)b;
    } else {
        div->quotient.integer = a / b;
    }

    return div;
}
