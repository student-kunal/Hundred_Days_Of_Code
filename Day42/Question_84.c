/*
Convert a lowercase string to uppercase without using built-in functions.
*/
#include <stdio.h>

int main(void)
{
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n' && ch != '\r') {
        if (ch >= 'a' && ch <= 'z') ch += 'A' - 'a';
        putchar(ch);
    }
    putchar('\n');
    return 0;
}
