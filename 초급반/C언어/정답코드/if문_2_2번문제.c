#include<stdio.h>

void main()
{
	int Time, Cash, Num, Temp;
	float Avg;
	printf("�¸� �̿� �ð��� �Է��Ͻÿ� :");
	scanf("%d", &Time);
	
	if (Time <= 30)
	{
		Cash = 3000;
	}
	else if (Time > 30 && Time % 10 == 0)
	{
		Temp = Time - 30;
		Num = Temp / 10;
		Cash = 3000 + Num * 500;
	}
	else 
	{
		Temp = Time - 20;
		Num = Temp / 10;
		Cash = 3000 + Num * 500;
	}
	printf("%d�� ž�� ��� : %d", Time, Cash);
}