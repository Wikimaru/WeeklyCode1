#include<stdio.h>
#include<windows.h>
#include<conio.h>
void setcursor(bool);
void setcolor(int, int);
void move(int);
void Bulletupdate();
void ShootBullet();
void erase_ship(int x, int y);
//========Bullet=========//
int bulletPosX[50], bulletPosY[50], bulletCooldown = 2, BulletNo = 0,Mag=5;
bool bullet[50];
//=========Ship==========//
int moveDirect = 1;	int x = 38, y = 20;

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	setcolor(2, 4); gotoxy(x, y); printf(" <-%d-> ",Mag);
}
int main()
{
	char ch = '.';
	draw_ship(x, y);
	setcolor(3, 0);
	setcursor(false);
	//==========Main_Loop==========//
	do {
		//Keyboard
		if (_kbhit()) 
		{
			ch = _getch();
			if (ch == 'a') 
			{
				moveDirect = 0;
			}
			if (ch == 's') 
			{
				moveDirect = 1;
			}
			if(ch=='d')
			{
				moveDirect = 2;
			}
			if(ch=='w'&&bulletCooldown<=0&&Mag>0)
			{
				ShootBullet();
			}
			fflush(stdin);
		}//End_keyboard

		//move Ship
		move(moveDirect);
		Bulletupdate();
		Sleep(30);
	} while (ch != 'x');
	return 0;
}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void ShootBullet()
{
	bulletPosX[BulletNo] = x + 3;
	bulletPosY[BulletNo] = y - 1;
	bullet[BulletNo] = true;
	BulletNo++;
	Mag--;
	if(BulletNo>=50)
	{			
		BulletNo = 0;
	}
}
void Bulletupdate()
{
	for(int i=0;i<50;i++)
	{
		if(bulletPosY[i] > 0)
		{
			setcolor(6, 0);
			bulletPosY[i]--;
			gotoxy(bulletPosX[i], bulletPosY[i]);
			printf("0");
			gotoxy(bulletPosX[i], bulletPosY[i]+1);
			printf(" ");
		}
		if(bullet[i]&&bulletPosY[i]<=0)
		{
			gotoxy(bulletPosX[i], bulletPosY[i]);
			printf(" ");
			bullet[i] = false;
			Mag++;
		}
	}

	if(bulletCooldown>0)
	{
		bulletCooldown--;
	}
}
void move(int a)
{//  0==left  1==stop  2==right
	if(a==0&&x>0)
	{
		erase_ship(x, y);
		draw_ship(--x, y);
	}
	else if(a==1)
	{
		erase_ship(x, y);
		draw_ship(x, y);
	}
	else if(a==2&&x<73)
	{
		erase_ship(x, y);
		draw_ship(++x, y);
	}
}
void erase_ship(int x, int y)
{
	setcolor(0, 0);
	gotoxy(x, y);
	printf("         ");
}