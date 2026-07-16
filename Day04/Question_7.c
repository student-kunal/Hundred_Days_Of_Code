/*
Write a program to swap two numbers without using a third variable.
*/
#include <stdio.h>

int main(void)
{
    int first, second;
    if (scanf("%d%d", &first, &second) != 2) return 1;
    first ^= second;
    second ^= first;
    first ^= second;
    printf("After swap: %d %d\n", first, second);
    return 0;
}
