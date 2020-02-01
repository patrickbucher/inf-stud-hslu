#include <stdio.h>

int calc(int f(int, int), int a, int b)
{
    return f(a, b);
}

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int main()
{
    int c;

    c = calc(add, 3, 4);
    printf("%d\n", c);

    c = calc(sub, 8, 2);
    printf("%d\n", c);

    return 0;
}
