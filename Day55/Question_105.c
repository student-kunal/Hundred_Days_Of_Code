/*
Write a program to take an integer array nums of size n, and print the majority element. The majority element is the element that appears strictly more than ⌊n / 2⌋ times. Print -1 if no such element exists. Note: Majority Element is not necessarily the element that is present most number of times.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

enum { CAPACITY = 4096 };

static int read_array(const char **cursor, int values[])
{
    const char *p = strchr(*cursor, '[');
    if (!p) return -1;
    ++p;
    // The notation "arr[] = [...]" contains an empty pair before the data.
    if (*p == ']') {
        const char *next = p + 1;
        while (isspace((unsigned char)*next)) ++next;
        if (*next == '=') {
            ++next;
            while (isspace((unsigned char)*next)) ++next;
            if (*next == '[') p = next + 1;
        }
    }
    int count = 0;
    while (*p) {
        while (isspace((unsigned char)*p) || *p == ',') ++p;
        if (*p == ']') {
            *cursor = p + 1;
            return count;
        }
        char *end;
        errno = 0;
        long value = strtol(p, &end, 10);
        if (end == p || errno || value < INT_MIN || value > INT_MAX || count == CAPACITY) return -1;
        values[count++] = (int)value;
        p = end;
    }
    return -1;
}

int main(void)
{
    char line[65536];
    if (!fgets(line, sizeof line, stdin)) return 1;
    const char *cursor = line;
    int values[CAPACITY];
    int n = read_array(&cursor, values);
    if (n < 0) return 1;
    int candidate = 0, votes = 0;
    for (int i = 0; i < n; ++i) {
        if (votes == 0) candidate = values[i];
        votes += values[i] == candidate ? 1 : -1;
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (values[i] == candidate) ++count;
    }
    printf("%d\n", count > n / 2 ? candidate : -1);
    return 0;
}
