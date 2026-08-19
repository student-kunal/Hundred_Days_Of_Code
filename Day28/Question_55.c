/*
Write a program to print all the prime numbers from 1 to n.
*/
#include <stdio.h>

static int is_prime(int n)
{
    if (n < 2) return 0;
    for (int divisor = 2; divisor <= n / divisor; ++divisor) {
        if (n % divisor == 0) return 0;
    }
    return 1;
}

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) return 1;
    for (long long i = 2; i <= n; ++i) {
        if (is_prime((int)i)) printf("%s%lld", i == 2 ? "" : " ", i);
    }
    putchar('\n');
    return 0;
}
