#include<stdio.h>
#define SIZE 3


int Sum(int Arr[SIZE])
{
	int SumNum = 0;

	for (int i = 0; i < SIZE; i++)
		SumNum += Arr[i];

	return SumNum;
}

float Avg(int Arr[SIZE])
{
	float AvgNum = 0;
	AvgNum = (float)Sum(Arr) / SIZE;
	return AvgNum;
}

int Big(int Arr[SIZE])
{
	int BigNum = Arr[0], Num;
	for (int i = 0; i < SIZE; i++)
	{
		Num = Arr[i];
		if (BigNum <= Num)
			BigNum = Num;
	}
	return BigNum;
}
//������ �������
void main()
{
	int Arr[SIZE];

	for (int i = 0, j = 1; i < SIZE, j <= SIZE; i++, j++)
	{
		printf("[%d]��° ���� �Է� : ", j);
		scanf("%d", &Arr[i]);
	}


	//printf("�� ū �� : %d  ���� = %d  ��� = %.3f", Big(Arr), Sum(Arr), Avg(Arr));
	printf("�� ū �� : %d ", Big(Arr));
}