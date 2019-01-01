/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

char *itoa(int i);

int main()
{
    int numbers[] = {0, -3, 43, -123, 9383, -84983, 348761, -7365647, 84755847};
    char *s;
    int i;

    for (i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        s = itoa(numbers[i]);
        printf("%d = %s\n", numbers[i], s);
        free(s);
    }

    return 0;
}

char *itoa(int i)
{
    unsigned int length = 1, w = 0, mag, pos, digit, m, n;
    bool negative = false;
    char *result, tmp;

    if (i == 0) {
        result = malloc(sizeof(char) * 2);
        result [0] = '0';
        result [1] = '\0';
        return result;
    }

    if (negative = i < 0) {
        length++;
        i = abs(i);
    }
    length += (unsigned int)log10(i) + 1;

    result = (char*)malloc(sizeof(char) * length);

    result[w++] = '\0';
    for (mag = 10; i > 0; mag *= 10) {
        pos = (i % mag);
        digit = pos / (mag / 10);
        result[w++] = digit + '0';
        i -= pos;
    }

    if (negative) {
        result[w++] = '-';
    }

    for (m = 0, n = w-1; m < n; m++, n--) {
        tmp = result[m];
        result[m] = result[n];
        result[n] = tmp;
    }

    return result;
}
