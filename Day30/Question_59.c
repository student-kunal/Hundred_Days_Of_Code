/*
Count even and odd numbers in an array.
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
    int even = 0;
    for (int i = 0; i < n; ++i) {
        if (values[i] % 2 == 0) ++even;
    }
    printf("Even=%d, Odd=%d\n", even, n - even);
    return 0;
}
