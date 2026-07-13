/*
Write a program to input two numbers and display their sum.
*/
#include <stdio.h>

int main(void)
{
    int a, b;
    if (scanf("%d%d", &a, &b) != 2) return 1;
    printf("Sum = %lld\n", (long long)a + b);
    return 0;
}
