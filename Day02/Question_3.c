/*
Write a program to calculate the area and perimeter of a rectangle given its length and breadth.
*/
#include <stdio.h>

int main(void)
{
    double length, breadth;
    if (scanf("%lf%lf", &length, &breadth) != 2) return 1;
    if (length < 0 || breadth < 0) return 1;
    printf("Area=%g, Perimeter=%g\n", length * breadth, 2 * (length + breadth));
    return 0;
}
