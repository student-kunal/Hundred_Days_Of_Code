/*
Open an existing file in append mode and allow the user to enter a new line of text. Append the text at the end without overwriting existing content.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    FILE *file = fopen("data.txt", "a+b");
    if (!file) return 1;
    if (fseek(file, 0, SEEK_END) != 0) return 1;
    long size = ftell(file);
    if (size < 0) return 1;
    int last = '\n';
    if (size > 0) {
        if (fseek(file, -1, SEEK_END) != 0) return 1;
        last = fgetc(file);
        if (last == EOF || fseek(file, 0, SEEK_END) != 0) return 1;
    }
    if (last != '\n' && fputc('\n', file) == EOF) return 1;
    int written = fprintf(file, "%s\n", line);
    if (fclose(file) != 0 || written < 0) return 1;
    puts("File updated successfully with appended text.");
    return 0;
}
