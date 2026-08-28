/*
Find the second largest element in an array.
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
    int largest = values[0], second = 0, has_second = 0;
    for (int i = 1; i < n; ++i) {
        if (values[i] > largest) {
            second = largest;
            largest = values[i];
            has_second = 1;
        } else if (values[i] < largest && (!has_second || values[i] > second)) {
            second = values[i];
            has_second = 1;
        }
    }
    if (has_second) printf("%d\n", second);
    else puts("No second largest");
    return 0;
}
