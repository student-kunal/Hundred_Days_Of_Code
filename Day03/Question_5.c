/*
Write a program to convert temperature from Celsius to Fahrenheit.
*/
#include <stdio.h>

int main(void)
{
    double celsius;
    if (scanf("%lf", &celsius) != 1) return 1;
    printf("Fahrenheit=%g\n", celsius * 9 / 5 + 32);
    return 0;
}
