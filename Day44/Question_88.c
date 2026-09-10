/*
Replace spaces with hyphens in a string.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    for (size_t i = 0; line[i]; ++i) {
        if (line[i] == ' ') line[i] = '-';
    }
    puts(line);
    return 0;
}
