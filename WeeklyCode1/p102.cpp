/*#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() 
{
	int x;
	scanf("%d",&x);
	for(int i=1;i<x+1;i++)
	{
		for(int j=1;j<x*2;j++)
		{
			//printf("( %d , %d )", j, i);
			if (j<=x-i)
			{
				printf(" ");
			}
			else if(j>=x+i)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	return 0;
}*/