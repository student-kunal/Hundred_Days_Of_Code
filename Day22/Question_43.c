/*
Write a program to check if a number is a strong number.
*/
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    int sum = 0, rest = n;
    if (n >= 0) {
        do {
            int factorial = 1;
            for (int i = 2; i <= rest % 10; ++i) factorial *= i;
            sum += factorial;
            rest /= 10;
        } while (rest);
    }
    puts(n == sum ? "Strong number" : "Not strong number");
    return 0;
}
