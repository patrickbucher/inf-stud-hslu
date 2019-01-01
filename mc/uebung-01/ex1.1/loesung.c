/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char input[] = "abc8DEF-ghi_JKL";

    // 'a' (97) comes after 'A' (65) in ACII
    const int offset = 'a' - 'A';

    for (int i = 0; i < strlen(input); i++) {
        int c = input[i];
        if (c >= 'A' && c <= 'Z') {
            printf("%c -> %c\n", c, c + offset);
        } else if (c >= 'a' && c <= 'z') {
            printf("%c -> %c\n", c, c - offset);
        }
    }

    return 0;
}
