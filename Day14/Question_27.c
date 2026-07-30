/*
Write a program to print the sum of the first n odd numbers.
*/
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) return 1;
    // The sum of the first n odd numbers is n squared.
    printf("%lld\n", (long long)n * n);
    return 0;
}
