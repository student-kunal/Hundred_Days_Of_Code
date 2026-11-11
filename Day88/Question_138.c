/*
Print all enum names and integer values using a loop.
*/
#include <stdio.h>

enum Light { RED, YELLOW, GREEN };

int main(void)
{
    const char *names[] = {"RED", "YELLOW", "GREEN"};
    for (enum Light light = RED; light <= GREEN; ++light) printf("%s=%d\n", names[light], (int)light);
    return 0;
}
