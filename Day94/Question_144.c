/*
Write a function that accepts a structure as parameter and prints its members.
*/
#include <stdio.h>

struct Student {
    char name[100];
    int roll_no;
    double marks;
};

static void print_student(struct Student student)
{
    printf("Name: %s | Roll: %d | Marks: %g\n", student.name, student.roll_no, student.marks);
}

int main(void)
{
    struct Student student;
    if (scanf(" Student: %99s%d%lf", student.name, &student.roll_no, &student.marks) != 3) return 1;
    print_student(student);
    return 0;
}
