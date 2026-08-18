/*
Write a program to print the following pattern:

   *
  ***
 *****
*******
 *****
  ***
   *

*/
#include <stdio.h>

int main(void)
{
    for (int row = 1; row <= 7; ++row) {
        int level = row <= 4 ? row : 8 - row;
        for (int i = level; i < 4; ++i) putchar(' ');
        for (int i = 1; i < 2 * level; ++i) putchar('*');
        putchar('\n');
    }
    return 0;
}
