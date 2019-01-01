/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>

int main()
{
    // all Fibonacci numbers up to 50
    const int limit = 50;
    int tmp = 0;
    int one_back, two_back;
    
    two_back = 0;
    one_back = 1;

    while (one_back <= limit) {
        printf("%d\n", one_back);
        tmp = one_back;
        one_back = one_back + two_back;
        two_back = tmp;
    }
    
    return 0;
}
