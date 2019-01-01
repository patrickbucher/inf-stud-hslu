/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <string.h>
#include "address.h"
#include "sorting.h"

// Swaps the elements of the address array at the two given indices.
static void swap(address **, int, int);

void insertion_sort(address **adrs, int n, int (*cmp)(address *, address *))
{
    int i, j;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j > 0 && cmp(adrs[j - 1], adrs[j]) > 0; j--) {
            swap(adrs, j, j - 1);
        }
    }
}

int compare_name(address *a, address *b)
{
    size_t la, lb, n;

    la = strlen(a->lastname);
    lb = strlen(b->lastname);
    n = la < lb ? la : lb;

    return strncmp(a->lastname, b->lastname, n);
}

int compare_street(address *a, address *b)
{
    size_t la, lb, n;
    
    la = strlen(a->street);
    lb = strlen(b->street);
    n = la < lb ? la : lb;

    return strncmp(a->street, b->street, n);
}

int compare_city(address *a, address *b)
{
    size_t la, lb, n;

    la = strlen(a->city);
    lb = strlen(b->city);
    n = la < lb ? la : lb;

    return strncmp(a->city, b->city, n);
}

static void swap(address **adrs, int i, int j)
{
    address *tmp;

    tmp = adrs[i];
    adrs[i] = adrs[j];
    adrs[j] = tmp;
}
