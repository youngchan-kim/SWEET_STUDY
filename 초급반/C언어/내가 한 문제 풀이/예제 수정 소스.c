#include<stdio.h>

int Show(int Num1, int Num2)
{
	int Sum = 0;
	while (Num1 <= Num2)
	{
		Sum += Num1++;
		printf("%d\n", Sum);
	}
	return Sum;
}

void main()
{
	int Num1, Num2;
	printf("Num1 ���� �Է� : ");
	scanf("%d", &Num1);
	printf("Num2 ���� �Է� : ");
	scanf("%d", &Num2);
	printf("Sum : %d", Show(Num1, Num2));
}