#include<stdio.h>

void Sum(int Num1, int Num2)
{
	printf("������ Num1 = %d Num2 = %d\n", Num1, Num2);
	Num1 += 5;
	Num2 += 5;
	printf("������ Num1 = %d Num2 = %d\n", Num1, Num2);
}

void main()
{
	int Num1 = 10, Num2 = 20;
	printf("�Լ� ȣ���� Num1 = %d Num2 = %d\n", Num1, Num2);
	Sum(Num1, Num2);
	printf("�Լ� ȣ���� Num1 = %d Num2 = %d\n", Num1, Num2);
}