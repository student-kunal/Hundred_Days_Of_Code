/*
Write a program to calculate simple and compound interest for given principal, rate, and time.
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    double principal, rate, years;
    if (scanf("%lf%lf%lf", &principal, &rate, &years) != 3) return 1;
    double simple = principal * rate * years / 100;
    double compound = principal * (pow(1 + rate / 100, years) - 1);
    printf("Simple Interest=%g, Compound Interest=%g\n", simple, round(compound * 100) / 100);
    return 0;
}
