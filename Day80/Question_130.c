/*
Store multiple student records (name, roll number, marks) into a file using fprintf(). Then read them using fscanf() and display each record.
*/
#include <stdio.h>

int main(void)
{
    int count;
    if (scanf("%d", &count) != 1 || count < 0) return 1;
    FILE *file = fopen("students.txt", "w");
    if (!file) return 1;
    char name[100];
    int roll;
    double marks;
    for (int i = 0; i < count; ++i) {
        if (scanf("%99s%d%lf", name, &roll, &marks) != 3 ||
            fprintf(file, "%s %d %.17g\n", name, roll, marks) < 0) return 1;
    }
    if (fclose(file) != 0) return 1;
    file = fopen("students.txt", "r");
    if (!file) return 1;
    for (int i = 0; i < count; ++i) {
        if (fscanf(file, "%99s%d%lf", name, &roll, &marks) != 3) return 1;
        printf("Name: %s | Roll: %d | Marks: %g\n", name, roll, marks);
    }
    if (fclose(file) != 0) return 1;
    return 0;
}
