/*
Insert an element in a sorted array at the appropriate position.
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
    int target;
    if (scanf("%d", &target) != 1) return 1;
    if (n == CAPACITY) return 1;
    int i = n;
    while (i > 0 && values[i - 1] > target) {
        values[i] = values[i - 1];
        --i;
    }
    values[i] = target;
    ++n;
    for (int i = 0; i < n; ++i) printf("%s%d", i ? " " : "", values[i]);
    putchar('\n');
    return 0;
}
