/*
Write a program to print the following pattern:

*

*
*
*

*
*
*
*
*

*
*
*

*


*/
#include <stdio.h>

int main(void)
{
    const int counts[] = {1, 3, 5, 3, 1};
    for (int group = 0; group < 5; ++group) {
        if (group) putchar('\n');
        for (int i = 0; i < counts[group]; ++i) puts("*");
    }
    return 0;
}
