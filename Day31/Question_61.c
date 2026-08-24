/*
Search for an element in an array using linear search.
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
    for (int i = 0; i < n; ++i) {
        if (values[i] == target) {
            printf("Found at index %d\n", i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
