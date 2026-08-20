/*
Find the maximum and minimum element in an array.
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
    if (!n) return 1;
    int minimum = values[0], maximum = values[0];
    for (int i = 1; i < n; ++i) {
        if (values[i] < minimum) minimum = values[i];
        if (values[i] > maximum) maximum = values[i];
    }
    printf("Max=%d, Min=%d\n", maximum, minimum);
    return 0;
}
