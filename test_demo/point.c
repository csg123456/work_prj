#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void point(char *x) 
{
    printf("%s\n", x);
    strncpy(x, "goodbye world.", strlen("goodbye world."));
    printf("%s\n", x);
}
int main() {

    char *y = malloc(100);
    memset(y, 0, 100);
    strncpy(y, "hello world.", strlen("hello world."));

    printf("%s\n", y);
    point(y);
    printf("%s\n", y);
    return 0;
}