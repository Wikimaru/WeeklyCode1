#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	char number[4];
	int a=1;
	cin >> number;
	while (strlen(number) > 1)
	{
		if(strlen(number) == 2)
		{
			cout << "0.";
		}
		for (int i = 0; i < strlen(number); i++)
		{
			cout << number[i];
			a = a * ((int)number[i] - 48);
			if(i == strlen(number)-1)
			{
				cout << " = ";
			}
			else
			{
				cout << ".";
			}
		}
		cout << a ;
		cout << "\n";
		sprintf(number,"%d", a);
		a = 1;
	}
	return 0;
}