/*
Write a program to input time in seconds and convert it to hours:minutes:seconds format.
*/
#include <stdio.h>

int main(void)
{
    int seconds;
    if (scanf("%d", &seconds) != 1) return 1;
    if (seconds < 0) return 1;
    printf("%d:%d:%d\n", seconds / 3600, seconds / 60 % 60, seconds % 60);
    return 0;
}
