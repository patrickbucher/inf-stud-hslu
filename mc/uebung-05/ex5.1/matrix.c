/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdlib.h>
#include <stdio.h>

int **create_matrix(int rows, int cols, int value);

int main()
{
    int **m;
    int rows, cols, r, c;

    rows = 40;
    cols = 80;
    m = create_matrix(rows, cols, 0);
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            printf("%d ", m[r][c]);
        }
        putchar('\n');
    }

    for (r = 0; r < rows; r++) {
        free(m[r]);
    }
    free(m);

    return 0;
}

int **create_matrix(int rows, int cols, int value)
{
    int **matrix;
    int r, c;

    matrix = (int **)malloc(sizeof(int *) * rows);
    for (r = 0; r < rows; r++) {
        matrix[r] = (int *)malloc(sizeof(int) * cols);
        for (c = 0; c < cols; c++) {
            matrix[r][c] = value;
        }
    }

    return matrix;
}
