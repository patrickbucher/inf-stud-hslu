/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>

// number of processed lines
static int nlines = 0;

int get_nlines()
{
    return nlines;
}

// read one line of input.
int readline(char s[], int limit)
{
    int i, c;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        // add line break character
        s[i++] = c;
    }
    s[i] = '\0';

    nlines++;

    return i;
}

// copy a string buffer
char *copy(char *dest, const char *from)
{
    char *save = dest;

    while (*dest++ = *from++);

    return save;
}
