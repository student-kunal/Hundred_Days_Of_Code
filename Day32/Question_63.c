/*
Merge two arrays.
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
    int count;
    if (scanf("%d", &count) != 1 || count < 0 || count > CAPACITY - n) return 1;
    for (int i = 0; i < count; ++i) {
        if (scanf("%d", &values[n + i]) != 1) return 1;
    }
    n += count;
    for (int i = 0; i < n; ++i) printf("%s%d", i ? " " : "", values[i]);
    putchar('\n');
    return 0;
}
