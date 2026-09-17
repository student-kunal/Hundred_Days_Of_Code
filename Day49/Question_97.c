/*
Print the initials of a name.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    for (char *word = strtok(line, " \t"); word; word = strtok(NULL, " \t"))
        printf("%c.", toupper((unsigned char)word[0]));
    putchar('\n');
    return 0;
}
