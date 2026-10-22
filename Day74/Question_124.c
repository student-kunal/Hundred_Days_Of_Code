/*
Take two filenames from the user – a source file and a destination file. Copy all the content from the source file to the destination file using fgetc() and fputc().
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char source[512], destination[512];
    if (!fgets(source, sizeof source, stdin) || !fgets(destination, sizeof destination, stdin)) return 1;
    source[strcspn(source, "\r\n")] = '\0';
    destination[strcspn(destination, "\r\n")] = '\0';
    FILE *input = fopen(source, "rb");
    if (!input) return 1;
    // Stage the bytes first so even two names for the same file are safe.
    FILE *staged = tmpfile();
    if (!staged) { fclose(input); return 1; }
    int ch;
    while ((ch = fgetc(input)) != EOF) {
        if (fputc(ch, staged) == EOF) return 1;
    }
    int failed = ferror(input);
    if (fclose(input) != 0 || failed || fseek(staged, 0, SEEK_SET) != 0) return 1;
    FILE *output = fopen(destination, "wb");
    if (!output) { fclose(staged); return 1; }
    while ((ch = fgetc(staged)) != EOF) {
        if (fputc(ch, output) == EOF) return 1;
    }
    failed = ferror(staged);
    fclose(staged);
    if (fclose(output) != 0 || failed) return 1;
    printf("File copied successfully to %s\n", destination);
    return 0;
}
