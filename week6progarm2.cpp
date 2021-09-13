#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int z;
	scanf("%d", &z);
	for (int y = 0; y < (z * 2) - 1; y++)
	{
		for (int x = 0; x < (z * 2) - 1; x++)
		{
			if (x >= y&&x+y<(z*2)-1)
			{
				printf("*");
			}
			else if (x + y >= (z * 2) - 2&&x<=y)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}