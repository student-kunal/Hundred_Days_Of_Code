/*
Print initials of a name with the surname displayed in full.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    char *word = strtok(line, " \t");
    int initials = 0;
    while (word) {
        char *next = strtok(NULL, " \t");
        if (next) {
            printf("%c.", toupper((unsigned char)word[0]));
            ++initials;
        } else printf("%s%s", initials ? " " : "", word);
        word = next;
    }
    putchar('\n');
    return 0;
}
