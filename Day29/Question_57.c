/*
Find the sum of array elements.
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
    long long sum = 0;
    for (int i = 0; i < n; ++i) sum += values[i];
    printf("%lld\n", sum);
    return 0;
}
