/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#ifndef _SORTING_H
#define _SORTING_H

// Sorts the given array of addresses of length n ascendingly using the given
// comparison function.
void insertion_sort(address **, int n, int (*)(address *, address *));

// Compares the last names of the given addresses.
int compare_name(address *, address *);

// Compares the streets of the given addresses.
int compare_street(address *, address *);

// Compares the cities of the given addresses.
int compare_city(address *, address *);

#endif
