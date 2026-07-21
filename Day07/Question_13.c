/*
Write a program to input a year and check whether it is a leap year or not using conditional statements.
*/
#include <stdio.h>

int main(void)
{
    int year;
    if (scanf("%d", &year) != 1) return 1;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        puts("Leap year");
    else
        puts("Not a leap year");
    return 0;
}
