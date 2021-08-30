#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	long int a, b = 1,x,y,z;
	cin >> a;
	while (a > 9)
	{
		b = b * (a % 10);
		x = a % 10;
		a = a / 10;
		//=============
		b = b * (a % 10);
		y = a % 10;
		a = a / 10;
		//=============
		b = b * (a % 10);
		z = a % 10;
		a = a / 10;
		cout <<z<<"."<<x<<"."<<y<<"="<< b << endl;
		a = b;
		b = 1;
	}
	return 0;
}