/*
Check if the elements on the diagonal of a matrix are distinct.
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
    int length = rows < cols ? rows : cols;
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < i; ++j) {
            if (matrix[i][i] == matrix[j][j]) {
                puts("False");
                return 0;
            }
        }
    }
    puts("True");
    return 0;
}
