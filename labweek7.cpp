#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
void setcursor(bool);
void setcolor(int, int);
void move(int);
void Bulletupdate();
void ShootBullet();
void erase_ship(int x, int y);
void createStar(int);
//========Bullet=========//
int bulletCooldown = 2, BulletNo = 0,Mag=5;
struct Bullet
{
	int x, y;
	bool shoot;
};
Bullet bullet[10];
//=========Ship==========//
int moveDirect = 1;	int x = 38, y = 20;
//=========Star==========//
struct star
{
	int x, y;
	bool alive;
};
star Enemy[20];
//========================//
int score=0;

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	setcolor(1, 8); gotoxy(x, y); printf(" <-%d-> ",Mag);
}
void addScore()
{
	score++;
	gotoxy(70, 0);
	setcolor(3, 0);
	printf("Score:%d", score);
}
int main()
{
	srand(time(NULL));
	createStar(20);
	char ch = '.';
	draw_ship(x, y);
	setcolor(3, 0);
	gotoxy(70, 0);
	printf("Score:%d", score);
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
			if(ch==' '&&bulletCooldown<=0&&Mag>0)
			{
				ShootBullet();
				Beep(440, 30);
			}
			fflush(stdin);
		}//End_keyboard

		//move Ship
		move(moveDirect);
		Bulletupdate();
		Sleep(20);
	} while (ch != 'x');
	return 0;
}
void createStar(int numberOfStar)
{
	for(int i=0;i<numberOfStar;i++)
	{
		setcolor(3, 0);
		Enemy[i].alive = true;
		bool canSpawn = false;
		while (!canSpawn)
		{
			canSpawn = true;
			Enemy[i].x = (rand() % 61) + 10;
			Enemy[i].y = (rand() % 4) + 2;
			for(int j=0;j<i;j++)
			{
				if(i!=j&&Enemy[i].x==Enemy[j].x&&Enemy[i].y==Enemy[j].y)
				{
					canSpawn = false;
				}
			}

		}
		gotoxy(Enemy[i].x, Enemy[i].y);
		printf("*");
	}
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
	bullet[BulletNo].x = x + 3;
	bullet[BulletNo].y = y - 1;
	bullet[BulletNo].shoot = true;
	BulletNo++;
	Mag--;
	if(BulletNo>=10)
	{			
		BulletNo = 0;
	}
}
void Bulletupdate()
{
	bool soundplay = false;
	for(int i=0;i<10;i++)
	{
		if(bullet[i].y > 0&&bullet[i].shoot)
		{
			setcolor(6, 0);
			bullet[i].y--;
			gotoxy(bullet[i].x, bullet[i].y);
			printf("0");
			gotoxy(bullet[i].x, bullet[i].y+1);
			printf(" ");
			soundplay = true;
		}
		if(bullet[i].shoot&&bullet[i].y<=1)
		{
			gotoxy(bullet[i].x, bullet[i].y);
			printf(" ");
			bullet[i].shoot = false;
			Mag++;
		}
		for(int j=0;j<20;j++)
		{
			if(bullet[i].x==Enemy[j].x&&bullet[i].shoot&&Enemy[j].alive)
			{
				if(bullet[i].y==Enemy[j].y)
				{
					setcolor(0, 0);
					gotoxy(bullet[i].x, bullet[i].y);
					printf(" ");
					bullet[i].shoot = false;
					Mag++;
					bool canSpawn = false;
					while (!canSpawn)
					{
						canSpawn = true;
						Enemy[j].x = (rand() % 61) + 10;
						Enemy[j].y = (rand() % 4) + 2;
						for (int k = 0; k < 20; k++)
						{
							if(j!=k&&Enemy[k].x==Enemy[j].x&&Enemy[k].y==Enemy[j].y||(Enemy[j].x==bullet[i].y&&Enemy[j].y==bullet[i].y))
							{
								canSpawn = false;
							}
						}
					}
					setcolor(3, 0);
					gotoxy(Enemy[j].x, Enemy[j].y);
					printf("*");
					addScore();
					Beep(240, 30);
				}
			}
		}
	}
	if (soundplay)
	{
		Beep(200, 30);
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