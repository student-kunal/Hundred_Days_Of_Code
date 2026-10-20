/*
Write a C program that opens an existing file (e.g., info.txt) and reads its contents using fgets(). The program should print all the lines to the console until EOF (end of file) is reached.
*/
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("info.txt", "r");
    if (!file) return 1;
    char buffer[1024];
    while (fgets(buffer, sizeof buffer, file)) {
        if (fputs(buffer, stdout) == EOF) return 1;
    }
    int failed = ferror(file);
    if (fclose(file) != 0 || failed) return 1;
    return 0;
}
