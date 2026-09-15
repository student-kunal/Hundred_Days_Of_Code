/*
Check if two strings are anagrams of each other.
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    char other[4096];
    if (!fgets(other, sizeof other, stdin)) return 1;
    other[strcspn(other, "\r\n")] = '\0';
    int balance[UCHAR_MAX + 1] = {0};
    for (size_t i = 0; line[i]; ++i) ++balance[(unsigned char)line[i]];
    for (size_t i = 0; other[i]; ++i) --balance[(unsigned char)other[i]];
    for (int i = 0; i <= UCHAR_MAX; ++i) {
        if (balance[i]) {
            puts("Not anagrams");
            return 0;
        }
    }
    puts("Anagrams");
    return 0;
}
