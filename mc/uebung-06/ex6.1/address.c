/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address.h"
#include "readline.h"

// Prompts for field with the given the user and initializes the pointer field
// with the value read from standard input.
static void read_field(char *name, char **field);

void adr_output(address *adr)
{
    if (adr == NULL) {
        return;
    }
    printf("%s %s\n", adr->firstname, adr->lastname);
    printf("%s %s\n", adr->street, adr->street_number);
    printf("%d %s\n", adr->zip, adr->city);
}

void adr_list_output(address **adrs, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        adr_output(adrs[i]);
        putchar('\n');
    }
}

address *adr_input()
{
    char buf[BUFSIZE];
    int n;
    address *adr;

    adr = (address *)malloc(sizeof(address));
    if (!adr) {
        return NULL;
    }

    read_field("First Name:\t", &(adr->firstname));
    read_field("Last Name:\t", &(adr->lastname));
    read_field("Street:\t\t", &(adr->street));
    read_field("Street Number:\t", &(adr->street_number));
    printf("Zip Code:\t");
    n = readline(buf, BUFSIZE);
    adr->zip = stoi(buf, n);
    read_field("City:\t\t", &(adr->city));
    adr->next = NULL;

    return adr;
}

static void read_field(char *name, char **field)
{
    char buf[BUFSIZE];
    int n;

    printf("%s", name);
    n = readline(buf, BUFSIZE);
    if (n > 0) {
        *field = (char *)malloc((n + 1) * sizeof(char));
        strncpy(*field, buf, (size_t)(n + 1));
    }
}
