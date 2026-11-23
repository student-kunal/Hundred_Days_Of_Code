/*
Create Employee structure with nested Date structure for joining date and print details.
*/
#include <stdio.h>
#include <string.h>

struct Date {
    int day, month, year;
};

struct Employee {
    char name[100];
    int id;
    struct Date joined;
};

int main(void)
{
    struct Employee employee;
    if (scanf(" Employee: %99[^|]| ID: %d | Joining Date: %d%d%d", employee.name, &employee.id,
              &employee.joined.day, &employee.joined.month, &employee.joined.year) != 5) return 1;
    size_t length = strlen(employee.name);
    while (length && employee.name[length - 1] == ' ') employee.name[--length] = '\0';
    printf("Name: %s | ID: %d | Joining Date: %02d/%02d/%04d\n", employee.name, employee.id,
           employee.joined.day, employee.joined.month, employee.joined.year);
    return 0;
}
