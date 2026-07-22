/*
Write a program to input three numbers and find the largest among them using if–else.
*/
#include <stdio.h>

int main(void)
{
    int a, b, c;
    if (scanf("%d%d%d", &a, &b, &c) != 3) return 1;
    int largest;
    if (a >= b && a >= c) largest = a;
    else if (b >= c) largest = b;
    else largest = c;
    printf("Largest is %d\n", largest);
    return 0;
}
