/*
Perform diagonal traversal of a matrix.
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
    for (int diagonal = 0; diagonal < rows + cols - 1; ++diagonal) {
        int first = diagonal < cols ? 0 : diagonal - cols + 1;
        int last = diagonal < rows ? diagonal : rows - 1;
        for (int i = first; i <= last; ++i) {
            int r = diagonal % 2 ? i : last - (i - first);
            printf("%s%d", diagonal ? " " : "", matrix[r][diagonal - r]);
        }
    }
    putchar('\n');
    return 0;
}
