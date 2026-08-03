/*
Write a program to take a number as input and print its equivalent binary representation.
*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    long long value = n;
    if (value < 0) value = -value;
    char bits[sizeof(value) * CHAR_BIT];
    int count = 0;
    do {
        bits[count++] = (char)('0' + value % 2);
        value /= 2;
    } while (value);
    if (n < 0) putchar('-');
    while (count > 0) putchar(bits[--count]);
    putchar('\n');
    return 0;
}
