/*
Define a struct with enum Gender and print person's gender.
*/
#include <stdio.h>
#include <string.h>

enum Gender { MALE, FEMALE, OTHER };

struct Person {
    enum Gender gender;
};

int main(void)
{
    struct Person person;
    char token[32];
    if (scanf(" Gender=%31s", token) != 1) return 1;
    if (strcmp(token, "MALE") == 0) person.gender = MALE;
    else if (strcmp(token, "FEMALE") == 0) person.gender = FEMALE;
    else if (strcmp(token, "OTHER") == 0) person.gender = OTHER;
    else return 1;
    const char *names[] = {"Male", "Female", "Other"};
    puts(names[person.gender]);
    return 0;
}
