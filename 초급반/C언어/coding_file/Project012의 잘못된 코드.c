#include<stdio.h>
#include<stdlib.h>
#include<time.h>//시간 값 사용하는 헤더 파일

void main()
{
	int RNum;

	while (1)
	{
		system("cls");
		srand((unsigned)time(NULL));
		for (int i = 1; i < 6; i++)
		{
			RNum = rand();
			printf("%d.%d\n", i, RNum);
		}
		system("pause");
	}
}