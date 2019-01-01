/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int day_of_year(int year, int month, int day);
uint8_t *create_daytab(int year);

int main()
{
    int doy;

    printf("01.01.2018 = %3d. day of year\n", day_of_year(2018, 1, 1));
    printf("24.06.2000 = %3d. day of year\n", day_of_year(2000, 6, 24));
    printf("24.06.2001 = %3d. day of year\n", day_of_year(2001, 6, 24));
    printf("31.12.2018 = %3d. day of year\n", day_of_year(2018, 12, 31));

    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i;
    uint8_t *daytab;

    daytab = create_daytab(year);
    for (i = 0; i < month - 1; i++) {
        day += daytab[i];
    }

    return day;
}

uint8_t *create_daytab(int year)
{
    uint8_t *daytab;
    uint8_t i;
    bool leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    daytab = (uint8_t*)malloc(12 * sizeof(uint8_t));
    for (i = 0; i < 12; i++) {
        switch (i + 1) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                daytab[i] = 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                daytab[i] = 30;
                break;
            case 2:
                daytab[i] = leap ? 29 : 28;
                break;
            default:
                daytab[i] = 0;
        }
    }

    return daytab;
}
