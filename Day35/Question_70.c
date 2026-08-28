/*
Rotate an array to the right by k positions.
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
    int k;
    if (scanf("%d", &k) != 1) return 1;
    if (n > 0) {
        int shift = (k % n + n) % n;
        for (int i = 0; i < n; ++i) printf("%s%d", i ? " " : "", values[(i + n - shift) % n]);
    }
    putchar('\n');
    return 0;
}
