/*
Count vowels and consonants in a string.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    int vowels = 0, consonants = 0;
    for (size_t i = 0; line[i]; ++i) {
        unsigned char ch = (unsigned char)line[i];
        if (!isalpha(ch)) continue;
        if (strchr("aeiou", tolower(ch))) ++vowels;
        else ++consonants;
    }
    printf("Vowels=%d, Consonants=%d\n", vowels, consonants);
    return 0;
}
