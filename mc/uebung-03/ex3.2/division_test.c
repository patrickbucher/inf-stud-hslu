/**
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <assert.h>
#include <stdbool.h>
#include "division.h"

static division tests[] = {
    {10, 2, {.integer = 5}, false},
    {10, 3, {.floatingpoint = 10/3.0f}, true},
    {10, 4, {.floatingpoint = 10/4.0f}, true},
    {10, 5, {.integer = 2}, false},
};

void test_divide();

int main()
{
    test_divide();
    return 0;
}

void test_divide()
{
    int i;
    division d, *got;

    for (i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        d = tests[i];
        got = divide(d.dividend, d.divisor);
        assert(got->remainder == d.remainder);
        if (d.remainder) {
            assert(got->quotient.floatingpoint == d.quotient.floatingpoint);
        } else {
            assert(got->quotient.integer == d.quotient.integer);
        }
    }
}
