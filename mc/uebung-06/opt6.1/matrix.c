/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

double **create_matrix(int rows, int cols, int argc, double init, ...);

int main()
{
    double **m;
    int rows, cols, r, c;

    rows = 8;
    cols = 8;
    m = create_matrix(rows, cols, 6, 1.11, 2.22, 3.33, 4.44, 5.55, 6.66);
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            printf("%4.2f ", m[r][c]);
        }
        putchar('\n');
    }

    for (r = 0; r < rows; r++) {
        free(m[r]);
    }
    free(m);

    return 0;
}

double **create_matrix(int rows, int cols, int argc, double init, ...)
{
    double **matrix;
    va_list argp;
    int r, c;

    if (argc > 0) {
        va_start(argp, init);
        argc--;
    } else {
        init = 0.0;
    }
    matrix = (double **)malloc(sizeof(double *) * rows);
    for (r = 0; r < rows; r++) {
        matrix[r] = (double *)malloc(sizeof(double) * cols);
        for (c = 0; c < cols; c++) {
            matrix[r][c] = init;
            if (argc > 0) {
                init = va_arg(argp, double);
                argc--;
            } else {
                init = 0.0;
            }
        }
    }
    va_end(argp);

    return matrix;
}
