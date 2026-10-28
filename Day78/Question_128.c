/*
Read a text file and count how many vowels and consonants are in the file. Ignore digits and special characters.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

static int is_vowel(int ch)
{
    return strchr("aeiouAEIOU", ch) != NULL;
}

int main(void)
{
    FILE *file = fopen("text.txt", "r");
    if (!file) return 1;
    size_t vowels = 0, consonants = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (!isalpha(ch)) continue;
        if (is_vowel(ch)) ++vowels;
        else ++consonants;
    }
    int failed = ferror(file);
    if (fclose(file) != 0 || failed) return 1;
    printf("Vowels: %zu\nConsonants: %zu\n", vowels, consonants);
    return 0;
}
