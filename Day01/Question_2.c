/*
Write a program to input two numbers and display their sum, difference, product, and quotient.
*/
#include <stdio.h>

int main(void)
{
    int a, b;
    if (scanf("%d%d", &a, &b) != 2) return 1;
    printf("Sum=%lld, Diff=%lld, Product=%lld, Quotient=",
           (long long)a + b, (long long)a - b, (long long)a * b);
    if (b == 0) puts("undefined");
    else printf("%lld\n", (long long)a / b);
    return 0;
}
