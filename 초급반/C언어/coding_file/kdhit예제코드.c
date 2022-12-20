#include<stdio.h>
#include<Windows.h>
#include<conio.h>

void Draw(int Map[][10])
{
	system("cls");
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (Map[y][x] == 1 || Map[y][x] == 2)
				printf("☆");
			else
				printf("  ");
		}
		printf("\n");
	}
	printf("별 멈추기 = d");
}

void Update(int Map[][10])
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (Map[y][x] == 1)
			{
				Map[y][x] = 0;
				if(x-1 < 0)
					Map[y][9] = 1;
				else
					Map[y][x - 1] = 1;
				break;
			}		
		}
	} 
}

void Stop(int Map[][10], int y)
{
	for(int x =0; x <10 ;x ++)
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
	int Mapy = 10;
	int Map[10][10] = { 0 };
	char ch;
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (x == 9)
				Map[y][x] = 1;
		}
	}
	printf("별을 보시겠습니까??\n");
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