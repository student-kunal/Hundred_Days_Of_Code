/*
Write a program to print numbers from 1 to n.
*/
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    if (n < 0) return 1;
    for (long long i = 1; i <= n; ++i) printf("%s%lld", i == 1 ? "" : " ", i);
    putchar('\n');
    return 0;
}
