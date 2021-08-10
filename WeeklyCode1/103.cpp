#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void No3();
void No1();
void No2();
int main() 
{
	//No1();
	No3();
	//No2();
}
void No3()
{
	int k;
	scanf("%d", &k);
	for (int y = 1; y <= k; y++)
	{
		for (int x = 1; x <= k; x++)
		{
			//printf("(%d,%d)",x,y);
			if (x == 1 || y == 1 || x == k || y == k)
			{
				printf("x");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
void No1()
{
	int k,a=2;
	bool stop=false;
	scanf("%d", &k);
	while (!stop)
	{
		if (k % a==0) 
		{
			k = k / a;
			printf("%d ",a);
		}
		else 
		{
			a++;
		}
		if(a>=k)
		{
			printf("%d", k);
			stop = true;
		}
	}
}
void No2()
{
	int k,l,a=2,z=1;
	bool stop = false,min_K;
	scanf("%d %d", &k,&l);
	if (k < l) 
	{
		min_K = true;
	}
	else
	{
		min_K = false;
	}
	while(!stop)
	{
		if(k%a==0&&l%a==0)
		{
			k = k / a;
			l = l / a;
			z = z * a;
		}
		else
		{
			a++;
		}
		if(min_K&&k<=a)
		{
			stop = true;
			printf("%d", z);
		}
		else if(!min_K&&l<=a)
		{
			stop = true;
			printf("%d", z);
		}
	}
}