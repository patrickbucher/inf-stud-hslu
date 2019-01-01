/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#ifndef _ADDRESS_H
#define _ADDRESS_H

#define BUFSIZE 128

// Structure to hold an address record. Street number is represented as a char
// array, because it can contain numbers.
typedef struct address {
    char *firstname;
    char *lastname;
    char *street;
    char *street_number;
    int zip;
    char *city;
    struct address *next;
} address;

// Output address in swiss letter address format to the standard output.
void adr_output(address *);

// Output a list of n addresses using adr_output with an empty line between
// addresses.
void adr_list_output(address **, int n);

// Prompts the address information from the user on standard input and returns
// the initialized address.
address *adr_input();

#endif
