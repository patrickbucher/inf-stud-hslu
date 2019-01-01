/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
#define DEBUGPRINT(_FMT, ...) \
    fprintf(stderr, "[file %s, line %d: " \
            _FMT, __FILE__, __LINE__, __VA_ARGS__)
#else
#define DEBUGPRINT(_fmt, ...)
#endif

// max line length
const int MAX_LINE_LENGTH = 80;

// number of processed lines
int nlines = 0;

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

// parses an input and returns the longest line
int main(int argc, char *argv[])
{
    int len, maxlen = 0;
    char line[MAX_LINE_LENGTH], maxline[MAX_LINE_LENGTH];

    DEBUGPRINT("Program starts\n", NULL);

    while ((len = readline(line, MAX_LINE_LENGTH)) > 0) {
        if (len > maxlen) {
            DEBUGPRINT("New longest line has %d characters:\n%s", len, line);
            maxlen = len;
            copy(maxline, line);
        }
    }

    if (maxlen > 0) {
        // there was a longest line
        printf("The longest line has %d characters:\n%s", maxlen, maxline);
    }
    printf("Total %d lines processed.\n", nlines);

    DEBUGPRINT("Program ends\n", NULL);

    return EXIT_SUCCESS;
}
