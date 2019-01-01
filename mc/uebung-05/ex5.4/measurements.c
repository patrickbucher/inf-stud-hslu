/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef enum {
    MEGA = 6,
    KILO = 3,
    ZERO = 0,
    MILLI = -3,
    MIKRO = -6
} metric_prefix;

typedef struct {
    float pressure;
    metric_prefix prefix;
} measurement;

measurement **random_measurements(int rows, int cols, metric_prefix prefix);
void print_measurements(measurement **m, int rows, int cols);

int main()
{
    int rows, cols, r, c;
    measurement **m;
    srand(time(NULL));

    rows = 4;
    cols = 3;
    m = random_measurements(rows, cols, KILO);
    print_measurements(m, rows, cols);

    return 0;
}

measurement **random_measurements(int rows, int cols, metric_prefix prefix)
{
    int r, c;
    measurement **m;

    m = (measurement **)malloc(rows * sizeof(measurement *));
    for (r = 0; r < rows; r++) {
        m[r] = (measurement *)malloc(cols * sizeof(measurement));
        for (c = 0; c < cols; c++) {
            m[r][c].pressure = rand() % 1000000 / 1000.0f;
            m[r][c].prefix = prefix;
        }
    }

    return m;
}

void print_measurements(measurement **m, int rows, int cols)
{
    int r, c;

    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            printf("%7.3f ", m[r][c].pressure);
            switch (m[r][c].prefix) {
                case MEGA:
                    printf("Mega");
                    break;
                case KILO:
                    printf("Kilo");
                    break;
                case MILLI:
                    printf("Milli");
                    break;
                case MIKRO:
                    printf("Mikro");
                    break;
                case ZERO:
                default:
                    break;
            }
            putchar(' ');
        }
        putchar('\n');
    }
}
