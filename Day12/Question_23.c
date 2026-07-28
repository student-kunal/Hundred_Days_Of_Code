/*
Write a program to calculate library fine based on late days as follows: 
First 5 days late: ₹2/day 
Next 5 days late: ₹4/day 
Next 20 days days late: ₹6/day 
More than 30 days: Membership Cancelled.
*/
#include <stdio.h>

int main(void)
{
    int days;
    if (scanf("%d", &days) != 1) return 1;
    if (days < 0) return 1;
    if (days > 30) puts("Membership Cancelled");
    else {
        int fine = 2 * days;
        if (days > 5) fine += 2 * (days - 5);
        if (days > 10) fine += 2 * (days - 10);
        printf("Fine ₹%d\n", fine);
    }
    return 0;
}
