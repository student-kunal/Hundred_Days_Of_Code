/*
A file numbers.txt contains a list of integers separated by spaces. Read all integers, compute their sum and average, and print both.
*/
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("numbers.txt", "r");
    if (!file) return 1;
    long long sum = 0;
    int value, status;
    size_t count = 0;
    while ((status = fscanf(file, "%d", &value)) == 1) {
        sum += value;
        ++count;
    }
    int failed = ferror(file) || status != EOF;
    if (fclose(file) != 0 || failed) return 1;
    if (!count) puts("Sum = 0\nAverage = undefined");
    else printf("Sum = %lld\nAverage = %.2f\n", sum, (double)sum / count);
    return 0;
}
