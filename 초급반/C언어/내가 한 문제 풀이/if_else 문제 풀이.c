#include<stdio.h>

void main()
{
	int Num1, Num2, Num3, Max, Min;
	printf("���� �� ���� �Է��Ͻÿ� : ");
	scanf("%d%d%d", &Num1, &Num2, &Num3);
	if (Num1 > Num2)
	{
		Max = Num1;
		if (Num2 > Num3)
		{
			Min = Num3;
		}
		else 
		{
			if (Max > Num3)
			{
				Min = Num2;
			}
		}
	}
	if (Num2 > Num1)
	{
		Max = Num2;
		if (Num1 > Num3)
		{
			Min = Num3;
		}
		else
		{
			if (Max > Num3)
			{
				Min = Num1;
			}
		}
	}
	if (Num3 > Num1)
	{
		Max = Num3;
		if (Num1 > Num2)
		{
			Min = Num2;
		}
		else
		{
			if (Max > Num2)
			{
				Min = Num1;
			}
		}
	}



	printf("\n Max = %d Min = %d", Max, Min);

}