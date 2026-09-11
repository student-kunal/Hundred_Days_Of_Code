/*
Count frequency of a given character in a string.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    int target = getchar(), count = 0;
    if (target == EOF) return 1;
    for (size_t i = 0; line[i]; ++i) {
        if ((unsigned char)line[i] == target) ++count;
    }
    printf("%d\n", count);
    return 0;
}
