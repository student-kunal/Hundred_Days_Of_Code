/*
Delete an element from an array.
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
    int index;
    if (scanf("%d", &index) != 1 || index < 0 || index >= n) return 1;
    for (int i = index + 1; i < n; ++i) values[i - 1] = values[i];
    --n;
    for (int i = 0; i < n; ++i) printf("%s%d", i ? " " : "", values[i]);
    putchar('\n');
    return 0;
}
