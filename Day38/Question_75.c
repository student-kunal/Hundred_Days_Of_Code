/*
Add two matrices.
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
    int other_rows, other_cols, other[MAX_SIDE][MAX_SIDE];
    if (scanf("%d%d", &other_rows, &other_cols) != 2 ||
        other_rows < 1 || other_rows > MAX_SIDE || other_cols < 1 || other_cols > MAX_SIDE) return 1;
    for (int r = 0; r < other_rows; ++r) {
        for (int c = 0; c < other_cols; ++c) {
            if (scanf("%d", &other[r][c]) != 1) return 1;
        }
    }
    if (rows != other_rows || cols != other_cols) return 1;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            printf("%s%lld", c ? " " : "", (long long)matrix[r][c] + other[r][c]);
        }
        putchar('\n');
    }
    return 0;
}
