#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>




void main()
{
	srand((unsigned)time(NULL));
	int RNum;
	while (1)
	{

	RNum = rand() % (10 / 2);
	printf("%d", RNum);
	system("pause");
	}
}
