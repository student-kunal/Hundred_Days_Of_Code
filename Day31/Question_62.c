/*
Reverse an array without taking extra space.
*/
#include <stdio.h>

int main(void)
{
    enum { CAPACITY = 10000 };
    int n, values[CAPACITY];
    if (scanf("%d", &n) != 1 || n < 0 || n > CAPACITY) return 1;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &values[i]) != 1) return 1;
    }
    for (int i = 0; i < n / 2; ++i) {
        int other = n - 1 - i;
        int temp = values[i];
        values[i] = values[other];
        values[other] = temp;
    }
    for (int i = 0; i < n; ++i) printf("%s%d", i ? " " : "", values[i]);
    putchar('\n');
    return 0;
}
