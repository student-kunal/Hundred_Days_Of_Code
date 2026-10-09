/*
Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[65536];
    if (!fgets(line, sizeof line, stdin)) return 1;
    int counts[26] = {0};
    char *cursor = line;
    for (int word = 0; word < 2; ++word) {
        char *start = strchr(cursor, '"');
        if (!start) return 1;
        char *end = strchr(++start, '"');
        if (!end) return 1;
        for (char *p = start; p < end; ++p) {
            if (*p < 'a' || *p > 'z') return 1;
            counts[*p - 'a'] += word == 0 ? 1 : -1;
        }
        cursor = end + 1;
    }
    for (int i = 0; i < 26; ++i) {
        if (counts[i] != 0) {
            puts("Not Anagram");
            return 0;
        }
    }
    puts("Anagram");
    return 0;
}
