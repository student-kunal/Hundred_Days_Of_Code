/*
Reverse a string.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    for (size_t i = strlen(line); i > 0; --i) putchar(line[i - 1]);
    putchar('\n');
    return 0;
}
