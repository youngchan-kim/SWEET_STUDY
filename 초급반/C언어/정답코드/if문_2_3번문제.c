#include<stdio.h>

void main()
{
	int Num, Cash, Sum;

	printf("������ ���ö� ������ �Է��Ͻÿ� : ");
	scanf("%d", &Num);
	
	if (Num <= 10)
	{
		Cash = Num * 2500;
	}
	else
	{
		Num = Num - 10;
		Cash = Num * 2400;
		Cash = Cash + 25000;
	}
	printf("���ö� %d�� ���� : %d��", Num, Cash);
	
}