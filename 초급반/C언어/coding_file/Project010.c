#include<stdio.h>
#include<Windows.h>

void main()
{
	while (1)
	{
		system("cls");
		printf("전화 거는 중 ☏");
		for (int i = 0; i < 3; i++)
		{
			Sleep(1000);
			printf(".");
		}
		Sleep(1000);
	}
}