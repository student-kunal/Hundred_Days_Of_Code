/*
Check if a string is a palindrome.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    size_t length = strlen(line);
    for (size_t i = 0; i < length / 2; ++i) {
        if (line[i] != line[length - 1 - i]) {
            puts("Not palindrome");
            return 0;
        }
    }
    puts("Palindrome");
    return 0;
}
