/*
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

#ifndef CALC_H
#define CALC_H

#define NUMBER '0' // signal that number was found
#define SIN 's'
#define EXP 'e'
#define POW 'p'

void push(double);
double pop();
int getop(char []);
int getch();
void ungetch(int);

#endif // CALC_H
