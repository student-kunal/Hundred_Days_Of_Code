/*
Ask the user for a filename. Check if it exists by trying to open it in read mode. If the file pointer is NULL, print an error message; otherwise, read and display its content.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char filename[512];
    if (!fgets(filename, sizeof filename, stdin)) return 1;
    filename[strcspn(filename, "\r\n")] = '\0';
    FILE *file = fopen(filename, "r");
    if (!file) {
        puts("Error: File does not exist!");
        return 0;
    }
    puts("File opened successfully.");
    char buffer[1024];
    while (fgets(buffer, sizeof buffer, file)) {
        if (fputs(buffer, stdout) == EOF) return 1;
    }
    int failed = ferror(file);
    if (fclose(file) != 0 || failed) return 1;
    return 0;
}
