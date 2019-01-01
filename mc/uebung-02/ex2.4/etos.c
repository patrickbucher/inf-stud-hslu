/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum {
    eicheln = 0,
    schellen = 1,
    schilten = 2,
    rosen = 3,
} farbe;

char *etos(farbe);

int main()
{
    char *s;
    farbe trumpf;

    srand(time(NULL));
    trumpf = rand() % 4;

    s = etos(trumpf);
    if (s) {
        printf("%s ist Trumpf\n", s);
        free(s);
    }

    return 0;
}

char *etos(farbe f)
{
    char *s = malloc(sizeof(char) * 10);
    switch (f) {
    case eicheln:
        strcpy(s, "Eicheln");
        break;
    case schellen:
        strcpy(s, "Schellen");
        break;
    case schilten:
        strcpy(s, "Schilten");
        break;
    case rosen:
        strcpy(s, "Rosen");
        break;
    }
    return s;
}
