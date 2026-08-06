/*
Write a program to find the sum of digits of a number.
*/
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    long long value = n;
    if (value < 0) value = -value;
    int sum = 0;
    while (value) {
        sum += (int)(value % 10);
        value /= 10;
    }
    printf("%d\n", sum);
    return 0;
}
