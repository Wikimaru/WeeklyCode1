#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[3];
	for(int i=0;i<3;i++)
	{
		scanf("%d",&a[i]);
	}
	if(a[0]<a[1])
	{
		if(a[0]<=a[2])
		{
			printf("%d", a[0]);
		}
	}
	else if(a[1]<a[2])
	{
		if(a[1]<=a[0])
		{
			printf("%d", a[1]);
		}
	}
	else
	{
		printf("%d", a[2]);
	}
	return 0;
}