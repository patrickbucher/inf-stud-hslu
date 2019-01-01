/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int readline(char *buf, int n)
{
    return freadline(stdin, buf, n);
}

int freadline(FILE *f, char *buf, int n)
{
    int i, c;

    if (n < 1 || !f) {
        return -1;
    }

    for (i = 0; i < (n - 1) && (c = fgetc(f)) != EOF && (char)c != '\n'; i++) {
        buf[i] = (char)c;
    }
    buf[i] = '\0';

    return i;
}

int stoi(char *buf, int n)
{
    int i, number;
    char c;

    for (i = 0, number = 0; i < n && (c = buf[i]) != '\0'; i++) {
        if (!isdigit(c)) {
            return -1;
        }
        number = number * 10 + (int)(c - '0');
    }

    return number;
}
