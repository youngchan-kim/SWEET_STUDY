#include<stdio.h>

int MaxNum(int Num1, int Num2);
int Odd_or_Even(int Num1);
int Absolute_Value(int Num1);
int Again(int Num1);
int backNum(int Num1);

void main()
{
	int Num1, Num2;

	printf("1. �� ���� �Է��Ͻÿ� : ");
	scanf("%d%d", &Num1, &Num2);
	int Max = MaxNum(Num1, Num2);
	printf("%d�� %d�� ū ���� %d�Դϴ�.\n", Num1, Num2, Max);



	printf("2.���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &Num1);
	int flag = Odd_or_Even(Num1);
	if (flag == 1)
		printf("%d�� Ȧ���Դϴ�.\n", Num1);
	else
		printf("%d�� ¦���Դϴ�.\n", Num1);



	printf("3.���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &Num1);
	int Absolute = Absolute_Value(Num1);
	printf("%d�� ���밪 %d\n", Num1, Absolute);



	printf("4.���� �ϳ��� �Է��Ͻÿ� : ");
	scanf("%d", &Num1);

	int flag1 = Again(Num1);
	if (flag1 != 0)
		for (int i = 1; i <= Num1; i++)
		{
			if (i % 3 == 0)
			{
				printf("%d,", i);
			}
		}printf("\b\n");


		printf("5.���� �ϳ��� �Է��Ͻÿ� : ");
		scanf("%d", &Num1);
		printf("%d�� �Ųٷ� �� : ", Num1);
		int back = backNum(Num1);
		printf("%d", back);
}
int backNum(int Num1)
{
	int out, temp = 0;
	while (Num1 != 0)
	{
		out = Num1 % 10;
		Num1 /= 10;
		temp += out;
		temp *= 10;
	}
	temp /= 10;
	return temp;
}
int Again(int Num1)
{
	int flag = 0;
	if (Num1 % 3 == 0)
		flag = 1;
	return flag;
}

int Absolute_Value(int Num1)
{
	int Absolute;
	if (Num1 < 0)
		Absolute = Num1 * (-1);
	else
		Absolute = Num1;
	return Absolute;
}

int Odd_or_Even(int Num1)
{
	int flag = 0;
	if (Num1 % 2 != 0)
		flag = 1;
	else

		return flag;
}

int MaxNum(int Num1, int Num2)
{
	int Max;
	if (Num1 >= Num2)
		Max = Num1;
	else if (Num1 < Num2)
		Max = Num2;

	return Max;
}