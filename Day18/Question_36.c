/*
Write a program to find the HCF (GCD) of two numbers.
*/
#include <stdio.h>
#include <stdlib.h>

static long long gcd(long long a, long long b)
{
    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main(void)
{
    int a, b;
    if (scanf("%d%d", &a, &b) != 2) return 1;
    printf("%lld\n", gcd(llabs((long long)a), llabs((long long)b)));
    return 0;
}
