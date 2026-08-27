/*
Insert an element in an array at a given position.
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
    int index, value;
    if (scanf("%d%d", &index, &value) != 2 || index < 0 || index > n || n == CAPACITY) return 1;
    for (int i = n; i > index; --i) values[i] = values[i - 1];
    values[index] = value;
    ++n;
    for (int i = 0; i < n; ++i) printf("%s%d", i ? " " : "", values[i]);
    putchar('\n');
    return 0;
}
