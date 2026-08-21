/*
Count positive, negative, and zero elements in an array.
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
    int positive = 0, negative = 0;
    for (int i = 0; i < n; ++i) {
        if (values[i] > 0) ++positive;
        if (values[i] < 0) ++negative;
    }
    printf("Positive=%d, Negative=%d, Zero=%d\n", positive, negative, n - positive - negative);
    return 0;
}
