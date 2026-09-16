/*
Reverse each word in a sentence without changing the word order.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    size_t i = 0;
    while (line[i]) {
        if (isspace((unsigned char)line[i])) {
            putchar(line[i++]);
        } else {
            size_t start = i;
            while (line[i] && !isspace((unsigned char)line[i])) ++i;
            for (size_t j = i; j > start; --j) putchar(line[j - 1]);
        }
    }
    putchar('\n');
    return 0;
}
