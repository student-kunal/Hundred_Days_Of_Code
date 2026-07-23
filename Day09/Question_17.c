/*
Write a program to find the roots of a quadratic equation and categorize them.
*/
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;
    if (scanf("%lf%lf%lf", &a, &b, &c) != 3) return 1;
    if (a == 0) {
        puts("Not a quadratic equation");
        return 0;
    }
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) puts("Roots are complex");
    else if (discriminant == 0) printf("Roots are real and same: %g\n", -b / (2 * a));
    else {
        double root = sqrt(discriminant);
        printf("Roots are real and different: %g, %g\n", (-b + root) / (2 * a), (-b - root) / (2 * a));
    }
    return 0;
}
