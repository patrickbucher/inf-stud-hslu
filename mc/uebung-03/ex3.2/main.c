/**
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "division.h"

int main()
{
    int a, b, n;
    division *div;

    for (;;) {
        printf("Dividend: ");
        n = scanf("%d", &a);
        if (a == 0 || n == -1) {
            break;
        }
        printf("Divisor:  ");
        n = scanf("%d", &b);
        if (b == 0 || n == -1) {
            break;
        }
        div = divide(a, b);
        printf("Resultat: ");
        if (div->remainder) {
            printf("%.3f\n", div->quotient.floatingpoint);
        } else {
            printf("%d\n", div->quotient.integer);
        }
        free(div);
    }

    return 0;
}
