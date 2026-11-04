/*
Create an enum for months and print how many days each month has.
*/
#include <stdio.h>
#include <string.h>

enum Month { JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

int main(void)
{
    char token[16];
    if (scanf("%15s", token) != 1) return 1;
    const char *names[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    for (enum Month m = JAN; m <= DEC; ++m) {
        if (strcmp(token, names[m]) != 0) continue;
        switch (m) {
            case FEB: puts("28 or 29 days"); break;
            case APR: case JUN: case SEP: case NOV: puts("30 days"); break;
            default: puts("31 days"); break;
        }
        return 0;
    }
    return 1;
}
