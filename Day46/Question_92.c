/*
Find the first repeating lowercase alphabet in a string.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[4096];
    if (!fgets(line, sizeof line, stdin)) return 1;
    line[strcspn(line, "\r\n")] = '\0';
    int counts[26] = {0};
    for (size_t i = 0; line[i]; ++i) {
        if (line[i] >= 'a' && line[i] <= 'z') ++counts[line[i] - 'a'];
    }
    for (size_t i = 0; line[i]; ++i) {
        if (line[i] >= 'a' && line[i] <= 'z' && counts[line[i] - 'a'] > 1) {
            printf("%c\n", line[i]);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
