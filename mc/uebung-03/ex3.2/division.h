/**
 * Author: Patrick Bucher <patrick.bucher@stud.hslu.ch>
 */

typedef union {
    int integer;
    float floatingpoint;
} result;

typedef struct {
    int dividend;
    int divisor;
    result quotient;
    bool remainder;
} division;

division *divide(int, int);
