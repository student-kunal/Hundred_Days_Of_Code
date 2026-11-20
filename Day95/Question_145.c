/*
Return a structure containing top student's details from a function.
*/
#include <stdio.h>

struct Student {
    char name[100];
    int roll_no;
    double marks;
};

static struct Student top_student(const struct Student students[], int count)
{
    int best = 0;
    for (int i = 1; i < count; ++i) {
        if (students[i].marks > students[best].marks) best = i;
    }
    return students[best];
}

int main(void)
{
    int count;
    if (scanf("%d", &count) != 1 || count < 1 || count > 1000) return 1;
    struct Student students[1000];
    for (int i = 0; i < count; ++i) {
        if (scanf("%99s%d%lf", students[i].name, &students[i].roll_no, &students[i].marks) != 3) return 1;
    }
    struct Student best = top_student(students, count);
    printf("Top Student: %s | Roll: %d | Marks: %g\n", best.name, best.roll_no, best.marks);
    return 0;
}
