/*
Find the longest word in a sentence.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    size_t best = 0, best_length = 0, i = 0;
    while (line[i]) {
        while (isspace((unsigned char)line[i])) ++i;
        size_t start = i;
        while (line[i] && !isspace((unsigned char)line[i])) ++i;
        if (i - start > best_length) {
            best = start;
            best_length = i - start;
        }
    }
    printf("%.*s\n", (int)best_length, line + best);
    return 0;
}
