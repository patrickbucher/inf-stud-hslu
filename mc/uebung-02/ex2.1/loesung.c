/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch
 */

#include <stdio.h>
#include <string.h>

int readline(char *, int);
void reverse(char *);

int main()
{
    const int length = 80;
    char line[length];
    int n;

    for (;;) {
        n = readline(line, length);
        if (n == 0) {
            break;
        }
        reverse(line);
        printf("%s", line);
    } 

    return 0;
}

int readline(char s[], int n)
{
    int i = 0;
    int c;

    while ((c = getchar()) != EOF && c != '\n' && i < n - 1) {
        s[i++] = c;

    }
    if (c == '\n') {
        s[i++] = '\n';
    }
    s[i] = '\0';

    return i;
}

void reverse(char s[])
{
    int i, j, n, tmp;

    n = strlen(s);

    for (i = 0, j = n - 2; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    s[n-1] = '\n';
    s[n] = '\0';
}
