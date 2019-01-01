/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdlib.h>
#include <stdio.h>

void nfibs(int *, int);

int main()
{
    int i, n, *fibs;

    printf("Anzahl Fibonacci-Zahlen: ");
    scanf("%d", &n);
    if (n < 1) {
        return 1;
    }

    fibs = (int *)malloc(sizeof(int) * (n + 1));
    if (fibs) {
        nfibs(fibs, n);
        for (i = 0; i < n; i++) {
            if (fibs[i] == -1) {
                // react on overflow
                break;
            }
            printf("f%d\t%10d\n", i, fibs[i]);
        }
        free(fibs);
    }

    return 0;
}

void nfibs(int *fibs, int n)
{
    int i;

    fibs[0] = 0;
    fibs[1] = 1;
    fibs[2] = 1;

    for (i = 3; i < n; i++) {
        fibs[i] = fibs[i-2] + fibs[i-1];
        if (fibs[i] < 0) {
            // handle overflow
            fibs[i] = -1;
            return;
        }
    }
}
