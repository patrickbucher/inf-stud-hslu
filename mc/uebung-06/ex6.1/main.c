/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "address.h"
#include "fileio.h"
#include "sorting.h"
#include "readline.h"

#define FILENAME_LENGTH 128

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

// Clears the screen and, if request_return is true, asks the user to press
// [Return] before, so that he can look at the output before. The
// platform-specific clear command ist defined as CLEAR above.
static int clear(bool request_return);

// Prompts the user for a file name on standard input.
static char *read_filename();

// Converts the array of addresses of size n to a linked list and returns the
// reference to its head.
static address *tolist(address **adrs, int n);

// Converts the linked list of addresse beginning at head to an array of
// addresses and returns the length of that array. The adrs pointer shall be
// NULL initialized.
static int toarray(address *head, address ***adrs);

// Frees the memory of the linked list.
static void cleanup(address *head);

int main()
{
    char c, *filename;
    bool first = true;
    address *adr, *head = NULL, **adrs;
    int (*cmp)(address *, address *);
    int n;

    do {
        clear(!first);
        first = false;
        printf("N: New Address\n");
        printf("L: List Addresses\n");
        printf("R: Read Addresses from File\n");
        printf("S: Save Addresses to File\n");
        printf("1: Sort List by Name\n");
        printf("2: Sort List by Street\n");
        printf("3: Sort List by City\n");
        printf("Q: Quit\n\n");
        while (!isalnum(c = getchar()));
        c = toupper(c);
        getchar(); // discard newline
        switch (c) {
            case 'N':
                adr = adr_input();
                if (head != NULL) {
                    adr->next = head;
                }
                head = adr;
                printf("\nAddress Saved. ");
                break;
            case 'L':
                for (adr = head; adr != NULL; adr = adr->next) {
                    adr_output(adr);
                    putchar('\n');
                }
                break;
            case 'R':
                filename = read_filename();
                if (head != NULL) {
                    cleanup(head);
                }
                head = read(filename);
                if (!head) {
                    printf("Reading from %s failed.\n", filename);
                    getchar();
                }
                free(filename);
                printf("Addresses read from file. ");
                break;
            case 'S':
                if (head == NULL) {
                    printf("No Addresses to Save\n");
                    break;
                }
                filename = read_filename();
                if (!write(head, filename)) {
                    printf("Writing to %s failed.\n", filename);
                    getchar();
                }
                free(filename);
                break;
            case '1':
            case '2':
            case '3':
                if (c == '1') {
                    cmp = compare_name;
                } else if (c == '2') {
                    cmp = compare_street;
                } else {
                    cmp = compare_city;
                }
                adrs = NULL;
                n = toarray(head, &adrs);
                insertion_sort(adrs, n, cmp);
                adr_list_output(adrs, n);
                head = tolist(adrs, n);
                free(adrs);
                break;
            default:
                break;
        }
    } while (c != 'Q');
    cleanup(head);

    return 0;
}

static char *read_filename()
{
    char *s;
    char buf[FILENAME_LENGTH];
    int n;

    do {
        printf("Enter File Name: ");
        n = readline(buf, FILENAME_LENGTH);
    } while (n < 1);
    s = (char *)malloc(sizeof(char) * (n + 1));

    return strncpy(s, buf, (size_t)(n + 1));
}

static int clear(bool request_return)
{
    if (request_return) {
        puts("Press [Return] to continue.");
        getchar();
    }
    return system(CLEAR);
}

static int toarray(address *head, address ***adrs)
{
    int n;
    address *adr;

    for (n = 0, adr = head; adr != NULL; adr = adr->next, n++) {
        *adrs = realloc(*adrs, (n + 1) * sizeof(address *));
        if (*adrs) {
            (*adrs)[n] = adr;
        }
    }

    return n;
}

static address *tolist(address **adrs, int n)
{
    address *head;
    int i;

    for (head = NULL, i = n - 1; i >= 0; i--) {
        if (head == NULL) {
            adrs[i]->next = NULL;
        } else {
            adrs[i]->next = head;
        }
        head = adrs[i];
    }

    return head;
}

static void cleanup(address *head)
{
    address *adr, *tmp;

    for (adr = head; adr != NULL;) {
        free(adr->firstname);
        free(adr->lastname);
        free(adr->street);
        free(adr->street_number);
        free(adr->city);
        tmp = adr->next;
        free(adr);
        adr = tmp;
    }
}
