/*
Write a C program that creates a text file named info.txt in write mode. The program should take the user’s name and age as input, and write them to the file using fprintf(). After writing, display a message confirming that the data was successfully saved.
*/
#include <stdio.h>

int main(void)
{
    char name[128];
    int age;
    if (scanf(" Name: %127[^,], Age: %d", name, &age) != 2 || age < 0) return 1;
    FILE *file = fopen("info.txt", "w");
    if (!file) return 1;
    int written = fprintf(file, "Name: %s\nAge: %d\n", name, age);
    if (fclose(file) != 0 || written < 0) return 1;
    puts("File created successfully! Data written to info.txt");
    return 0;
}
