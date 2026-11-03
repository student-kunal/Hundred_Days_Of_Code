/*
Define an enum for traffic lights (RED, YELLOW, GREEN) and print 'Stop', 'Wait', or 'Go' based on its value.
*/
#include <stdio.h>
#include <string.h>

enum Light { RED, YELLOW, GREEN };

int main(void)
{
    char token[32];
    if (scanf("%31s", token) != 1) return 1;
    enum Light selection;
    if (strcmp(token, "RED") == 0) selection = RED;
    else if (strcmp(token, "YELLOW") == 0) selection = YELLOW;
    else if (strcmp(token, "GREEN") == 0) selection = GREEN;
    else return 1;
    switch (selection) {
        case RED: puts("Stop"); break;
        case YELLOW: puts("Wait"); break;
        case GREEN: puts("Go"); break;
    }
    return 0;
}
