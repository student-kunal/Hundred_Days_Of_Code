/*
Find the sum of all elements in a matrix.
*/
#include <stdio.h>

int main(void)
{
    enum { MAX_SIDE = 100 };
    int rows, cols, matrix[MAX_SIDE][MAX_SIDE];
    if (scanf("%d%d", &rows, &cols) != 2 || rows < 1 || rows > MAX_SIDE ||
        cols < 1 || cols > MAX_SIDE) return 1;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (scanf("%d", &matrix[r][c]) != 1) return 1;
        }
    }
    long long sum = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) sum += matrix[r][c];
    }
    printf("%lld\n", sum);
    return 0;
}
