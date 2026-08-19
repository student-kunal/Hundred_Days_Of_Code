/*
Read and print elements of a one-dimensional array.
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
    for (int i = 0; i < n; ++i) printf("%s%d", i ? " " : "", values[i]);
    putchar('\n');
    return 0;
}
