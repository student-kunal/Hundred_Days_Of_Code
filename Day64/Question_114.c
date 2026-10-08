/*
Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main(void)
{
    char line[65536];
    if (!fgets(line, sizeof line, stdin)) return 1;
    char *start = strchr(line, '"');
    if (start) {
        char *end = strrchr(++start, '"');
        if (!end) return 1;
        *end = '\0';
    } else {
        start = line;
        start[strcspn(start, "\r\n")] = '\0';
    }
    int last_plus_one[UCHAR_MAX + 1] = {0}, left = 0, best = 0;
    for (int i = 0; start[i]; ++i) {
        unsigned char ch = (unsigned char)start[i];
        if (last_plus_one[ch] > left) left = last_plus_one[ch];
        last_plus_one[ch] = i + 1;
        if (i - left + 1 > best) best = i - left + 1;
    }
    printf("%d\n", best);
    return 0;
}
