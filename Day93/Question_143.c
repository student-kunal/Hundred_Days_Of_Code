/*
Find and print the student with the highest marks.
*/
#include <stdio.h>

struct Student {
    char name[100];
    int roll_no;
    double marks;
};

int main(void)
{
    int count;
    if (scanf("%d", &count) != 1 || count < 1 || count > 1000) return 1;
    struct Student students[1000];
    for (int i = 0; i < count; ++i) {
        if (scanf("%99s%d%lf", students[i].name, &students[i].roll_no, &students[i].marks) != 3) return 1;
    }
    int best = 0;
    for (int i = 1; i < count; ++i) {
        if (students[i].marks > students[best].marks) best = i;
    }
    printf("Topper: %s (Marks: %g)\n", students[best].name, students[best].marks);
    return 0;
}
