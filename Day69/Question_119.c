/*
Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.
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
    // At most CAPACITY distinct values, so this table always has an empty slot.
    enum { SLOTS = 2 * CAPACITY };
    int keys[SLOTS];
    unsigned char used[SLOTS] = {0};
    for (int i = 0; i < n; ++i) {
        unsigned slot = (unsigned)values[i] % SLOTS;
        while (used[slot] && keys[slot] != values[i]) slot = (slot + 1) % SLOTS;
        if (used[slot]) {
            printf("%d\n", values[i]);
            return 0;
        }
        used[slot] = 1;
        keys[slot] = values[i];
    }
    puts("-1");
    return 0;
}
