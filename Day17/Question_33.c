/*
Write a program to check if a number is an Armstrong number.
*/
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    int digits = 1;
    for (int rest = n; rest >= 10; rest /= 10) ++digits;
    long long sum = 0;
    for (int rest = n; rest > 0; rest /= 10) {
        long long power = 1;
        for (int i = 0; i < digits; ++i) power *= rest % 10;
        sum += power;
    }
    puts(n == sum ? "Armstrong" : "Not Armstrong");
    return 0;
}
