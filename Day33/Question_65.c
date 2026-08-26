/*
Search in a sorted array using binary search.
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
    int low = 0, high = n;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (values[mid] < target) low = mid + 1;
        else high = mid;
    }
    if (low < n && values[low] == target) printf("Found at index %d\n", low);
    else puts("-1");
    return 0;
}
