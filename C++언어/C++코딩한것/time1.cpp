#include<iostream>
#include<time.h>
#include<Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void main()
{
	int OldClock, CurClock, i = 0;
	OldClock = clock();
	while (1)
	{
		CurClock = clock();
		if (CurClock - OldClock >= 1000)
		{
			i++;
			gotoxy(10, 10);
			cout << "Cout :" << i;
			OldClock = CurClock;
		}
	}
}