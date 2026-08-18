/*
Write a program to print the following pattern:
*
***
*****
*******
*********
*******
*****
***
*
*/
#include <stdio.h>

int main(void)
{
    for (int row = 1; row <= 9; ++row) {
        int stars = row <= 5 ? 2 * row - 1 : 2 * (10 - row) - 1;
        for (int i = 0; i < stars; ++i) putchar('*');
        putchar('\n');
    }
    return 0;
}
