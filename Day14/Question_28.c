/*
Write a program to print the product of even numbers from 1 to n.
*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) return 1;
    unsigned long long product = 1;
    for (int even = 2; even <= n; even += 2) {
        if (product > ULLONG_MAX / (unsigned)even) {
            puts("Overflow");
            return 0;
        }
        product *= even;
    }
    printf("%llu", product);
    if (n >= 2) {
        printf(" (2");
        for (int even = 4; even <= n; even += 2) printf(" * %d", even);
        putchar(')');
    }
    putchar('\n');
    return 0;
}
