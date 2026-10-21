/*
Read a text file and count the total number of characters, words, and lines. A word is defined as a sequence of non-space characters separated by spaces or newlines.
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    FILE *file = fopen("sample.txt", "r");
    if (!file) return 1;
    size_t characters = 0, words = 0, lines = 0;
    int ch, previous = '\n', in_word = 0;
    while ((ch = fgetc(file)) != EOF) {
        ++characters;
        if (ch == '\n') ++lines;
        if (!isspace(ch) && !in_word) ++words;
        in_word = !isspace(ch);
        previous = ch;
    }
    if (previous != '\n') ++lines;
    int failed = ferror(file);
    if (fclose(file) != 0 || failed) return 1;
    printf("Characters: %zu\nWords: %zu\nLines: %zu\n", characters, words, lines);
    return 0;
}
