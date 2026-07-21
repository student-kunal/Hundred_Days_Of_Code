/*
Write a program to input a character and check whether it is a vowel or consonant using if–else.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char ch;
    if (scanf(" %c", &ch) != 1) return 1;
    int letter = tolower((unsigned char)ch);
    if (!isalpha((unsigned char)ch)) return 1;
    if (strchr("aeiou", letter)) puts("Vowel");
    else puts("Consonant");
    return 0;
}
