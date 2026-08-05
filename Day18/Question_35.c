/*
Write a program to print all factors of a given number.
*/
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) return 1;
    if (n == 0) return 1;
    for (long long factor = 1; factor <= n; ++factor) {
        if (n % factor == 0) printf("%s%lld", factor == 1 ? "" : " ", factor);
    }
    putchar('\n');
    return 0;
}
