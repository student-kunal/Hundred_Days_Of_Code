/*
Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.
*/
#include <stdio.h>
#include <string.h>

enum Operation { ADD, SUBTRACT, MULTIPLY };

int main(void)
{
    char token[32];
    int a, b;
    if (scanf("%31s%d%d", token, &a, &b) != 3) return 1;
    enum Operation selection;
    if (strcmp(token, "ADD") == 0) selection = ADD;
    else if (strcmp(token, "SUBTRACT") == 0) selection = SUBTRACT;
    else if (strcmp(token, "MULTIPLY") == 0) selection = MULTIPLY;
    else return 1;
    switch (selection) {
        case ADD: printf("%lld\n", (long long)a + b); break;
        case SUBTRACT: printf("%lld\n", (long long)a - b); break;
        case MULTIPLY: printf("%lld\n", (long long)a * b); break;
    }
    return 0;
}
