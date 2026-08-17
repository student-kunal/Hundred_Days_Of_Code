/*
Write a program to print the following pattern:
    5
   45
  345
 2345
12345
*/
#include <stdio.h>

int main(void)
{
    for (int row = 1; row <= 5; ++row) {
        for (int space = row; space < 5; ++space) putchar(' ');
        for (int digit = 6 - row; digit <= 5; ++digit) printf("%d", digit);
        putchar('\n');
    }
    return 0;
}
