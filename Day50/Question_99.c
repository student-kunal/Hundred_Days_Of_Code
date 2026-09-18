/*
Change the date format from dd/04/yyyy to dd-Apr-yyyy.
*/
#include <stdio.h>

int main(void)
{
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int day, month, year;
    if (scanf("%d/%d/%d", &day, &month, &year) != 3 || day < 1 || day > 31 ||
        month < 1 || month > 12 || year < 1) return 1;
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) days[1] = 29;
    if (day > days[month - 1]) return 1;
    printf("%02d-%s-%04d\n", day, months[month - 1], year);
    return 0;
}
