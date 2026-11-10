/*
Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.
*/
#include <stdio.h>
#include <string.h>

enum Role { ADMIN, USER, GUEST };

int main(void)
{
    char token[32];
    if (scanf("%31s", token) != 1) return 1;
    enum Role selection;
    if (strcmp(token, "ADMIN") == 0) selection = ADMIN;
    else if (strcmp(token, "USER") == 0) selection = USER;
    else if (strcmp(token, "GUEST") == 0) selection = GUEST;
    else return 1;
    switch (selection) {
        case ADMIN: puts("Welcome Admin!"); break;
        case USER: puts("Welcome User!"); break;
        case GUEST: puts("Welcome Guest!"); break;
    }
    return 0;
}
