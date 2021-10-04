#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//64010892
bool even_or_odd(int number)
{
	if(number%2==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void drawEven(int x,int y,int size)
{
	if (x + y == (size - 2) / 2 || x - y == (size - 2) / 2 || x + y == ((size - 4) / 2) + size || y - x == size / 2)
	{
		printf("*");
	}
	else
	{
		printf("-");
	}
	x++;
	if(x>=size-1)
	{
		y++;
		x = 0;
		printf("\n");
	}
	if(y<size)
	{
		drawEven(x, y, size);
	}

}
void drawOdd(int x,int y,int size)
{
	if (x + y == size + (size / 2) - 1 || x + y == size / 2 || x - y == size / 2 || y - x == size / 2)
	{
		printf("*");
	}
	else
	{
		printf("-");
	}
	x++;
	if (x >= size)
	{
		y++;
		x = 0;
		printf("\n");
	}
	if (y < size)
	{
		drawOdd(x, y, size);
	}
}
void main()
{
	int a;
	scanf("%d", &a);
	if(even_or_odd(a))
	{
		drawEven(0, 0, a);
	}
	else
	{
		drawOdd(0, 0, a);
	}
}
