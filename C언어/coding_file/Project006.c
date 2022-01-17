//�߰��� �� 
//1. �Ա��� �ⱸ
//2. ���� ������ ������ ����
//3. �ѹ� ������ ��Ż�� ������
//4. �������� �̿��� ���μ���
//5. üũ����Ʈ�� �̿��� ��¥ ��Ż �����ϱ�

#include<stdio.h>
#include<conio.h>
#include<Windows.h>
//////////////////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//���� ����
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////
#define WALL 1
#define NULL 0
#define Y 0
#define X 1
#define CHARACTER 2
#define POTAL_MAX 6//��Ż ����
#define START_MAX 1
#define EXIT_POINT 9
#define ENTRY_START 10
#define EXIT_START 20
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define WIDTH 21
#define HEIGHT 22

#define BROKEN_WALL_MAX 1 //�μ��� ���� ����
#define BROKEN_WALL 30
#define BROKEN_WALL_LIFE 1 //�� ����

#define WEAPON 40
#define WEAPON_MAX 3 //���� ����
#define WEAPON_LIFE 0

#define CHECK_POINT 7
#define CHECK_POINT_MAX 1 //üũ����Ʈ�� ����

#define FAKE_POTAL 8
#define FAKE_POTAL_MAX 1 //��¥ ������ �� ����

#define LIFE 3

int map[HEIGHT][WIDTH] = {
  { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
  { 1,	2,	1,	0,	0,	30,	0,	0,	0,	0,	0,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	24,	1,	23,	1,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	10,	1,	22,	0,	0,	40,	14,	1,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	11,	1,	21,	0,	0,	41,	14,	1,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	12,	1,	20,	0,	0,	42,	14,	1,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	13,	1,	0,	0,	0,	0,	0,	1,  0,	0,	8,	8,	15,	8,	8,	7,	1 },
  { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,  1,	1,	1,	1,	1,	1,	1,	1,	1 },
  { 1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,	0,	0,	0,	0,	1 },
  { 1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	25,	0,	0,	0,	0,	0,	9,	1 },
  { 1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1 },
  { 90,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,  0,	0,	0,	0,	0,	0,	0,	0,	0 }, };
int Life = LIFE;
int character[2];
int Exit_Point[START_MAX][2];
int Entry_Potal[POTAL_MAX][2];
int Exit_Potal[POTAL_MAX][2];
int Check_Point[CHECK_POINT_MAX][2];
int Weapon[WEAPON_MAX][2];
int Weapon_life = WEAPON_LIFE;
int Broken_Wall[BROKEN_WALL_MAX][2];
int Broken_life = BROKEN_WALL_LIFE;
int Fake_Potal[FAKE_POTAL_MAX][2];

int LastObjectIndex = NULL;
int flag = 0;
int Win = 0;
int Lose = 0;

void Init()
{
	int Width = (WIDTH * 2) + 1;
	int Height = HEIGHT + 1;
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", Height, Width);
	system(buf);


	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == CHARACTER)
			{
				character[X] = x;
				character[Y] = y;
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX)
			{
				Entry_Potal[map[y][x] - ENTRY_START][X] = x;
				Entry_Potal[map[y][x] - ENTRY_START][Y] = y;
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX)
			{
				Exit_Potal[map[y][x] - EXIT_START][X] = x;
				Exit_Potal[map[y][x] - EXIT_START][Y] = y;
			}
			else if (map[y][x] >= WEAPON && map[y][x] < WEAPON + WEAPON_MAX)
			{
				Weapon[map[y][x] - WEAPON][X] = x;
				Weapon[map[y][x] - WEAPON][Y] = y;
			}
			else if (map[y][x] >= BROKEN_WALL && map[y][x] < BROKEN_WALL + BROKEN_WALL_MAX)
			{
				Broken_Wall[map[y][x] - BROKEN_WALL][X] = x;
				Broken_Wall[map[y][x] - BROKEN_WALL][Y] = y;
			}
			else if (map[y][x] >= CHECK_POINT && map[y][x] < CHECK_POINT + CHECK_POINT_MAX)
			{
				Check_Point[map[y][x] - CHECK_POINT][X] = x;
				Check_Point[map[y][x] - CHECK_POINT][Y] = y;
			}
			else if (map[y][x] >= FAKE_POTAL && map[y][x] < FAKE_POTAL + FAKE_POTAL_MAX)
			{
				Fake_Potal[map[y][x] - FAKE_POTAL][X] = x;
				Fake_Potal[map[y][x] - FAKE_POTAL][Y] = y;
			}
			else if (map[y][x] == EXIT_POINT)
			{
				Exit_Point[map[y][x] - EXIT_POINT][X] = x;
				Exit_Point[map[y][x] - EXIT_POINT][Y] = y;
			}

		}
	}
}
void MapDraw()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == WALL)
				printf("��");
			else if (map[y][x] == CHARACTER)
			{
				RED
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] >= ENTRY_START && map[y][x] < ENTRY_START + POTAL_MAX)
			{
				BLUE
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] >= EXIT_START && map[y][x] < EXIT_START + POTAL_MAX)
			{
				YELLOW
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] >= WEAPON && map[y][x] < WEAPON + WEAPON_MAX)
			{
				GOLD
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] >= BROKEN_WALL && map[y][x] < BROKEN_WALL + BROKEN_WALL_MAX)
			{
				SKY_BLUE
					if (Broken_life == 3)
						printf("��");
					else if (Broken_life == 2)
						printf("��");
					else if (Broken_life == 1)
						printf("��");
					else if (Broken_life == 0)
						printf("  ");
				ORIGINAL

			}
			else if (map[y][x] == EXIT_POINT)
			{
				BLUE_GREEN
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] == FAKE_POTAL)
			{
				if (flag == 0)
					BLUE
				else
					RED
					printf("��");
				ORIGINAL
			}
			else if (map[y][x] == CHECK_POINT)
			{
				SKY_BLUE
					printf("��");
				ORIGINAL
			}

			else if (map[y][x] == NULL)
				printf("  ");

		}
		printf("\n");
	}
}

void MoveCheck()
{
	int index = map[character[Y]][character[X]];

	if (index >= ENTRY_START && index < ENTRY_START + POTAL_MAX)
	{
		map[character[Y]][character[X]] = LastObjectIndex;
		character[X] = Exit_Potal[index - ENTRY_START][X];
		character[Y] = Exit_Potal[index - ENTRY_START][Y];
	}
	else if (index >= WEAPON && index < WEAPON + WEAPON_MAX)
	{
		map[character[Y]][character[X]] = LastObjectIndex;
		Weapon_life += 1;
	}
	else if (index >= BROKEN_WALL && index < BROKEN_WALL + BROKEN_WALL_MAX)
	{
		character[X] --;
		if (Weapon_life > 0)
		{
			Weapon_life--;
			Broken_life--;
		}
		else if (Broken_life > 0 && Weapon_life < 1)
		{
			Life--;
		}
		else if (Broken_life < 1)
		{
			character[X] ++;
			map[character[Y]][character[X]] = LastObjectIndex;

		}

	}
	else if (index == CHECK_POINT)
	{
		map[character[Y]][character[X]] = LastObjectIndex;
		flag = 1;
	}
	else if (index == FAKE_POTAL)
	{
		printf("�߸��� ��Ż�� Ÿ�� �Ǿ� �й��Ͽ����ϴ�.");
		Lose = 1;
	}
	else if (index == EXIT_POINT)
	{
		Win = 1;
		printf("Ŭ����!!");
	}

}
void WALL_DAGNER_P(char T)
{
	character[T]--;
	Life--;
	character[T]++;
}
void WALL_DAGNER_M(char T)
{
	character[T]++;
	Life--;
	character[T]--;
}
void Move()
{
	char ch;
	ch = getch();
	system("cls");
	map[character[Y]][character[X]] = LastObjectIndex;
	switch (ch)
	{
	case LEFT:
		if (map[character[Y]][character[X] - 1] != WALL)
			character[X]--;
		else
			WALL_DAGNER_P(X);
		break;
	case RIGHT:
		if (map[character[Y]][character[X] + 1] != WALL)
			character[X]++;
		else
			WALL_DAGNER_M(X);
		break;
	case UP:
		if (map[character[Y] - 1][character[X]] != WALL)
			character[Y]--;
		else
			WALL_DAGNER_P(Y);
		break;
	case DOWN:
		if (map[character[Y] + 1][character[X]] != WALL)
			character[Y]++;
		else
			WALL_DAGNER_M(Y);
		break;
	}
	MoveCheck();
	LastObjectIndex = map[character[Y]][character[X]];
	map[character[Y]][character[X]] = CHARACTER;
}
void Add()
{
	int index = map[character[Y]][character[X]];

	printf("LIFE : %d\t", Life);
	printf("WEAPON : %d", Weapon_life);	
	if (Life < 1)
	{
		Lose = 1;
		printf("\n");
		printf("�������� �� �Ǿ����ϴ�.");
	}
}

void main()
{
	Init();

	while (1)
	{
		MapDraw();
		Add();
		Move();
		if (Lose == 1)
		{
			printf("\n");
			printf("�����ϴ�.");
			break;
		}
		else if (Win == 1)
		{
			printf("\n");
			printf("�̰���ϴ�.");
			break;
		}
	}
}