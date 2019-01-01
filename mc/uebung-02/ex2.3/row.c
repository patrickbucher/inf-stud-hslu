/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int *row(int from, int to, int step);

typedef struct {
    int from;
    int to;
    int step;
} rowdef;

int main()
{
    rowdef rows[] = {
        {1, 11, 1},
        {6, 61, 6},
        {10, 101, 10},
        {0, 101, 5},
        {1, 100, 4},
    };
    int *r, i, rd;

    for (rd = 0; rd < sizeof(rows)/sizeof(rows[0]); rd++) {
        r = row(rows[rd].from, rows[rd].to, rows[rd].step);
        if (r) {
            for (i = 0; r[i] != -1; i++) {
                printf("%d ", r[i]);
            }
            free(r);
        }
        putchar('\n');
    }
}

int *row(int from, int to, int step)
{
    int *r, n, i, x;

    if (from < 0 || to < 0 || step < 0) {
        return NULL;
    }
    if (to <= from) {
        return NULL;
    }

    n = ceil((to - from) / (float)step);
    if (n < 1) {
        return NULL;
    }

    n++; // terminator
    r = (int*)malloc(sizeof(int) * n);
    if (!r) {
        return NULL;
    }

    for (i = 0, x = from; x < to && i < n; x += step, i++) {
        r[i] = x;
    }
    r[i] = -1; // terminator

    return r;
}
