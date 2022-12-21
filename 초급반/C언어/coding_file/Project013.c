#include<stdio.h>
#include<stdlib.h>
#include<time.h>//시간 값을 사용하는 헤더파일
#define LOTTO_NUM 6
void main()
{
	int RNum;
	int Lotto[LOTTO_NUM] = { 0 };
	srand((unsigned)time(NULL));
	while (1)
	{
		system("cls");
		for (int i = 0; i < LOTTO_NUM; i++)
		{
			RNum = (rand() % 45) + 1;
			Lotto[i] = RNum;
		}
		for (int i = 0; i < LOTTO_NUM; i++)
			printf("%d,", Lotto[i]);
		printf("\b");
		system("pause");
	}
}