/*
Write a program to reverse a given number.
*/
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    long long value = n;
    if (value < 0) value = -value;
    long long reversed = 0;
    while (value > 0) {
        reversed = reversed * 10 + value % 10;
        value /= 10;
    }
    printf("%lld\n", n < 0 ? -reversed : reversed);
    return 0;
}
