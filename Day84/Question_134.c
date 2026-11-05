/*
Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.
*/
#include <stdio.h>
#include <string.h>

enum Status { SUCCESS, FAILURE, TIMEOUT };

int main(void)
{
    char token[32];
    if (scanf("%31s", token) != 1) return 1;
    enum Status selection;
    if (strcmp(token, "SUCCESS") == 0) selection = SUCCESS;
    else if (strcmp(token, "FAILURE") == 0) selection = FAILURE;
    else if (strcmp(token, "TIMEOUT") == 0) selection = TIMEOUT;
    else return 1;
    switch (selection) {
        case SUCCESS: puts("Operation succeeded"); break;
        case FAILURE: puts("Operation failed"); break;
        case TIMEOUT: puts("Operation timed out"); break;
    }
    return 0;
}
