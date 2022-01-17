#include<stdio.h>
#include<stdlib.h>

void main()
{
	int RNum;
	while (1)
	{
		system("cls");
		for (int i = 1; i < 6; i++)
		{
			RNum = rand();
			printf("%d. %d\n", i, RNum);
		}
		system("pause");
	}
}