/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char *firstname;
    char *lastname;
    struct person *next;
} person;

const int length = 100;

int main()
{
    int i, n, count;
    person *p, *head = NULL;
    char first[length], last[length];

    // input
    for (count = 0; ; count++) {
        printf("Vorname:  ");
        n = scanf("%s", first);
        if (n <= 0) {
            break;
        }
        printf("Nachname: ");
        n = scanf("%s", last);
        if (n <= 0) {
            break;
        }
        p = (person*)malloc(sizeof(person));
        p->firstname = malloc(sizeof(char) * (strlen(first) + 1));
        p->lastname = malloc(sizeof(char) * (strlen(last) + 1));
        strcpy(p->firstname, first);
        strcpy(p->lastname, last);
        p->next = head;
        head = p;
    }

    // output
    printf("\n%d Personen eingegeben:\n", count);
    for (p = head; p != NULL; p = p->next) {
        printf("%s %s\n", p->firstname, p->lastname);
    }

    // cleanup
    for (p = head; p != NULL;) {
        free(p->firstname);
        free(p->lastname);
        head = p->next;
        free(p);
        p = head;
    }

    return 0;
}
