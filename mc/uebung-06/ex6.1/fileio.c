/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address.h"
#include "fileio.h"
#include "readline.h"

// Parses a line with the given lenght denoting an address record and returns
// an initialized address structure.
static address *parse(char *line, int length);

// Replaces possible tab characters with single spaces in the given string.
static void untab(char *);

bool write(address *head, char *filename)
{
    FILE *f;
    address *adr;

    f = fopen(filename, "w");
    if (!f) {
        return false;
    }

    for (adr = head; adr != NULL; adr = adr->next) {
        untab(adr->firstname);
        untab(adr->lastname);
        untab(adr->street);
        untab(adr->street_number);
        untab(adr->city);
        fprintf(f, RECORD_FORMAT,
                adr->firstname, adr->lastname,
                adr->street, adr->street_number,
                adr->zip, adr->city);
    }

    return fclose(f) == 0;
}

address *read(char *filename)
{
    FILE *f;
    address *head, *adr;
    char buf[RECORD_SIZE];
    int n;

    f = fopen(filename, "r");
    if (!f) {
        return NULL;
    }

    head = NULL;
    for (;;) {
        n = freadline(f, buf, RECORD_SIZE);
        if (n == 0) {
            break;
        }
        adr = parse(buf, n);
        if (!adr) {
            printf("Invalid Line '%s'\n", buf);
            continue;
        }
        if (head != NULL) {
            adr->next = head;
        } else {
            adr->next = NULL;
        }
        head = adr;
    }
    fclose(f);

    return head;
}

static address *parse(char *line, int length)
{
    address *adr;
    char buf[RECORD_SIZE];
    int tabs, r, w, field;
    size_t len;

    adr = (address *)malloc(sizeof(address));

    for (field = 0, r = 0, w = 0; r <= length; r++) {
        if (line[r] == '\t') {
            buf[w++] = '\0';
            field++;
            len = (size_t)w;
            switch (field) {
                case FIRSTNAME:
                    adr->firstname = (char *)malloc(w * sizeof(char));
                    strncpy(adr->firstname, buf, len);
                    break;
                case LASTNAME:
                    adr->lastname = (char *)malloc(w * sizeof(char));
                    strncpy(adr->lastname, buf, len);
                    break;
                case STREET:
                    adr->street = (char *)malloc(w * sizeof(char));
                    strncpy(adr->street, buf, len);
                    break;
                case STREET_NUMBER:
                    adr->street_number = (char *)malloc(w * sizeof(char));
                    strncpy(adr->street_number, buf, len);
                    break;
                case ZIP:
                    adr->zip = stoi(buf, w);
                    break;
            }
            w = 0;
        } else {
            buf[w++] = line[r];
        }
    }
    buf[w] = '\0';
    adr->city = (char *)malloc(w * sizeof(char));
    strncpy(adr->city, buf, (size_t)w);

    return adr;
}

static void untab(char *s)
{
    while (*(s++) != '\0') {
        if (*s == '\t') {
            *s = ' ';
        }
    }
}
