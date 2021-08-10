#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int x,min;
	for(int i=0;i<3;i++)
	{
		scanf("%d",&x);
		if(i==0)
		{
			min = x;
		}
		if(min>x)
		{
			min = x;
		}

	}
	printf("%d", min);
	return 0;
}