/*
Write a program to check if a number is a palindrome.
*/
#include <stdio.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;
    long long reversed = 0;
    for (int rest = n; rest > 0; rest /= 10) reversed = reversed * 10 + rest % 10;
    puts(reversed == n ? "Palindrome" : "Not palindrome");
    return 0;
}
