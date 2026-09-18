/*
Print all sub-strings of a string.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    size_t length = strlen(line);
    for (size_t start = 0; start < length; ++start) {
        for (size_t end = start + 1; end <= length; ++end) {
            if (start || end > 1) putchar(',');
            printf("%.*s", (int)(end - start), line + start);
        }
    }
    putchar('\n');
    return 0;
}
