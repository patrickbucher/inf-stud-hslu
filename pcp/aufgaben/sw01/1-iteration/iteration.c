#include <stdio.h>

void printNumberGoto(int n);
void printNumberFor(int n);
void printNumberRecursiveFunction(int n);
void printIfSmaller(int i, int max);

int main()
{
    printNumberGoto(7);
    printf("= printNumbersGoto(7)\n");
    printNumberFor(7);
    printf("= printNumbersFor(7)\n");
    printNumberRecursiveFunction(7);
    printf("= printNumbersRecursiveFunction(7)\n");
    return 0;
}

void printNumberGoto(int n)
{
    int i = 0;

start:
    printf("%d ", i);
    i++;
    if (i <= n) {
        goto start;
    }
}

void printNumberFor(int n)
{
    int i;

    for (i = 0; i <= n; i++) {
        printf("%d ", i);
    }
}

void printNumberRecursiveFunction(int n)
{
    printIfSmaller(0, n);
}

void printIfSmaller(int i, int max)
{
    if (i > max) {
        return;
    } else {
        printf("%d ", i);
        printIfSmaller(i+1, max);
    }
}
