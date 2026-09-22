/*
Write a Program to take a sorted array arr[] and an integer x as input, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x and print it. This element is called the ceil of x. If such an element does not exist, print -1. Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.
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
    const char *equals = strrchr(cursor, '=');
    int target;
    if (sscanf(equals ? equals + 1 : cursor, "%d", &target) != 1) return 1;
    int low = 0, high = n;
    while (low < high) {
        int middle = low + (high - low) / 2;
        if (values[middle] < target) low = middle + 1;
        else high = middle;
    }
    printf("%d\n", low == n ? -1 : low);
    return 0;
}
