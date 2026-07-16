/*
Write a program to find and display the sum of the first n natural numbers.
*/
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) return 1;
    printf("Sum=%lld\n", n * (n + 1LL) / 2);
    return 0;
}
