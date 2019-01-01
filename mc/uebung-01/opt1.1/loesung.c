/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdio.h>

float to_celsius(int fahrenheit);

int main()
{
    for (int fahrenheit = 0; fahrenheit <= 210; fahrenheit += 15) {
        printf("%3d\t%10.6f\n", fahrenheit, to_celsius(fahrenheit));
    }
    return 0;
}

float to_celsius(int fahrenheit)
{
    return (5.0/9.0) * (fahrenheit-32);
}
