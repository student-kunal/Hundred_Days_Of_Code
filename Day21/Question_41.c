/*
Write a program to swap the first and last digit of a number.
*/
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    long long value = n;
    if (value < 0) value = -value;
    long long place = 1;
    while (place <= value / 10) place *= 10;
    long long first = value / place, last = value % 10;
    long long swapped = value + (last - first) * (place - 1);
    printf("%lld\n", n < 0 ? -swapped : swapped);
    return 0;
}
