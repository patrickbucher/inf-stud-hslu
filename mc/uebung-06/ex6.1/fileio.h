/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#ifndef _FILEIO_H
#define _FILEIO_H

// Denotes the order of address input fields.
typedef enum {
    FIRSTNAME = 1,
    LASTNAME = 2,
    STREET = 3,
    STREET_NUMBER = 4,
    ZIP = 5,
    CITY = 6,
} fields;

// Writes the linked list of addresses starting from head to the path denoted by
// filename.
bool write(address *head, char *filename);

// Reads the address file from the path at filename and returns the head of the
// linked list created.
address *read(char *filename);

#define RECORD_SIZE 1024
#define RECORD_FORMAT "%s\t%s\t%s\t%s\t%d\t%s\n"

#endif
