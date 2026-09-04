/*
Multiply two matrices.
*/
#include <stdio.h>
#include <limits.h>

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
    int other_rows, other_cols, other[MAX_SIDE][MAX_SIDE];
    if (scanf("%d%d", &other_rows, &other_cols) != 2 ||
        other_rows < 1 || other_rows > MAX_SIDE || other_cols < 1 || other_cols > MAX_SIDE) return 1;
    for (int r = 0; r < other_rows; ++r) {
        for (int c = 0; c < other_cols; ++c) {
            if (scanf("%d", &other[r][c]) != 1) return 1;
        }
    }
    if (cols != other_rows) return 1;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < other_cols; ++c) {
            long long sum = 0;
            for (int k = 0; k < cols; ++k) {
                long long term = (long long)matrix[r][k] * other[k][c];
                if ((term > 0 && sum > LLONG_MAX - term) || (term < 0 && sum < LLONG_MIN - term)) return 1;
                sum += term;
            }
            printf("%s%lld", c ? " " : "", sum);
        }
        putchar('\n');
    }
    return 0;
}
