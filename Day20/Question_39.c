/*
Write a program to find the product of odd digits of a number.
*/
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    long long value = n;
    if (value < 0) value = -value;
    int odd[16], count = 0;
    long long product = 1;
    while (value) {
        int digit = (int)(value % 10);
        if (digit % 2) {
            odd[count++] = digit;
            product *= digit;
        }
        value /= 10;
    }
    printf("%lld (", product);
    if (count == 0) printf("no odd digits, assume 1");
    for (int i = count - 1; i >= 0; --i) printf("%d%s", odd[i], i ? "*" : "");
    puts(")");
    return 0;
}
