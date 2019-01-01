/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>

#define MIN(_X, _Y) (((_X) > (_Y)) ? (_Y) : (_X))
#define MAX(_X, _Y) (((_X) > (_Y)) ? (_X) : (_Y))
#define SWAP(_T, _X, _Y) _T = _X; _X = _Y; _Y = _T;
#define DEBUGPRINT(_FMT, ...) \
    fprintf(stderr, "[file %s, line %d]: " \
            _FMT, __FILE__, __LINE__, __VA_ARGS__)

int main()
{
    int t = 0, x = 3, y = 5;

    printf("MIN(%d, %d) = %d\n", x, y, MIN(x, y));
    printf("MAX(%d, %d) = %d\n", x, y, MAX(x, y));
    DEBUGPRINT("before SWAP: t=%d, x=%d, y=%d\n", t, x, y);
    SWAP(t, x, y);
    DEBUGPRINT("after SWAP:  t=%d, x=%d, y=%d\n", t, x, y);

    return 0;
}
