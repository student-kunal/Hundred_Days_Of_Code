/*
Check if a matrix is symmetric.
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
    int symmetric = rows == cols;
    for (int r = 1; r < rows && symmetric; ++r) {
        for (int c = 0; c < r; ++c) {
            if (matrix[r][c] != matrix[c][r]) symmetric = 0;
        }
    }
    puts(symmetric ? "True" : "False");
    return 0;
}
