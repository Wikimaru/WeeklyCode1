/*#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int x;
	scanf("%d", &x);
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=(i+x)-1;j++)
		{
			if (j>x-i) 
			{
				printf("*");
			}
			else if((1+(2*(i-1)))<j)
			{
				printf(" ");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}*/