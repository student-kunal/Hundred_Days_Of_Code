/*
Write a program to input a character and check whether it is an uppercase alphabet, lowercase alphabet, digit, or special character.
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    if (scanf(" %c", &ch) != 1) return 1;
    unsigned char value = (unsigned char)ch;
    if (isupper(value)) puts("Uppercase alphabet");
    else if (islower(value)) puts("Lowercase alphabet");
    else if (isdigit(value)) puts("Digit");
    else puts("Special character");
    return 0;
}
