#include<stdio.h>
#include<stdlib.h>
#include<time.h>//시간 값 사용하는 헤더파일
#define LOTTO_NUM 6
#define TRUE 1
#define FALSE 0

void Lotto_Run()
{
	int RNum;
	int Lotto[LOTTO_NUM] = { 0 };
	system("cls");
	int Stop = FALSE;

	do
	{
		Stop = TRUE;
		for (int i = 0; i < LOTTO_NUM; i++)
		{
			Lotto[i] = (rand() % 45) + 1;
			for (int j = 0; j < i; j++)
			{
				if (Lotto[j] == Lotto[i])
				{
					Stop = FALSE;
					break;
				}
			}
		}
	} while (Stop == FALSE);

	for (int i = 0; i < LOTTO_NUM; i++)
	{
		printf("%d.", i + 1);
		printf("%d\n", Lotto[i]);
	}
	system("pause");
}
void main()
{

	srand((unsigned)time(NULL));
	
	while (TRUE)
	{
		Lotto_Run();
	}
}
