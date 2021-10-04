#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//64010892

void main()
{
	int a;
	scanf("%d", &a);
	if(a%2==0)
	{
		for (int y = 0; y < a; y++)
		{
			for (int x = 0; x < a - 1; x++)
			{
				if(x+y==(a-2)/2||x-y==(a-2)/2||x+y==((a-4)/2)+a||y-x==a/2)
				{
					printf("*");
				}
				else
				{
					printf("-");
				}
			}
			printf("\n");
		}
		for(int y=0;y<a;y++)
		{
			for(int x=0;x<a-1;x++)
			{
				printf("(%d,%d)", x, y);
			}
			printf("\n");
		}
	}
	else
	{
		for (int y = 0; y < a; y++)
		{
			for (int x = 0; x < a; x++)
			{
				//printf("(%d,%d)", x, y);
				if(x+y==a+(a/2)-1||x+y==a/2||x-y==a/2||y-x==a/2)
				{
					printf("*");
				}
				else
				{
					printf("-");
				}
			}
			printf("\n");
		}
		for (int y = 0; y < a; y++)
		{
			for (int x = 0; x < a; x++)
			{
				printf("(%d,%d)", x, y);
			}
			printf("\n");
		}
	}
}