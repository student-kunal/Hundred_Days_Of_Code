/*
Check if one string is a rotation of another.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    char other[4096];
    if (!fgets(other, sizeof other, stdin)) return 1;
    other[strcspn(other, "\r\n")] = '\0';
    char doubled[2 * sizeof line];
    snprintf(doubled, sizeof doubled, "%s%s", line, line);
    puts(strlen(line) == strlen(other) && strstr(doubled, other) ? "Rotation" : "Not rotation");
    return 0;
}
