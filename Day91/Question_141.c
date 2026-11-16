/*
Define a structure Student with name, roll_no, and marks, then read and print one student's data.
*/
#include <stdio.h>

struct Student {
    char name[100];
    int roll_no;
    double marks;
};

int main(void)
{
    struct Student student;
    if (scanf(" Name: %99[^\n] Roll: %d Marks: %lf", student.name, &student.roll_no, &student.marks) != 3) return 1;
    printf("Name: %s | Roll: %d | Marks: %g\n", student.name, student.roll_no, student.marks);
    return 0;
}
