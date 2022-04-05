#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

#define TRUE 1
#define FALSE 0
#define EXIT 1

#define WIDTH 10
#define HEIGHT 10

#define X 0
#define	Y 1

#define NULL_0 0
#define WALL 1
#define CHARACTER 2
#define SHOOTINGSTAR 3
#define SHOOTINGSTAR_T 4

#define LEFT 75
#define RIGHT 77


void init(int map[HEIGHT][WIDTH], int character[2])
{
	int Width = (WIDTH * 2) + 5;
	int Height = (HEIGHT) + 4;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			map[y][0] = WALL;
			map[y][x] = NULL_0;
			map[y][WIDTH - 1] = WALL;
		}printf("\n");

	}map[HEIGHT - 1][WIDTH / 2] = CHARACTER;

	if (map[HEIGHT - 1][WIDTH / 2] == CHARACTER)
	{
		character[X] = WIDTH / 2;
		character[Y] = HEIGHT - 1;
	}

}

void MapDraw(int map[HEIGHT][WIDTH])
{
	system("cls");
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
				printf("��");
			else if (map[y][x] == CHARACTER)
				printf("��");
			else if (map[y][x] == NULL_0)
				printf("  ");
			else if (map[y][x] == SHOOTINGSTAR)
				printf("��");
		}printf("\n");
	}
}

void Move(char ch, int map[HEIGHT][WIDTH], int character[2])
{
	system("cls");

	map[character[Y]][character[X]] = NULL_0;
	switch (ch)
	{
	case LEFT:
		if (map[character[Y]][character[X] - 1] != WALL)
			character[X]--;
		break;
	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL)
			character[X]++;
		break;
	}
	map[character[Y]][character[X]] = CHARACTER;
}


void Star(int map[HEIGHT][WIDTH])
{
	int RNum;
	RNum = rand() % (WIDTH - 2) + 1;
	map[0][RNum] = SHOOTINGSTAR;
}
void StarCraft(int map[HEIGHT][WIDTH])
{
	int RNum;
	RNum = rand() % (WIDTH/ (WIDTH / 5));

	if(RNum == 0)
	Star(map);
}


int StarFall(int map[HEIGHT][WIDTH])
{
	int Score = 0;
	for (int y = HEIGHT - 1; y >= 0; y--)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == SHOOTINGSTAR) //�࿡ ���� �ִٸ�
			{
				map[y][x] = NULL_0;	// ���� ���� ���� �����.
				if (y < HEIGHT - 1)// ���� ���� ���پƴ϶��
				{
					map[y + 1][x] = SHOOTINGSTAR;
					// ���� �࿡ ���� �����.
					//�࿡ ���� �ִµ� �� ���� ������ ���̶�� 

				}
				else if (y == HEIGHT - 1)//i�� 0�ε� �ʿ� �������ٿ� ���� �ִٸ� I++�� �����
				{
					Score = Score + 1; //i�� 1�� �� �Ѵ�.
				}
			}
		}
	}
	return Score;
}

int Smash(int map[HEIGHT][WIDTH], int character[2], int flag )
{
	if (map[character[Y]][character[X]] == SHOOTINGSTAR)
	{
		flag = 1;
	}
	return flag;
}


void Msg(int flag)
{
	printf("���� ����\n");
	system("pause");
}

void Game()
{
	char ch;
	int map[HEIGHT][WIDTH] = { 0 };//���⼭ �� ���� �� 
	int character[2];
	int flag = TRUE;
	int Game_Score = 0;
	int Score = 0;
	init(map, character);

	do
	{
		flag = FALSE;
		StarCraft(map);
		MapDraw(map);
		Game_Score = StarFall(map);
		Score += Game_Score;
		printf("SCORE : %d\n", Score);
		flag = Smash(map, character, flag);



		if (kbhit())
		{
			ch = getch();
			if (ch == LEFT || ch == RIGHT)
			{
				Move(ch, map, character);
			}
		}
		Sleep(100);
	} while (flag == FALSE);
	if (flag != FALSE)
	{
		Msg(flag);
	}
}

void main()
{
	srand(time(NULL));
	int Sellect_Num;
	int Sellect_Mode;
	while(TRUE)
	{
		Game();
	}
}