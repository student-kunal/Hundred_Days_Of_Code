/*
Find the transpose of a matrix.
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
    for (int c = 0; c < cols; ++c) {
        for (int r = 0; r < rows; ++r) printf("%s%d", r ? " " : "", matrix[r][c]);
        putchar('\n');
    }
    return 0;
}
