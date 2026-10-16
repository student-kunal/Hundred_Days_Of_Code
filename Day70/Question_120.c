/*
Write a program to take a string input. Change it to sentence case.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char line[65536];
    if (!fgets(line, sizeof line, stdin)) return 1;
    char *text = line;
    if (strncmp(text, "str = ", 6) == 0) text += 6;
    text[strcspn(text, "\r\n")] = '\0';
    // The examples capitalize the first letter of every word.
    int start_word = 1;
    for (; *text; ++text) {
        unsigned char ch = (unsigned char)*text;
        putchar(start_word ? toupper(ch) : tolower(ch));
        start_word = isspace(ch);
    }
    putchar('\n');
    return 0;
}
