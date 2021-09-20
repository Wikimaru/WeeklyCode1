#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    x = x + y;
    y = x - y;
    x = x - y; 

    printf("%d,%d", x, y);

    return 0;
}