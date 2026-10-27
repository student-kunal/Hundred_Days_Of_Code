/*
Write a program that reads text from input.txt, converts all lowercase letters to uppercase, and writes the result to output.txt.
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    FILE *input = fopen("input.txt", "r");
    if (!input) return 1;
    FILE *output = fopen("output.txt", "w");
    if (!output) { fclose(input); return 1; }
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (fputc(toupper(ch), output) == EOF) return 1;
    }
    int failed = ferror(input);
    fclose(input);
    if (fclose(output) != 0 || failed) return 1;
    return 0;
}
