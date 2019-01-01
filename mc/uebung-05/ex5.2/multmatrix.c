/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>
#include <stdlib.h>

int **mult_matrix(int n);

int main()
{
    int **m;
    int n, r, c;

    n = 10;
    m = mult_matrix(n);
    for (r = 0; r < n; r++) {
        for (c = 0; c < n; c++) {
            printf("%3d ", m[r][c]);
        }
        putchar('\n');
    }

    for (r = 0; r < n; r++) {
        free(m[r]);
    }
    free(m);

    return 0;
}

int **mult_matrix(int n)
{
    int **m;
    int r, c;

    m = (int **)malloc(sizeof(int *) * n);
    for (r = 0; r < n; r++) {
        m[r] = (int *)malloc(sizeof(int) * n);
        for (c = 0; c < n; c++) {
            if (c == 0) {
                m[r][c] = r + 1;
            } else if (r == 0) {
                m[r][c] = c + 1;
            } else {
                m[r][c] = (r + 1) * (c + 1);
            }
        }
    }

    return m;
}
