/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>
#include <stdlib.h>
#include "debug.h"
#include "readline.h"

const int MAX_LINE_LENGTH = 80;

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
    printf("Total %d lines processed.\n", get_nlines());

    DEBUGPRINT("Program ends\n", NULL);

    return EXIT_SUCCESS;
}
