#include <stdio.h>

int main()
{
    int value = 3;
    int other = 5;

    int * const a = &value; // constant pointer: reference can't change
    const int * b = &value; // constant integer: value can't change

    printf("a=%d, b=%d\n", *a, *b);

    // ok
    *a = 4; 

    // error: the value is constant (pointer to const int)
    // *b = 4;

    // error: the reference is constant (const pointer to int)
    // a = &other; 

    // ok
    b = &other;

    return 0;
}
