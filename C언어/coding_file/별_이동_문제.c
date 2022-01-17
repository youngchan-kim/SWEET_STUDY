#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define X_SIZE 10
#define Y_SIZE 10


int flag = 0;

void Draw(int Map[][X_SIZE])
{
	system("cls");
	for (int y = 0; y < Y_SIZE; y++)
	{
		for (int x = 0; x < X_SIZE; x++)
		{
			if (Map[y][x] == 1 || Map[y][x] == 2)
				printf("��");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("�� ���߱� = d");
}

void Update(int Map[][X_SIZE])
{
	
	for (int y = 0; y < Y_SIZE; y++)
	{

		for (int x = 0; x < X_SIZE; x++)
		{
			if (flag == 0)
			{
				if (Map[y][x] == 1)
				{
					Map[y][x] = 0;
					if (x - 1 < 0)
					{ 
						Map[y][0] = 1;
						flag = 1;
					}
					else
						Map[y][x - 1] = 1;
					break;
				}
			}
			else if (flag == 1)
			{
				if (Map[y][x] == 1)
				{
					Map[y][x] = 0;
					if (x >= X_SIZE-1)
					{
						Map[y][X_SIZE-1] = 1;
						flag = 0;
					}
					else
						Map[y][x + 1] = 1;
					break;
				}
			}
		}	
	}
}

void Stop(int Map[][X_SIZE], int y)
{
	for (int x = 0; x < X_SIZE; x++)
	{
		if (Map[y][x] == 1)
		{
			Map[y][x] = 2;
			return;
		}
	}
}

void main()
{
	int Mapy = X_SIZE;
	int Map[Y_SIZE][X_SIZE] = { 0 };
	char ch;
	for (int y = 0; y < Y_SIZE; y++)
	{
		for (int x = 0; x < X_SIZE; x++)
		{
			if (x == 9)
				Map[y][x] = 1;
		}
	}
	printf("���� ���ðڽ��ϱ�??\n");
	system("pause");
	system("cls");
	while (1)
	{
		Update(Map);
		if (kbhit())
		{
			ch = getch();
			if (ch == 'd' || ch == 'D')
			{
				Mapy--;
				Stop(Map, Mapy);
			}
		}
		Draw(Map);
		Sleep(100);
	}
}