/*
Write a program to find the 1’s complement of a binary number and print it.
*/
#include <stdio.h>

int main(void)
{
    char digits[256];
    if (scanf("%255s", digits) != 1) return 1;
    for (int i = 0; digits[i]; ++i) {
        if (digits[i] != '0' && digits[i] != '1') return 1;
        digits[i] = digits[i] == '0' ? '1' : '0';
    }
    puts(digits);
    return 0;
}
