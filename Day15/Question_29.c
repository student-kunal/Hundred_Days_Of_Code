/*
Write a program to calculate the factorial of a number.
*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        if (result > ULLONG_MAX / (unsigned)i) {
            puts("Overflow");
            return 0;
        }
        result *= i;
    }
    printf("%llu\n", result);
    return 0;
}
