#include<stdio.h>

void Swap(int *Num1, int *Num2)
{
	printf("������ Num1 = %d Num2 = %d\n", *Num1, *Num2);
	int tmp = *Num1;
	*Num1 = *Num2;
	*Num2 = tmp;
	printf("������ Num1 = %d Num2 = %d\n", *Num1, *Num2);
}

void main()
{
	int Num1 = 10, Num2 = 20;
	printf("�Լ� ȣ���� Num1 = %d Num2 = %d\n", Num1, Num2);
	Swap(&Num1, &Num2);
	printf("�Լ� ȣ���� Num1 = %d Num2 = %d\n", Num1, Num2);
}