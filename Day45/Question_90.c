/*
Toggle case of each character in a string.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    for (size_t i = 0; line[i]; ++i) {
        unsigned char ch = (unsigned char)line[i];
        line[i] = (char)(isupper(ch) ? tolower(ch) : toupper(ch));
    }
    puts(line);
    return 0;
}
