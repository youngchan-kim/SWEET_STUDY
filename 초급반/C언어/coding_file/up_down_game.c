#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

#define ANSWER 2
#define UP 1
#define DOWN 0

#define TRUE 1
#define FALSE 0 

void First_Print()
{
	printf("=========UpDown=========\n");
	printf("\t1.게임시작\n");
	printf("\t2.범위 설정\n");
	printf("\t3.종료\n");
	printf("입력 : ");
}
int UpDown_Check(int UpDown, int Qust)
{
	printf("UpDown %d 확인용\n", UpDown);
	int flag;
	if (Qust > UpDown)
		flag = DOWN;
	else if (Qust < UpDown)
		flag = UP;
	else if (Qust == UpDown)
		flag = ANSWER;
	return flag;
}
void GameOver()
{
	system("cls");
	printf("GameOver : Turn수 초과\n");
	system("pause");

}
int RanD(int Max, int Min)
{
	int UpDown;
	do
	{
		UpDown = rand() % (Max + 1);
	} while (UpDown < Min);

	return UpDown;
}

void Start_Game(int Max, int Min, int Turn)
{
	int Qust;
	int M = Turn - 1;
	int UpDown = RanD(Max, Min);
	for (int i = 0; i < Turn; i++)
	{
		system("cls");
		printf("범위 : %d ~ %d\n", Min, Max);
		printf("제한 Turn : %d\n", Turn);
		printf("======== %d턴 ========\n", i + 1);
		printf("입력 : ");
		scanf("%d", &Qust);
		int Check = UpDown_Check(UpDown, Qust);
		if (Check == DOWN)
		{
			printf("DOWN!!\n");
			system("pause");
			if (i == M)
			{
				GameOver();
				break;
			}
		}
		else if (Check == UP)
		{
			printf("UP!!\n");
			system("pause");
			if (i == M)
			{
				GameOver();
				break;
			}
		}
		else if (Check == ANSWER)
		{
			system("cls");
			printf("정답!!  턴수 : %d\n", i + 1);
			system("pause");
			break;
		}
	}
}
void Mode_Print()
{
	printf("=========UpDown=========\n");
	printf("\t1.최대, 최소범위 설정\n");
	printf("\t2.최대 Turn수 설정\n");
	printf("\t3.돌아가기\n");
	printf("입력 : ");
}
int MAX_CHANGE(int Max, int Min)
{
	int Max_Change_Num = 0;
	do
	{
		system("cls");
		printf("((현재 : %d))최댓 값 변경 : ", Max);
		scanf("%d", &Max_Change_Num);
		Max = Max_Change_Num;

	} while (Min < Max);

	return Max;
}

int MIN_CHANGE(int Max, int Min)
{
	int Min_Change_Num = 0;
	do
	{
		system("cls");
		printf("((현재 : %d))최소 값 변경 : ", Min);
		scanf("%d", &Min_Change_Num);
		Min = Min_Change_Num;

	} while (Min < Max);

	return Min;
}

int TURN_CHANGE(int Turn)
{
	int Turn_Change_Num = 0;
	do
	{
		system("cls");
		printf("((현재 : %d))턴 값 변경 : ", Turn);
		scanf("%d", &Turn_Change_Num);
		Turn = Turn_Change_Num;

	} while (0 < Turn_Change_Num);

	return Turn;
}

void Start()
{
	int Min = 1;
	int Max = 100;
	int Turn = 10;

	int StartNum;
	int Set_Num;
	int Back = FALSE;

	do
	{
		system("cls");
		Back = TRUE;
		First_Print();
		scanf("%d", &StartNum);
		switch (StartNum)
		{
		case 1:
			Start_Game(Max, Min, Turn);
			break;
		case 2:

			do
			{
				system("cls");
				Back = FALSE;
				Mode_Print();
				scanf("%d", &Set_Num);
				switch (Set_Num)
				{
				case 1:
					Max = MAX_CHANGE(Max, Min);
					Min = MIN_CHANGE(Max, Min);
					break;
				case 2:
					TURN_CHANGE(Turn);
					Turn = TURN_CHANGE(Turn);
					break;
				case 3:
					Back = TRUE;
					break;
				}
			} while (Back == FALSE);
			break;
		case 3:
			return;
		}
	} while (TRUE);
}

void main()
{
	srand((unsigned)time(NULL));
	Start();
}