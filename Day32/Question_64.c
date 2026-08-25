/*
Find the digit that occurs the most times in an integer number.
*/
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int count[10] = {0}, ch;
    while ((ch = getchar()) != EOF) {
        if (isdigit(ch)) ++count[ch - '0'];
    }
    int best = 0;
    for (int digit = 1; digit < 10; ++digit) {
        if (count[digit] > count[best]) best = digit;
    }
    if (count[best] == 0) return 1;
    printf("%d\n", best);
    return 0;
}
