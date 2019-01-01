/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdlib.h>
#include <stdio.h>

void readline(char *, int);
char *mystrcat(char *, char *);

const int inputsize = 128;

int main()
{
    int i;
    char a[inputsize], b[inputsize], *str;

    printf("Zeichenkette 1: ");
    readline(a, inputsize);

    printf("Zeichenkette 2: ");
    readline(b, inputsize);

    str = mystrcat(a, b);
    if (str) {
        puts(str);
        free(str);
    }

    return 0;
}

void readline(char *line, int n)
{
    int i;
    char c;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < n - 1; i++) {
        line[i] = c;
    }
    line[i] = '\0';
}

char *mystrcat(char a[], char b[])
{
    int r, w, la, lb, lc;
    char *c;

    for (la = 0; a[la] != '\0'; la++);
    for (lb = 0; b[lb] != '\0'; lb++);

    lc = la + lb + 1;
    c = (char *)malloc(sizeof(char) * lc);
    if (!c) {
        return NULL;
    }

    w = 0;
    for (r = 0; r < la; r++) {
        c[w++] = a[r];
    }
    for (r = 0; r < lb; r++) {
        c[w++] = b[r];
    }
    c[w] = '\0';

    return c;
}
