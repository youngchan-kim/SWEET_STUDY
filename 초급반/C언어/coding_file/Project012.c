#include<stdio.h>
#include<stdlib.h>
#include<time.h>//�ð� �� ����ϴ� ��� ����

void main()
{
	int RNum;
	srand(time(NULL));
	while (1)
	{
		system("cls");
		for (int i = 1; i < 6; i++)
		{
			RNum = rand();
			printf("%d.%d\n", i, RNum);
		}
		system("pause");
	}
}