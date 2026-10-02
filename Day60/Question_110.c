/*
Write a program to take an integer array arr and an integer k as inputs. The task is to find the maximum element in each subarray of size k moving from left to right. Print the maximum elements for each window separated by spaces as output.
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
    int k;
    if (sscanf(equals ? equals + 1 : cursor, "%d", &k) != 1) return 1;
    if (k < 1 || k > n) return 1;
    for (int start = 0; start + k <= n; ++start) {
        int maximum = values[start];
        for (int j = start + 1; j < start + k; ++j) {
            if (values[j] > maximum) maximum = values[j];
        }
        printf("%s%d", start ? " " : "", maximum);
    }
    putchar('\n');
    return 0;
}
