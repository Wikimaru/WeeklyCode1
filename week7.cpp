#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

 int main()
 {
	 int x, y;
	 scanf("%d",&x);
	 y = x;
	 scanf("%d", &x);
	 printf("%d,%d",x,y);
	 return 0;
 }