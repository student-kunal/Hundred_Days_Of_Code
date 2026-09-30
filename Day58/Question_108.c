/*
Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
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
    long long answer[CAPACITY], prefix = 1, suffix = 1;
    for (int i = 0; i < n; ++i) {
        answer[i] = prefix;
        prefix *= values[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        answer[i] *= suffix;
        suffix *= values[i];
    }
    putchar('[');
    for (int i = 0; i < n; ++i) printf("%s%lld", i ? "," : "", answer[i]);
    puts("]");
    return 0;
}
