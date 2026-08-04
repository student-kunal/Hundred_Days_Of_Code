/*
Write a program to check if a number is prime.
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
    puts(is_prime(n) ? "Prime" : "Not prime");
    return 0;
}
