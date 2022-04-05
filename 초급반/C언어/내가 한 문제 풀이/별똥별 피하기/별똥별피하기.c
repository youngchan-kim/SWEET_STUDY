#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

#define TRUE 1
#define FALSE 0
#define EXIT 1

#define WIDTH 9
#define HEIGHT 13

#define X 0
#define	Y 1

#define NULL_0 0
#define WALL 1
#define CHARACTER 2
#define SHOOTINGSTAR 3

#define LEFT 75
#define RIGHT 77

#define LIMIT 100
#define STARSPEED_MAX 10
#define TARGETSCORE 10

void Menu()
{
	system("cls");
	printf("==== ���˺� ���ϱ� ====\n");
	printf("     1.���� ����\n");
	printf("     2.���̵� ����\n");
	printf("     3.����\n");
	printf("�Է� : ");

}
void LevelSet(int Level)
{
	system("cls");
	switch (Level)
	{
	case 1:
		printf("���̵� : ====Easy====\n");
		break;
	case 2:
		printf("���̵� : ====Normal====\n");
		break;
	case 3:
		printf("���̵� : ====Hard====\n");
		break;
	case 4:
		printf("���̵� : ====Hell====\n");
		break;
	}
}


void init(int map[HEIGHT][WIDTH], int character[2])
{
	int Width = (WIDTH * 2) + 5;
	int Height = (HEIGHT)+4;
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

void MapDraw(int map[HEIGHT][WIDTH], int Score, int Speed)
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
	printf("SCORE : %d\n", Score);
	printf("Speed : %d\n", Speed);
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

void StarNum(int map[HEIGHT][WIDTH], int MaxStarNumber)
{
	int RNum;
	RNum = (rand() % MaxStarNumber) + 1;

	for (int i = 0; i < RNum; i++)
		Star(map);
}

int StarCraft(int map[HEIGHT][WIDTH], int Craft, int MaxStarNumber, int movemap)
{
	int RNum;
	RNum = rand() % Craft;

	if (RNum == 0)
	{
		StarNum(map, MaxStarNumber);
		movemap = TRUE;
	}
	return movemap;
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

int StarMoveCheck(int map[HEIGHT][WIDTH], int movestarmap)
{
	for (int y = HEIGHT - 1; y >= 0; y--)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == SHOOTINGSTAR) //�࿡ ���� �ִٸ�
			{
				movestarmap = TRUE;
			}
		}
	}
	return movestarmap;
}

int Smash(int map[HEIGHT][WIDTH], int character[2], int flag)
{
	if (map[character[Y]][character[X]] == SHOOTINGSTAR)
	{
		flag = TRUE;
	}
	return flag;
}

void Msg(int flag)
{
	printf("���� ����\n");
	system("pause");
}

void Game(int Craft, int MaxStarNumber, int Level)
{
	char ch;
	int map[HEIGHT][WIDTH] = { 0 };//���⼭ �� ���� �� 
	int character[2];
	int Game_Score = 0, Score = 0, PreviousScore = 0;
	int CountingReturn = 0;
	int Speed = 50;
	int flag = TRUE;
	int movemap = TRUE, movestarmap = TRUE, movecharacter = TRUE;

	int	targetscore = 9;
	init(map, character);
	LevelSet(Level);
	MapDraw(map, Score, Speed);
	do
	{//ȭ��� ������ �ִ� ��� �ʵ�ο�� ĳ���� �̵� �ڵ尡 ���� �� �� �ֵ���
		flag = FALSE;
		if (movemap == TRUE || movestarmap == TRUE || movecharacter == TRUE)
			MapDraw(map, Score, Speed);


		movemap = FALSE;
		movestarmap = FALSE;
		movecharacter = FALSE;

		if (CountingReturn == Speed)
		{
			CountingReturn = 0;
			movemap = StarCraft(map, Craft, MaxStarNumber, movemap);
			movestarmap = StarMoveCheck(map, movestarmap);
			Game_Score = StarFall(map);
			Score += Game_Score;

			if (PreviousScore < Score && Speed > STARSPEED_MAX) //10�� ������ �ӵ��� ������ �ϰڴ�.
			{
				if (targetscore < Score)
				{
					targetscore += TARGETSCORE;
					Speed -= STARSPEED_MAX;
				}
			}
			PreviousScore = Score;
		}

		if (kbhit())
		{
			ch = getch();
			if (ch == LEFT || ch == RIGHT)
			{
				Move(ch, map, character);
				movecharacter = TRUE;
			}
		}

		flag = Smash(map, character, flag);
		CountingReturn++;
		Sleep(10);

	} while (flag == FALSE);
	if (flag != FALSE)
	{
		Msg(flag);
		return;
	}
}


void Modemenu(int Level)
{
	LevelSet(Level);
	printf("==== ���̵� ���� ====\n");
	printf("1.Easy\n");
	printf("2.Normal\n");
	printf("3.Hard\n");
	printf("4.Hell\n");
	printf("5.Return\n");
	printf("�Է� : ");
}

void main()
{
	srand(time(NULL));
	int Craft = 3, MaxStarNumber = 2, Level = 1;
	int Sellect_Num;
	int Sellect_Mode;

	do
	{
		Menu();
		scanf("%d", &Sellect_Num);
		switch (Sellect_Num)
		{
		case 1:
			Game(Craft, MaxStarNumber, Level);
			break;
		case 2:
			do
			{
				Modemenu(Level);
				scanf("%d", &Sellect_Mode);
				Modemenu(Level);
				switch (Sellect_Mode)
				{
				case 1:
					Level = 1;
					Craft = 3;
					MaxStarNumber = 2;
					break;

				case 2:
					Level = 2;
					Craft = 3;
					MaxStarNumber = 3;
					break;

				case 3:
					Level = 3;
					Craft = 2;
					MaxStarNumber = 4;
					break;

				case 4:
					Level = 4;
					Craft = 2;
					MaxStarNumber = 5;
					break;
				}
			} while (Sellect_Mode != 5);
			break;
		}
	} while (Sellect_Num != 3);
}