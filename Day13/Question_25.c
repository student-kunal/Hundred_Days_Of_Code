/*
Write a program to implement a basic calculator using switch-case for +, -, *, /, %.
*/
#include <stdio.h>

int main(void)
{
    int a, b;
    if (scanf("%d%d", &a, &b) != 2) return 1;
    char operation;
    if (scanf(" %c", &operation) != 1) return 1;
    switch (operation) {
        case '+': printf("%lld\n", (long long)a + b); break;
        case '-': printf("%lld\n", (long long)a - b); break;
        case '*': printf("%lld\n", (long long)a * b); break;
        case '/':
            if (b == 0) puts("undefined");
            else printf("%g\n", (double)a / b);
            break;
        case '%':
            if (b == 0) puts("undefined");
            else printf("%lld\n", (long long)a % b);
            break;
        default: return 1;
    }
    return 0;
}
