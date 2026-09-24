/*
Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char line[65536];
    if (!fgets(line, sizeof line, stdin)) return 1;
    const char *equals = strchr(line, '=');
    int n;
    if (sscanf(equals ? equals + 1 : line, "%d", &n) != 1 || n < 1) return 1;
    // Equal inclusive sums imply x*x equals the sum from 1 through n.
    long long total = (long long)n * (n + 1LL) / 2;
    long long low = 1, high = n;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * mid == total) {
            printf("%lld\n", mid);
            return 0;
        }
        if (mid * mid < total) low = mid + 1;
        else high = mid - 1;
    }
    puts("-1");
    return 0;
}
