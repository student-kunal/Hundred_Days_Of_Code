/*
Write a program to print the following pattern:
*****
 ****
  ***
   **
    *
*/
#include <stdio.h>

int main(void)
{
    for (int row = 1; row <= 5; ++row) {
        for (int space = 1; space < row; ++space) putchar(' ');
        for (int star = row; star <= 5; ++star) putchar('*');
        putchar('\n');
    }
    return 0;
}
