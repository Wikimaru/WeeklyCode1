#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <conio.h>
//###ÊÔÃÀ¾ ÀÑ¡´ÕºØµÃ 64010892###
void gotoxy(int x, int y);
void draw_ship(int,int);
void erase_ship(int x, int y);
void main()
{	
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do
	{
		if(_kbhit())
		{
			ch = _getch();
			if(ch=='a'&&x>=2)
			{
				erase_ship(x, y);
				draw_ship(--x, y);
			}
			if(ch=='d'&&x<=71)
			{
				erase_ship(x, y);
				draw_ship(++x, y);
			}
			if(ch=='w'&&y>=1)
			{
				erase_ship(x, y);
				draw_ship(x, --y);
			}
			if(ch=='s'&&y<=79)
			{
				erase_ship(x, y);
				draw_ship(x, ++y);
			}
			fflush(stdin);
		}
		Sleep(50);
	} while (ch != 'x');
}
//###ÊÔÃÀ¾ ÀÑ¡´ÕºØµÃ 64010892###
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
//###ÊÔÃÀ¾ ÀÑ¡´ÕºØµÃ 64010892###
void draw_ship(int x,int y)
{
	gotoxy(x,y);
	printf("/=|%d|=\\ ",x);
}
//###ÊÔÃÀ¾ ÀÑ¡´ÕºØµÃ 64010892###
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("         ");
}