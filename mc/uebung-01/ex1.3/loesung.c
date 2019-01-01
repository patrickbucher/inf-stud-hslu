/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int wert;

    printf("Wert als Integer (auch negativ): ");
    scanf("%d", &wert);

    if (wert < 0) {
        // display -13 as +12 with 0 for set bits
        wert = abs(wert) - 1;
        for (int i = sizeof(int) * 8; i > 0; i--) {
            if (wert & 1 << (i-1)) {
                putchar('0');
            } else {
                putchar('1');
            }
        }
    } else {
        for (int i = sizeof(int) * 8; i > 0; i--) {
            if (wert & 1 << (i-1)) {
                putchar('1');
            } else {
                putchar('0');
            }
        }
    }
    putchar('\n');

    return 0;
}
