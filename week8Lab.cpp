#include <stdio.h>
#include <windows.h>
#include <time.h>
#define screen_x 80
#define screen_y 25
HANDLE rHnd;
HANDLE wHnd;
DWORD fdwMode;
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
CHAR_INFO consoleBuffer[screen_x * screen_y];
struct Ship
{
	int x, y;
};
Ship ship;
struct Star
{
	int x, y;
};
int numOfStar = 80;
Star star[80];
int HP = 9;
bool play = true;
void clear_buffer()
{
	for (int y = 0; y < screen_y; ++y)
	{
		for (int x = 0; x < screen_x; ++x)
		{
			consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
			consoleBuffer[x + screen_x * y].Attributes = 7;
		}
	}
}
void fill_buffer_to_console()
{
	WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos,&windowSize);
}
int setMode()
{
	rHnd = GetStdHandle(STD_INPUT_HANDLE);
	fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
		ENABLE_MOUSE_INPUT;
	SetConsoleMode(rHnd, fdwMode);
	return 0;
}
int setConsole(int x, int y)
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	return 0;
}
void star_fall()
{
	int i;
	for (i = 0; i < numOfStar; i++) 
	{
		if (star[i].y >= screen_y - 1) 
		{
			star[i] = { (rand() % screen_x),1 };
		}
		else 
		{
			star[i] = { star[i].x,star[i].y + 1 };
		}
	}
}
void init_star()
{
	for (int i = 0; i < numOfStar; i++)
	{
		star[i] = { (rand() % screen_x), (rand() % screen_y) };
	}
}
void fill_everything_to_buffer()
{
	consoleBuffer[ship.x + screen_x * ship.y].Char.AsciiChar = '=';
	consoleBuffer[ship.x + 1 + screen_x * ship.y].Char.AsciiChar = '0';
	consoleBuffer[ship.x + 2 + screen_x * ship.y].Char.AsciiChar = '=';
	
	for (int i = 0; i < numOfStar; i++)
	{
		consoleBuffer[star[i].x + screen_x * star[i].y].Char.AsciiChar = '*';
		consoleBuffer[star[i].x + screen_x * star[i].y].Attributes = 7;
	}
	fill_buffer_to_console();
}
bool Hit()
{
	for(int i=0;i<numOfStar;i++)
	{
		if ((star[i].x == ship.y || star[i].x == ship.x + 1 || star[i].x == ship.x + 2) && star[i].y == ship.y)
		{
			star[i] = {(rand() % screen_x), 1 };
			return true;
		}
	}
	return false;
}
void CheckCollision()
{
	for (int i = 0; i < numOfStar; i++)
	{
		if ((star[i].x == ship.y || star[i].x == ship.x + 1 || star[i].x == ship.x + 2) && star[i].y == ship.y)
		{
			star[i] = { (rand() % screen_x), 1 };
			HP--;
		}
		if (HP == 0)
		{
			play = false;
		}
	}
}
int main()
{
	srand(time(NULL));
	DWORD numEvents = 0;
	DWORD numEventsRead = 0;
	setConsole(screen_x, screen_y);
	setMode();
	init_star();
	while (play)
	{
		GetNumberOfConsoleInputEvents(rHnd, &numEvents);
		if (numEvents != 0) 
		{
			INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
			ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
			for (DWORD i = 0; i < numEventsRead; ++i) 
			{
				if (eventBuffer[i].EventType == KEY_EVENT &&eventBuffer[i].Event.KeyEvent.bKeyDown == true) 
				{
					if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) 
					{
						play = false;
					}
				}
				else if (eventBuffer[i].EventType == MOUSE_EVENT) 
				{
					int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
					int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
					if (eventBuffer[i].Event.MouseEvent.dwButtonState &FROM_LEFT_1ST_BUTTON_PRESSED) 
					{
					}
					else if (eventBuffer[i].Event.MouseEvent.dwButtonState &RIGHTMOST_BUTTON_PRESSED) 
					{
					}
					else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED)
					{
						//printf("mouse position : (%d,%d)\n", posx, posy);
						ship.x = posx;
						ship.y = posy;
					}
				}
			}
			delete[] eventBuffer;
		}
		
		star_fall();
		CheckCollision();
		clear_buffer();
		fill_everything_to_buffer();
		Sleep(100);
	}
	return 0;
}