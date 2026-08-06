/*
Write a program to find the LCM of two numbers.
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
    long long x = llabs((long long)a), y = llabs((long long)b);
    long long multiple = (x == 0 || y == 0) ? 0 : x / gcd(x, y) * y;
    printf("%lld\n", multiple);
    return 0;
}
