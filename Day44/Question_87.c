/*
Count spaces, digits, and special characters in a string.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    int spaces = 0, digits = 0, special = 0;
    for (size_t i = 0; line[i]; ++i) {
        unsigned char ch = (unsigned char)line[i];
        if (ch == ' ') ++spaces;
        else if (isdigit(ch)) ++digits;
        else if (!isalpha(ch)) ++special;
    }
    printf("Spaces=%d, Digits=%d, Special=%d\n", spaces, digits, special);
    return 0;
}
