/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void doA();
void doB();
void doC();
void doD();

int main()
{
    char input[32];
    char selection;
    bool done = false;
    do {
        printf("A --> Select menu item A\n");
        printf("B --> Select menu item B\n");
        printf("C --> Select menu item C\n");
        printf("D --> Select menu item D\n");
        printf("Q --> Exit\n");
        printf("Enter selection:\n");
        scanf("%s", input);
        selection = tolower(input[0]);
        switch (selection) {
            case 'a':
                doA();
                break;
            case 'b':
                doB();
                break;
            case 'c':
                doC();
                break;
            case 'd':
                doD();
                break;
            case 'q':
                printf("Exiting...");
                done = true;
                break;
            default:
                puts("Unknown selection");
        }
        printf("\n\n");
    } while (!done);
    return 0;
}

void doA() {
    puts("Menu A selected");
}

void doB() {
    puts("Menu B selected");
}

void doC() {
    puts("Menu C selected");
}

void doD() {
    puts("Menu D selected");
}
